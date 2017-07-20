# morpheus


[![Build Status](https://travis-ci.org/Alexander-Ignatyev/morpheus.svg?branch=master)](https://travis-ci.org/Alexander-Ignatyev/morpheus)

Low-level machine learning auxiliary functions.

## Build and run tests

```bash
make && ./obj/testapp
```

### Build against OpenBLAS

#### macOS

* Homebrew:

```
brew install homebrew/science/openblas
OPENBLAS=`brew --prefix openblas` make
```

#### Linux

* Debian/Ubuntu:

```
apt-get install libopenblas-dev
OPENBLAS=/usr make
```
