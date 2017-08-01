#include "simple_blas.h"

void simple_dscal(const int n, const double alpha, double *x) {
  const int inc = 1;
  cblas_dscal(n, alpha, x, inc);
}

void simple_dcopy(const int n, const double *x, double *y) {
  const int inc = 1;
  cblas_dcopy(n, x, inc, y, inc);
}

void simple_dgemv(const SIMPLE_TRANSPOSE trans,
                  const int nrows, const int ncols,
                  const double alpha, const double *A, const double *x,
                  const double beta, double *y) {
  const int inc = 1;
  const int lda = ncols;
  cblas_dgemv(CblasRowMajor, (int)trans, nrows, ncols,
              alpha, A, lda, x, inc, beta, y, inc);
}
