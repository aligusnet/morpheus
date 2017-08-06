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
        y[i] = op(y[i], row[j]);                            \
      }                                                     \
    }                                                       \
  } else if (layout == morpheus_col_major) {                \
    /* first column is initial values */                    \
    morpheus_dcopy(nrows, x, y);                            \
    for (int j = 1; j < ncols; ++j) {                       \
      const double *column = x + j*nrows;                   \
      for (int i = 0; i < nrows; ++i) {                     \
        y[i] = op(y[i], column[i]);                         \
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

void morpheus_column_max_index(morpheus_layout_e layout,
                               int nrows, int ncols,
                               const double *x,
                               double *y,
                               int *is) {
  if (layout == morpheus_row_major) {
    for (int j = 0; j < ncols; ++j) {
      is[j] = 0;
      y[j] = x[j];
    }
    morpheus_dcopy(ncols, x, y);
    for (int i = 1; i < nrows; ++i) {
      const double *row = x + i*ncols;
      for (int j = 0; j < ncols; ++j) {
        if (y[j] < row[j]) {
          y[j] = row[j];
          is[j] = i;
        }
      }
    }
  } else if (layout == morpheus_col_major) {
    for (int j = 0; j < ncols; ++j) {
      const double *column = &x[j*nrows];
      y[j] = column[0];
      is[j] = 0;
      for (int i = 1; i < nrows; ++i) {
        if (y[j] < column[i]) {
          y[j] = column[i];
          is[j] = i;
        }
      }
    }
  } else {
    perror("unkwnown matrix layout");
    assert(0);
  }
}


void morpheus_column_min_index(morpheus_layout_e layout,
                               int nrows, int ncols,
                               const double *x,
                               double *y,
                               int *is) {
  if (layout == morpheus_row_major) {
    for (int j = 0; j < ncols; ++j) {
      is[j] = 0;
      y[j] = x[j];
    }
    morpheus_dcopy(ncols, x, y);
    for (int i = 1; i < nrows; ++i) {
      const double *row = x + i*ncols;
      for (int j = 0; j < ncols; ++j) {
        if (y[j] > row[j]) {
          y[j] = row[j];
          is[j] = i;
        }
      }
    }
  } else if (layout == morpheus_col_major) {
    for (int j = 0; j < ncols; ++j) {
      const double *column = &x[j*nrows];
      y[j] = column[0];
      is[j] = 0;
      for (int i = 1; i < nrows; ++i) {
        if (y[j] > column[i]) {
          y[j] = column[i];
          is[j] = i;
        }
      }
    }
  } else {
    perror("unkwnown matrix layout");
    assert(0);
  }
}

void morpheus_row_max_index(morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y,
                            int *is) {
  if (layout == morpheus_row_major) {
    for (int i = 0; i < nrows; ++i) {
      const double *row = x + i*ncols;
      y[i] = row[0];
      is[i] = 0;
      for (int j = 1; j < ncols; ++j) {
        if (y[i] < row[j]) {
          y[i] = row[j];
          is[i] = j;
        }
      }
    }
  } else if (layout == morpheus_col_major) {
    /* first column is initial values */
    morpheus_dcopy(nrows, x, y);
    for (int j = 1; j < ncols; ++j) {
      const double *column = x + j*nrows;
      for (int i = 0; i < nrows; ++i) {
        if (y[i] < column[i]) {
          y[i] = column[i];
          is[i] = j;
        }
      }
    }
  } else {
    perror("unkwnown matrix layout");
    assert(0);
  }
}

void morpheus_row_min_index(morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y,
                            int *is) {
  if (layout == morpheus_row_major) {
    for (int i = 0; i < nrows; ++i) {
      const double *row = x + i*ncols;
      y[i] = row[0];
      is[i] = 0;
      for (int j = 1; j < ncols; ++j) {
        if (y[i] > row[j]) {
          y[i] = row[j];
          is[i] = j;
        }
      }
    }
  } else if (layout == morpheus_col_major) {
    /* first column is initial values */
    morpheus_dcopy(nrows, x, y);
    for (int j = 1; j < ncols; ++j) {
      const double *column = x + j*nrows;
      for (int i = 0; i < nrows; ++i) {
        if (y[i] > column[i]) {
          y[i] = column[i];
          is[i] = j;
        }
      }
    }
  } else {
    perror("unkwnown matrix layout");
    assert(0);
  }
}
