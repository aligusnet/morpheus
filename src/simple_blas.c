#include "simple_blas.h"

void morpheus_dscal(const int n, const double alpha, double *x) {
  const int inc = 1;
  cblas_dscal(n, alpha, x, inc);
}

void morpheus_dcopy(const int n, const double *x, double *y) {
  const int inc = 1;
  cblas_dcopy(n, x, inc, y, inc);
}

void morpheus_dgemv(const MORPHEUS_TRANSPOSE trans,
                  const int nrows, const int ncols,
                  const double alpha, const double *A, const double *x,
                  const double beta, double *y) {
  const int inc = 1;
  const int lda = ncols;
  cblas_dgemv(CblasRowMajor, (int)trans, nrows, ncols,
              alpha, A, lda, x, inc, beta, y, inc);
}
