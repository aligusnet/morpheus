#include "matrix_map.h"

#include <math.h>
#include <stdio.h>
#include <assert.h>

void morpheus_column_max(morpheus_layout_e layout,
                         int nrows, int ncols,
                         const double *x,
                         double *y) {
  if (layout == morpheus_row_major) {
    /* first row is initial values */
    morpheus_dcopy(ncols, x, y);

    for (int i = 1; i < nrows; ++i) {
      const int row_offset = i*ncols;
      for (int j = 0; j < ncols; ++j) {
        y[j] = fmax(x[row_offset+j], y[j]);
      }
    }
  } else if (layout == morpheus_col_major) {
    for (int j = 0; j < ncols; ++j) {
      const double *column = &x[j*nrows];
      y[j] = column[0];
      for (int i = 1; i < nrows; ++i) {
        y[j] = fmax(column[i], y[j]);
      }
    }
  } else {
    perror("unkwnown matrix layout");
    assert(0);
  }
}
