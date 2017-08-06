#ifndef MORPHEUS_BENCHMARKS_BENCH_MATRIX_MAP_H
#define MORPHEUS_BENCHMARKS_BENCH_MATRIX_MAP_H

#include "../src/simple_blas.h"

void bench_column_max(int n, const char *message,
                      morpheus_layout_e layout,
                      int size, double *x);

void bench_column_min(int n, const char *message,
                      morpheus_layout_e layout,
                      int size, double *x);

void bench_column_pred(int n, const char *message,
                       double (*pred)(double, double),
                       morpheus_layout_e layout,
                       int size, double *x);

void bench_row_pred(int n, const char *message,
                    double (*pred)(double, double),
                    morpheus_layout_e layout,
                    int size, double *x);

void bench_column_max_index(int n, const char *message,
                            morpheus_layout_e layout,
                            int size, double *x);

void bench_column_min_index(int n, const char *message,
                            morpheus_layout_e layout,
                            int size, double *x);

void bench_row_max_index(int n, const char *message,
                         morpheus_layout_e layout,
                         int size, double *x);

void bench_row_min_index(int n, const char *message,
                         morpheus_layout_e layout,
                         int size, double *x);
#endif /* MORPHEUS_BENCHMARKS_BENCH_MATRIX_MAP_H */
