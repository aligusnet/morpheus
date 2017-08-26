# morpheus


[![Build Status](https://travis-ci.org/Alexander-Ignatyev/morpheus.svg?branch=master)](https://travis-ci.org/Alexander-Ignatyev/morpheus)

The library contains a bunch of cache line aware numerical algorithms suitable for using as a low-level primitives to build machine learning applications.

Naive implementations, which do not take into account cache lines, would suffer order of magnitude performance degradation if tried to traverse a row major matrix in column order.

The library functions take into account CPU cache and work well for both row major and column major matrices, as you can see from the benchmark below which measure time for finding indices of max elements for every column and every row:

| Benchmark | Time
| --- | ---
| column_max_index - row_major | 0.892378 ms
| column_max_index - col_major | 0.845999 ms
| row_max_index - row_major | 0.879663 ms
| row_max_index - col_major | 0.870022 ms

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
