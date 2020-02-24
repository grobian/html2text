
/* ------------------------------------------------------------------------- */

/*
 * Copyright (c) 1999
 *      GMRS Software GmbH, Innsbrucker Ring 159, 81669 Munich, Germany.
 *      http://www.gmrs.de
 *      All rights reserved.
 *      Author: Arno Unkrig (arno.unkrig@gmrs.de)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by GMRS Software GmbH.
 * 4. The name of GMRS Software GmbH may not be used to endorse or promote
 *    products derived from this software without specific prior written
 *    permission.
 *
 * THIS SOFTWARE IS PROVIDED BY GMRS SOFTWARE GMBH ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GMRS SOFTWARE GMBH BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

/* ------------------------------------------------------------------------- */

#ident "$Id: string.C,v 1.10 1999/10/27 12:15:13 arno Exp $"

/*
 * Uncomment "cerr" for debugging, 
 */
//#define DBG(x) x

#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <string>

#ifndef DBG
#define DBG(x)
#endif

/* ------------------------------------------------------------------------- */

/*static*/ const string::size_type string::npos = (string::size_type) -1;

/*static*/ char string::null = 0;

/* ------------------------------------------------------------------------- */

string::string(const string &x) :
  p(*x.p ? strdup(x.p) : &null)
{
  DBG(cerr << "string::string(string &\"" << x.p << "\")" << endl);
}

/* ------------------------------------------------------------------------- */

string::string(const char *x, size_type n)
{
  if (!n) { p = &null; return; }
  p = (char *) malloc(n + 1);
  memcpy(p, x, n);
  p[n] = '\0';
}

/* ------------------------------------------------------------------------- */

string::string(const char *x) :
  p(*x ? strdup(x) : &null)
{
  DBG(cerr << "string::string(\"" << x << "\")" << endl);
}

/* ------------------------------------------------------------------------- */

string::string(size_type n, char c)
{
  if (n == 0) {
    p = &null;
  } else {
    p = (char *) malloc(n + 1);
    memset(p, c, n);
    p[n] = '\0';
  }
}

/* ------------------------------------------------------------------------- */

// Internal use only: Create an uninitialized string.
string::string(size_type x) :
  p(x ? (char *) malloc(x + 1) : &null)
{
}

/* ------------------------------------------------------------------------- */

string::~string() {
  DBG(cerr << "string::~string(\"" << p << "\")" << endl);
  if (p != &null) free(p);
  p = (char *) 0xa5a5a5a5;   // For a fast core dump.
}

/* ------------------------------------------------------------------------- */

const string &
string::operator=(const string &x)
{
  if (p != &null) free(p);
  p = *x.p ? strdup(x.p) : &null;
  return *this;
}

/* ------------------------------------------------------------------------- */

const string &
string::operator=(const char *x)
{
  if (p != &null) free(p);
  p = *x ? strdup(x) : &null;
  return *this;
}

/* ------------------------------------------------------------------------- */

const string &
string::operator=(char c)
{
  if (p != &null) free(p);
  p = (char *) malloc(2);
  p[0] = c;
  p[1] = '\0';
  return *this;
}

/* ------------------------------------------------------------------------- */

string::iterator string::end()
{ return strchr(p, '\0'); }

string::const_iterator string::end() const
{ return strchr(p, '\0'); }

string::reverse_iterator string::rbegin()
{ return strchr(p, '\0'); }

string::const_reverse_iterator string::rbegin() const
{ return strchr(p, '\0'); }

/* ------------------------------------------------------------------------- */

