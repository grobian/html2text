
 /***************************************************************************/

/*
 * Portions Copyright (c) 1999 GMRS Software GmbH
 * Carl-von-Linde-Str. 38, D-85716 Unterschleissheim, http://www.gmrs.de
 * All rights reserved.
 *
 * Author: Arno Unkrig <arno@unkrig.de>
 */
 
/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License in the file COPYING for more details.
 */

 /***************************************************************************/

/*
 * Changes to version 1.2.2 were made by Martin Bayer <mbayer@zedat.fu-berlin.de>
 * Dates and reasons of modifications:
 * Thu Oct  4 21:49:09 CEST 2001: ported to g++ 3.0
 * Sun Apr  7 11:59:03 CEST 2002: Handle URLs with missing node
 * Mon Jul 22 13:53:02 CEST 2002: Made finaly reading from STDIN work.
 */
  
 /***************************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>
#ifdef SYS_POLL_MISSING /* { */
struct pollfd {
  int fd;           /* file descriptor */
  short events;     /* requested events */
  short revents;    /* returned events */
};
extern "C" int poll(struct pollfd *ufds, unsigned int nfds, int timeout);
#define POLLIN      0x0001    /* There is data to read */
#define POLLPRI     0x0002    /* There is urgent data to read */
#define POLLOUT     0x0004    /* Writing now will not block */
#define POLLERR     0x0008    /* Error condition */
#define POLLHUP     0x0010    /* Hung up */
#define POLLNVAL    0x0020    /* Invalid request: fd not open */
#else /* } { */
#include <sys/poll.h>
#endif /* } */
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <signal.h>

#include "urlistream.h"

using std::ios;

/* ------------------------------------------------------------------------- */

/*
 * Compile with
 *
 *     CC -DTESTING urlistream.C -o urlcat
 */

/* ------------------------------------------------------------------------- */

void
urlistream::open(
  const char *url,
  int        timeout /* = default_timeout */  // Milliseconds
)
{
  if (is_open()) close();

  /*
   * "http:" <address> URL?
   */
  if (!memcmp(url, "http:", 5)) {
    http_open(url + 5, timeout);
    return;
  }

  /*
   * "file:" <file-name> URL?
   */
  if (!memcmp(url, "file:", 5)) {
    file_open(url + 5);
    return;
  }

  /*
   * is the URL a bare file name?
   */
  if (strchr(url, ':') == NULL) {
    file_open(url);
    return;
  }

  open_error_ = "Unknown protocol (only \"file:\" and \"http:\" allowed)";
}

void
urlistream::open(
  const string &url,
  int          timeout /* = default_timeout */  // Milliseconds
)
{
  open(url.c_str(), timeout);
}

/* ------------------------------------------------------------------------- */

