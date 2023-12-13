# 2.3 (unreleased master branch)

### New Features

* [Issue #62](https://gitlab.com/grobian/html2text/-/issues/62)
  use ANSI-escapes instead of backspace sequences, this includes some
  colour handling

### Bugfixes

* [Issue #59](https://github.com/grobian/html2text/issues/59)
  Fix build for C++ compilers that do not default to C++11 or more
  recent.
* [Issue #61](https://https://gitlab.com/grobian/html2text/-/issues/61)
  Fix handling of malformed attributes in tags


# 2.2.3 (31-07-2023)

### New Features

### Bugfixes

* [Issue #57](https://github.com/grobian/html2text/issues/57)
  de-escape link hrefs so they can be copy-pasted in a browser
* [Issue #56](https://github.com/grobian/html2text/issues/56)
  drop usage of sprintf from the codebase


# 2.2.2 (30-07-2023)

### New Features

### Bugfixes

* Fix building on platforms requiring libiconv


# 2.2.1 (30-07-2023)

### New Features

### Bugfixes

* Fix release script to produce working tarball


# 2.2.0 

### New Features

* [Issue #52](https://github.com/grobian/html2text/issues/52)
  Support -utf8 flag as alias for compatibility with <2.0.0 releases
* Build-system now uses autotools-based configure and Makefiles
* Suppress xml namespace tags in output (<?xml ...)
* [Issue #12](https://github.com/grobian/html2text/issues/12)
  [Issue #26](https://github.com/grobian/html2text/issues/26)
  Whitespace normalisation now works over tags, removing extra
  and adding missing where appropriate
* Ignore &zwnj; to improve monospace rendering

### Bugfixes

* [PR #48](https://github.com/grobian/html2text/pull/48)
  Fix typos in manpage
