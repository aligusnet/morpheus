#include "bench_activation.h"
#include "benchmark.h"

#include "../src/activation.h"

#include <stdio.h>
#include <stdlib.h>

void bench_sigmoid(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_sigmoid(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_sigmoid_gradient(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_sigmoid_gradient(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_relu(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_relu(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_relu_gradient(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_relu_gradient(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_tanh(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_tanh(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_tanh_gradient(int n, const char *message, int size, double *x) {
  double *y = calloc(size*size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    morpheus_tanh_gradient(size*size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}