void
urlistream::http_open(
  const char *address,    // The URL portion after "http:"
  int        timeout      // Milliseconds
)
{

  /*
   * Break up the HTTP address:
   *
   *   "//" <host> [ ":" <port> ] <node>
   *
   * A missing node is interpreted as node "/" - Arno
   */
  char host_name[100];
  char port_name[100];
  char node_name[1000];
  {
    const char *p = address;
    char       *q;

    if (*p++ != '/' || *p++ != '/') {
      open_error_ = "HTTP address does not begin with \"//\"";
      return;
    }

    for (q = host_name; *p && *p != ':' && *p != '/'; ++p) {
      if (q < host_name + sizeof(host_name) - 1) *q++ = *p;
    }
    *q = '\0';

    if (*p == ':') {
      ++p;
      for (q = port_name; *p && *p != '/'; ++p) {
	if (q < port_name + sizeof(port_name) - 1) *q++ = *p;
      }
      *q = '\0';
    } else {
      strcpy(port_name, "80");
    }

    for (q = node_name; *p && *p != '#'; ++p) {
      if (q < node_name + sizeof(node_name) - 1) *q++ = *p;
    }
    *q = '\0';
    if (!node_name[0]) {
      strcpy(node_name, "/");
    }
  }

  struct sockaddr_in soc_address;
  soc_address.sin_family = AF_INET;

  /*
   * Parse the host name.
   */
  {
    const char *p;
    int dot_count = 0;
    for (p = host_name; *p; ++p) {
      if (*p == '.') { ++dot_count; } else if (!isdigit(*p)) break;
    }
    if (*p == '\0' && dot_count == 3) {
      soc_address.sin_addr.s_addr = inet_addr(host_name);
    } else {
      struct hostent *h = gethostbyname(host_name);
      if (
        h == 0 ||
        h->h_addrtype != AF_INET ||
        h->h_length != sizeof(struct in_addr)
      ) {
	open_error_ = "Could not resolve host name";
	return;
      }
      soc_address.sin_addr = *(struct in_addr *) h->h_addr;
    }
  }

  /*
   * Parse the port name.
   */
  if (isdigit(port_name[0])) {
    soc_address.sin_port = htons(atoi(port_name));
  } else {
    struct servent *s = getservbyname(port_name, 0);
    soc_address.sin_port = htons(s ? s->s_port : 80);
  }

  /*
   * Strip the "#anchor" suffix from the node name.
   */
  { char *p = strchr(node_name, '#'); if (p) *p = '\0'; }

  /*
   * On-the-fly definition of "FileHandle" which closes a UNIX file descriptor
   * on destruction.
   */
  class FileHandle {
  public:
    FileHandle() : fd(-1) {}
    ~FileHandle() { if (fd != -1) ::close(fd); }
    operator int() { return fd; }
    int operator=(int x) { return (fd = x); }
  private:
    int fd;
  } fd;

  fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (fd == -1) {
    open_error_ = strerror(errno);
    return;
  }

  /*
   * Make the socket non-blocking, so the "connect()" can be canceled. This
   * means that when we issue the "connect()" we should NOT have to wait for
   * the accept on the other end.
   */
  if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1) {
    open_error_ = strerror(errno);
    return;
  }

  /*
   * Issue the "connect()". Since the server can't do an instantaneous
   * "accept()" and we are non-blocking, this will almost certainly return
   * a negative status.
   */
  if (connect(
    fd,
    (struct sockaddr *) &soc_address, sizeof(soc_address)
  ) == -1) {
    if (errno != EINPROGRESS && errno != EAGAIN) {
      open_error_ = strerror(errno);
      return;
    }

    for (;;) {
      struct pollfd p;
      int           res;

      p.fd     = fd;
      p.events = POLLOUT;
      res = poll(&p, 1, timeout);

      /*
       * Interrupted "poll()"?
       */
      if (res == -1 && errno == EINTR) continue;

      /*
       * Check for errors.
       */
      if (res == -1 && errno != EALREADY) {
        open_error_ = strerror(errno);
	return;
      }

      /*
       * Check for timeout.
       */
      if (res == 0) {
	open_error_ = "\"connect()\" timed out";
	return;
      }

      /*
       * Extra check here for connection success, if we try to
       * connect again, and get EISCONN, it means we have a
       * successful connection.
       *
       * Notice: On SINIX 5.43 B2000, the "poll()" returns "1" when the
       * timeout occurs (!?). When we call "poll()", we encounter a SIGPIPE
       * (!?). If we ignore it, "poll()" returns EINVAL (22) (!?).
       */
      void (*sigpipe_handler)(int) = signal(SIGPIPE, SIG_IGN); /* { */
      res = connect(fd, (struct sockaddr *) &soc_address, sizeof(soc_address));
      (void) signal(SIGPIPE, sigpipe_handler); /* } */

      if (res == -1 && errno == EISCONN) break;
      if (res == -1 && errno != EALREADY) {
        open_error_ = strerror(errno);
	return;
      }
    }
  }

  /*
   * Make the socket blocking again on good "connect()".
   */
  if (fcntl(fd, F_SETFL, 0) == -1) {
    open_error_ = strerror(errno);
    return;
  }

  /*
   * Issue the HTTP request.
   *
   * Notice: "GET xyz" means "return the document without a header".
   */
  char command[4 + (sizeof(node_name) - 1) + 4 + 1];
  sprintf(command, "GET %s\r\n\r\n", node_name);
  ssize_t command_length = strlen(command);

  if (::write(fd, command, command_length) != command_length) {
    open_error_ = "Error sending HTTP GET request";
    return;
  }

  /*
   * Attach the file descriptor to the ifstream.
   */
  fd_ = fd;

  fd = -1;    // ...so that it is not implicitly "::close()"'d.
}

/* ------------------------------------------------------------------------- */

void
urlistream::file_open(const char *file_name)
{
  fd_ = !strcmp(file_name, "-") ? ::dup(0) : ::open(file_name, O_RDONLY);
  open_error_ = strerror(errno);
}

/* ------------------------------------------------------------------------- */

const char *
urlistream::open_error() const
{
  return open_error_ ? open_error_ : "No error";
}

/* ------------------------------------------------------------------------- */

int
urlistream::get()
{
  char ch;
  int ret = ::read(fd_, &ch, 1);
  return (ret > 0 ? ch : -1);
}

#ifdef TESTING /* { */

int
main(int argc, char **argv)
{
  if (argc < 2) {
    cerr << "Usage:  urlcat <url> [ ... ]" << endl;
    exit(1);
  }

  for (int i = 1; i < argc; ++i) {
    urlistream uis(argv[i]);
    if (!uis.is_open()) {
      cerr << "Opening \"" << argv[i] << "\": " << uis.open_error() << endl;
      exit(1);
    }

    for (;;) {
      int c = uis.get();
      if (c == EOF) break;
      cout << (char) c;
    }
  }

  return 0;
}

#endif /* } */

/* ------------------------------------------------------------------------- */
