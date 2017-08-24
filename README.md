# morpheus


[![Build Status](https://travis-ci.org/Alexander-Ignatyev/morpheus.svg?branch=master)](https://travis-ci.org/Alexander-Ignatyev/morpheus)

Low-level machine learning auxiliary functions.

## Build and run tests

```bash
make test
```

## Build and run benchmarks

```bash
make bench
```

### Build against OpenBLAS

#### macOS

* Homebrew:

```bash
brew install homebrew/science/openblas
OPENBLAS=`brew --prefix openblas` make
```

#### Linux

* Debian/Ubuntu:

```bash
apt-get install libopenblas-dev
OPENBLAS=/usr make
```

## Generate documentation

```bash
make docs
```

*requires [doxygen](http://www.doxygen.org/)*


## Build hmatrix-morpheus

```
stack build
```

### Build and run unit tests

```
stack test
```