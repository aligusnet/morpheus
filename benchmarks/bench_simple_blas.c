#include "bench_simple_blas.h"
#include "benchmark.h"

#include "../src/simple_blas.h"

#include <stdio.h>
#include <stdlib.h>

void bench_morpheus_identity(int n, const char *message, int size) {
  double *x = calloc(size*size, sizeof(double));

  double start = get_time();
  for (int i = 0; i < n; ++i) {
    x[0] = i;
    morpheus_identity(size, x);
  }
  double finish = get_time();
  free(x);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}


void manual_identity(int n, double *x) {
  int m = n*n;
  for (int i = 0; i < n; ++i) {
    double *row = x + i*n;
    for (int j = 0; j < n; ++j) {
      row[j] = i != j ? 0 : 1;
    }
  }
}

void bench_manual_identity(int n, const char *message, int size) {
  double *x = calloc(size*size, sizeof(double));

  double start = get_time();
  for (int i = 0; i < n; ++i) {
    x[0] = i;
    manual_identity(size, x);
  }
  double finish = get_time();
  free(x);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}
