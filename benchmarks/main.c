#include "bench_matrix_map.h"

#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv) {
  int n = 100;
  int size = 1000;
  double *x = calloc(size*size, sizeof(double));
  for (int i = 0; i < size*size; ++i) {
    x[i] = rand();
  }
  
  bench_column_pred(n, "column_pred_max - row_major", fmax, morpheus_row_major, size, x);
  bench_column_pred(n, "column_pred_max - col_major", fmax, morpheus_col_major, size, x);

  bench_row_pred(n, "row_pred_max - row_major", fmax, morpheus_row_major, size, x);
  bench_row_pred(n, "row_pred_max - col_major", fmax, morpheus_col_major, size, x);

  bench_column_max_index(n, "column_max_index - row_major", morpheus_row_major, size, x);
  bench_column_max_index(n, "column_max_index - col_major", morpheus_col_major, size, x);

  bench_column_min_index(n, "column_min_index - row_major", morpheus_row_major, size, x);
  bench_column_min_index(n, "column_min_index - col_major", morpheus_col_major, size, x);

  bench_row_max_index(n, "row_max_index - row_major", morpheus_row_major, size, x);
  bench_row_max_index(n, "row_max_index - col_major", morpheus_col_major, size, x);

  bench_row_min_index(n, "row_min_index - row_major", morpheus_row_major, size, x);
  bench_row_min_index(n, "row_min_index - col_major", morpheus_col_major, size, x);

  free(x);
  return 0;
}
