# hmatrix-morpheus

Purely functional interface to morpheus based on hmatrix. Morpheus library contains a bunch of cache line aware numerical algorithms suitable for using as a low-level primitives to build machine learning applications.

Naive implementations, which do not take into account cache lines, would suffer order of magnitude performance degradation if tried to traverse a row major matrix in column order.

The library functions take into account CPU cache and work well for both row major and column major matrices, as you can see from the benchmark below which measure time for finding indices of max elements for every column and every row in comparison with naive approach:

| Benchmark | morheus | Naive
| --- | --- | ---
| max index in columns - row major | 0.9077 ms | 12.93 ms
| max index in columns - column major | 0.8778 ms | 1.490 ms
| max index in rows - row major | 0.8622 ms | 1.504 ms
| max index in rows - column major | 0.8913 ms | 12.80 ms
