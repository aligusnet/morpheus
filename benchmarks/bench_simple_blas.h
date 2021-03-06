#ifndef MORPHEUS_BENCHMARKS_BENCH_SIMPLE_BLAS_H
#define MORPHEUS_BENCHMARKS_BENCH_SIMPLE_BLAS_H

void bench_morpheus_identity(int n, const char *message, int size);

void bench_manual_identity(int n, const char *message, int size);

void bench_morpheus_dcopy(int n, const char *message, int size, double *x);

void bench_manual_dcopy(int n, const char *message, int size, double *x);

#endif  /* MORPHEUS_BENCHMARKS_BENCH_SIMPLE_BLAS_H */
