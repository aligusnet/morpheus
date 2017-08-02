/*! \file simple_blas.h
  \brief Simple Wrappers around BLAS functions
*/

#ifndef MORHEPUS_morpheus_BLAS_H
#define MORHEPUS_morpheus_BLAS_H

#ifdef ACCELERATE
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#endif

typedef enum {
    MorpheusNoTrans=CblasNoTrans,
    MorpheusTrans=CblasTrans,
    MorpheusConjTrans=CblasConjTrans
} MORPHEUS_TRANSPOSE;


void morpheus_dscal(const int n, const double alpha, double *x);

void morpheus_dcopy(const int n, const double *x, double *y);

void morpheus_dgemv(const MORPHEUS_TRANSPOSE trans,
                  const int nrows, const int ncols,
                  const double alpha, const double *A, const double *x,
                  const double beta, double *y);

#endif  /* MORHEPUS_morpheus_BLAS_H */
