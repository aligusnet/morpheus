#ifndef MORPHEUS_BENCHMARKS_BENCH_ACTIVATION_H
#define MORPHEUS_BENCHMARKS_BENCH_ACTIVATION_H

void bench_sigmoid(int n, const char *message, int size, double *x);

void bench_sigmoid_gradient(int n, const char *message, int size, double *x);

#endif  /* MORPHEUS_BENCHMARKS_BENCH_ACTIVATION_H */
