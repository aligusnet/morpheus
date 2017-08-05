#include "matrix_map.h"

#include <math.h>
#include <stdio.h>
#include <assert.h>

#define MORPHEUS_COLUMN_OP(layout, nrows, ncols, x, y, op)  \
  if (layout == morpheus_row_major) {                       \
    /* first row is initial values */                       \
    morpheus_dcopy(ncols, x, y);                            \
    for (int i = 1; i < nrows; ++i) {                       \
      const double *row = x + i*ncols;                      \
      for (int j = 0; j < ncols; ++j) {                     \
        y[j] = op(y[j], row[j]);                            \
      }                                                     \
    }                                                       \
  } else if (layout == morpheus_col_major) {                \
    for (int j = 0; j < ncols; ++j) {                       \
      const double *column = &x[j*nrows];                   \
      y[j] = column[0];                                     \
      for (int i = 1; i < nrows; ++i) {                     \
        y[j] = op(y[j], column[i]);                         \
      }                                                     \
    }                                                       \
  } else {                                                  \
    perror("unkwnown matrix layout");                       \
    assert(0);                                              \
  }

#define MORPHEUS_ROW_OP(layout, nrows, ncols, x, y, op)     \
  if (layout == morpheus_row_major) {                       \
    for (int i = 0; i < nrows; ++i) {                       \
      const double *row = x + i*ncols;                      \
      y[i] = row[0];                                        \
      for (int j = 1; j < ncols; ++j) {                     \
        y[i] = fmax(y[i], row[j]);                          \
      }                                                     \
    }                                                       \
  } else if (layout == morpheus_col_major) {                \
    /* first column is initial values */                    \
    morpheus_dcopy(nrows, x, y);                            \
    for (int j = 1; j < ncols; ++j) {                       \
      const double *column = x + j*nrows;                   \
      for (int i = 0; i < nrows; ++i) {                     \
        y[i] = fmax(y[i], column[i]);                       \
      }                                                     \
    }                                                       \
  } else {                                                  \
   perror("unkwnown matrix layout");                        \
   assert(0);                                               \
  }

void morpheus_column_predicate(double (*pred)(double, double),
                               morpheus_layout_e layout,
                               int nrows,
                               int ncols,
                               const double *x,
                               double *y) {
  MORPHEUS_COLUMN_OP(layout, nrows, ncols, x, y, pred);
}

void morpheus_column_max(morpheus_layout_e layout,
                         int nrows, int ncols,
                         const double *x,
                         double *y) {
  MORPHEUS_COLUMN_OP(layout, nrows, ncols, x, y, fmax);
}

void morpheus_column_min(morpheus_layout_e layout,
                         int nrows, int ncols,
                         const double *x,
                         double *y) {
  MORPHEUS_COLUMN_OP(layout, nrows, ncols, x, y, fmin);
}

void morpheus_row_predicate(double (*pred)(double, double),
                            morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y) {
  MORPHEUS_ROW_OP(layout, nrows, ncols, x, y, pred);
}
