#ifndef MORHEPUS_SIMPLE_BLAS_H
#define MORHEPUS_SIMPLE_BLAS_H

#ifdef ACCELERATE
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif

void simple_dscal(const int n, const double alpha, double *x);

void simple_dcopy(const int n, const double *x, double *y);

void simple_dgemv(const enum CBLAS_TRANSPOSE trans,
                  const int nrows, const int ncols,
                  const double alpha, const double *A, const double *x,
                  const double beta, double *y);

#endif  /* MORHEPUS_SIMPLE_BLAS_H */
