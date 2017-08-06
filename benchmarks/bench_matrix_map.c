#include "bench_matrix_map.h"
#include "benchmark.h"

#include "../src/matrix_map.h"

#include <stdio.h>

void bench_column_max(int n, const char *message,
                      morpheus_layout_e layout,
                      int size, double *x) {
  double *y = calloc(size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    y[0] = i;
    morpheus_column_max(layout, size, size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_column_min(int n, const char *message,
                      morpheus_layout_e layout,
                      int size, double *x) {
  double *y = calloc(size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    y[0] = i;
    morpheus_column_min(layout, size, size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_column_pred(int n, const char *message,
                       double (*pred)(double, double),
                       morpheus_layout_e layout,
                       int size, double *x) {
  double *y = calloc(size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    y[0] = i;
    morpheus_column_predicate(pred, layout, size, size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}

void bench_row_pred(int n, const char *message,
                    double (*pred)(double, double),
                    morpheus_layout_e layout,
                    int size, double *x) {
  double *y = calloc(size, sizeof(double));
  double start = get_time();
  for (int i = 0; i < n; ++i) {
    y[0] = i;
    morpheus_row_predicate(pred, layout, size, size, x, y);
  }
  double finish = get_time();
  free(y);
  double ms = (finish-start)/n;
  printf("Benchmark %s: %f ms\n", message, ms);
}