const string &
string::operator+=(char c)
{
  DBG(cerr << "string::operator+=(\"" << p << "\", '" << c << "')" << endl);

  if (p == &null) {
    p = (char *) malloc(2);
    p[0] = c;
    p[1] = '\0';
  } else {
    size_t len = strlen(p);
    p = (char *) realloc(p, len + 2);
    p[len] = c;
    p[len + 1] = '\0';
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

const string &
string::operator+=(const char *x)
{
  if (p == &null) {
    p = strdup(x);
  } else {
    size_t len = strlen(p);
    p = (char *) realloc(p, len + strlen(x) + 1);
    strcpy(p + len, x);
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

void
string::resize(size_type n, char c /*= ends*/ )
{
  if (n == 0) {
    if (p != &null) free(p);
    p = &null;
    return;
  }

  if (p == &null) {
    p = (char *) malloc(n + 1);
    memset(p, c, n);
  } else {
    size_type len = strlen(p);

    if (n > len) {
      p = (char *) realloc(p, n + 1);
      memset(p + len, c, n - len);
    }
  }
  p[n] = '\0';
}

/* ------------------------------------------------------------------------- */

string &
string::append(size_type n, char c)
{
  if (p == &null) {
    p = (char *) malloc(n + 1);
    memset(p, c, n);
    p[n] = '\0';
  } else {
    size_type len = strlen(p);
    p = (char *) realloc(p, len + n + 1);
    memset(p + len, c, n);
    p[len + n] = '\0';
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::assign(const string &s, size_type pos, size_type n)
{
  if (p != &null) free(p);
  if (n == 0) { p = &null; return *this; }

  size_type sl = s.size();
  if (pos >= sl) { p = &null; return *this; }
  if (n == npos || n > sl - pos) n = sl - pos;
  p = (char *) malloc(n + 1);
  memcpy(p, s.p + pos, n);
  p[n] = '\0';
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::insert(size_type pos, size_type n, char c)
{
  if (n) {
    if (p == &null) {
      // ASSERT that "pos == 0".
      p = (char *) malloc(n + 1);
      memset(p, c, n);
      p[n] = '\0';
    } else {
      size_type len = strlen(p);
      // ASSERT that "pos <= len".
      p = (char *) realloc(p, len + n + 1);
      memmove(p + pos + n, p + pos, len - pos + 1);
      memset(p + pos, c, n);
    }
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::erase(size_type pos /*= 0*/, size_type n /*= npos*/ )
{
  DBG(cerr << "\"" << p << "\"::erase(" << pos << ", " << n << ") -> \"");
  size_type len = strlen(p);
  // ASSERT on that "pos <= len".
  if (n == npos || pos + n >= len) {
    p[pos] = '\0';
  } else {
    strcpy(p + pos, p + pos + n);
  }

  DBG(cerr << p << "\"" << endl);
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::replace(
  size_type    pos1,
  size_type    n1,
  const string &s,
  size_type    pos2,
  size_type    n2
)
{
  size_type l1 = size();
  size_type l2 = s.size();

  if (pos1 > l1 || pos2 > l2) return *this;
  if (n1 == npos || pos1 + n1 > l1) n1 = l1 - pos1;
  if (n2 == npos || pos2 + n2 > l2) n2 = l2 - pos2;

  if (pos1 + n1 == l1) {
    size_type j = pos1 + n2 + 1;
    p = (char *) (p == &null ? malloc(j) : realloc(p, j));
    memcpy(p + pos1, s.p + pos2, n2);
    p[pos1 + n2] = '\0';
  } else {
    size_type j = l1 - n1 + n2 + 1;
    p = (char *) (p == &null ? malloc(j) : realloc(p, j));
    memmove(p + pos1 + n2, p + pos1 + n1, l1 - pos1 - n1 + 1);
    memcpy(p + pos1, s.p + pos2, n2);
  }

  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::replace(size_type pos, size_type n1, const char *x, size_type n2)
{
  if (p == &null) {
    // ASSERT that "pos == 0".
    if (n2) { p = (char *) malloc(n2 + 1); memcpy(p, x, n2); p[n2] = '\0'; }
  } else {
    size_type len1 = strlen(p);
    if (n1 == npos || pos + n1 >= len1) {
      p = (char *) realloc(p, pos + n2 + 1);
      memcpy(p + pos, x, n2);
      p[pos + n2] = '\0';
    } else {
      if (n2 > n1) {
        p = (char *) realloc(p, len1 - n1 + n2 + 1);
        memmove(p + pos + n2, p + pos + n1, len1 - pos - n1 + 1);
      } else
      if (n2 < n1) {
        memmove(p + pos + n2, p + pos + n1, len1 - pos - n1 + 1);
        p = (char *) realloc(p, len1 - n1 + n2 + 1);
      }
      memcpy(p + pos, x, n2);
    }
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::replace(size_type pos, size_type n, const char *x)
{
  if (p == &null) {
    // ASSERT that "pos == 0".
    if (*x) p = strdup(x);
  } else {
    size_type len1 = strlen(p);
    size_type len2 = strlen(x);
    if (n == npos || pos + n >= len1) {
      p = (char *) realloc(p, pos + len2 + 1);
      strcpy(p + pos, x);
    } else {
      if (len2 > n) {
	p = (char *) realloc(p, len1 - n + len2 + 1);
        memmove(p + pos + len2, p + pos + n, len1 - pos - n + 1);
      } else
      if (len2 < n) {
        memmove(p + pos + len2, p + pos + n, len1 - pos - n + 1);
	p = (char *) realloc(p, len1 - n + len2 + 1);
      }
      memcpy(p + pos, x, len2);
    }
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

string &
string::replace(size_type pos, size_type n1, size_type n2, char c)
{
  if (p == &null) {
    // ASSERT that "pos == 0".
    if (n2 > 0) {
      p = (char *) malloc(n2 + 1);
      memset(p, c, n2);
      p[n2] = '\0';
    }
  } else {
    size_type len1 = strlen(p);
    if (n1 == npos || pos + n1 >= len1) {
      p = (char *) realloc(p, pos + n2 + 1);
      memset(p + pos, c, n2);
      p[pos + n2] = '\0';
    } else {
      if (n2 > n1) {
	p = (char *) realloc(p, len1 - n1 + n2 + 1);
        memmove(p + pos + n2, p + pos + n1, len1 - pos - n1 + 1);
      } else
      if (n2 < n1) {
        memmove(p + pos + n2, p + pos + n1, len1 - pos - n1 + 1);
	p = (char *) realloc(p, len1 - n1 + n2 + 1);
      }
      memset(p + pos, c, n2);
    }
  }
  return *this;
}

/* ------------------------------------------------------------------------- */

string::size_type
string::length() const { return strlen(p); }

string::size_type
string::size() const { return strlen(p); }

/* ------------------------------------------------------------------------- */

ostream &
operator<<(ostream &os, const string &s)
{ return os << s.p; }

/* ------------------------------------------------------------------------- */

/*
 * Note: "istream::getline(p, n, delim)" reads the delimiter, but does not
 * put it into "p", so we must compare "gcount()" against "strlen(p)".
 *
 * "getline(is, str, delim)" reads the delimiter, but it is not entered into
 * "str".
 */
/*friend of string*/ istream &
getline(istream &is, string &s_return, char delim /*= '\n'*/ )
{
  char buffer[1024];
  if (is.getline(buffer, sizeof(buffer), delim)) {
    s_return = buffer;
    while (is.gcount() == strlen(buffer)) {   // Delimiter not read yet
      if (!is.getline(buffer, sizeof(buffer), delim)) break;
      s_return += buffer;
    }
  }
  return is;
}

/* ------------------------------------------------------------------------- */

bool operator==(const string &x, const string &y)
{ return strcmp(x.c_str(), y.c_str()) == 0; }

bool operator==(const char *x, const string &y)
{ return strcmp(x, y.c_str()) == 0; }

bool operator==(const string &x, const char *y)
{ return strcmp(x.c_str(), y) == 0; }

/* ------------------------------------------------------------------------- */

bool operator<(const string &x, const string &y)
{ return strcmp(x.c_str(), y.c_str()) < 0; }

bool operator<(const char *x, const string &y)
{ return strcmp(x, y.c_str()) < 0; }

bool operator<(const string &x, const char *y)
{ return strcmp(x.c_str(), y) < 0; }

/* ------------------------------------------------------------------------- */

bool operator!=(const string &x, const string &y)
{ return strcmp(x.c_str(), y.c_str()) != 0; }

bool operator!=(const char *x, const string &y)
{ return strcmp(x, y.c_str()) != 0; }

bool operator!=(const string &x, const char *y)
{ return strcmp(x.c_str(), y) != 0; }

/* ------------------------------------------------------------------------- */

string
operator+(const string &s1, const string &s2)
{
  string::size_type l1 = strlen(s1.p), l2 = strlen(s2.p);
  string res(l1 + l2);
  memcpy(res.p, s1.p, l1);
  memcpy(res.p + l1, s2.p, l2);
  res.p[l1 + l2] = '\0';
  return res;
}

string
operator+(const char *p1, const string &s2)
{
  string::size_type l1 = strlen(p1), l2 = strlen(s2.p);
  string res(l1 + l2);
  memcpy(res.p, p1, l1);
  memcpy(res.p + l1, s2.p, l2);
  res.p[l1 + l2] = '\0';
  return res;
}

string
operator+(char c, const string &s)
{
  string::size_type l = strlen(s.p);
  string res(1 + l);
  res.p[0] = c;
  memcpy(res.p + 1, s.p, l);
  res.p[1 + l] = '\0';
  return res;
}

string
operator+(const string &s1, const char *p2)
{
  string::size_type l1 = strlen(s1.p), l2 = strlen(p2);
  string res(l1 + l2);
  memcpy(res.p, s1.p, l1);
  memcpy(res.p + l1, p2, l2);
  res.p[l1 + l2] = '\0';
  return res;
}

string
operator+(const string &s, char c)
{
  string::size_type l = strlen(s.p);
  string res(l + 1);
  memcpy(res.p, s.p, l);
  res.p[l] = c;
  res.p[l + 1] = '\0';
  return res;
}

/* ------------------------------------------------------------------------- */

