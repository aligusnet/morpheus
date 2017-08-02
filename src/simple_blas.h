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

/*! \defgroup simple_blas simple_blas
  \brief Simple Wrappers around BLAS functions
  \{
*/

/*! Whether to transpose matrix */
typedef enum {
    MorpheusNoTrans=CblasNoTrans,
    MorpheusTrans=CblasTrans,
    MorpheusConjTrans=CblasConjTrans
} MORPHEUS_TRANSPOSE;


/*! Scales a vector by a constant. */
void morpheus_dscal(const int n, const double alpha, double *x);


/*! Copies a vector, x, to a vector, y. */
void morpheus_dcopy(const int n, const double *x, double *y);


/*! Performs one of the matrix-vector operations.
  y = alpha*A*x + beta*y,   or   y = alpha*A**T*x + beta*y,

  where alpha and beta are scalars, x and y are vectors and A is an
  nrows by ncols matrix.

  Assumes row-major ordering of matrix A.
*/
void morpheus_dgemv(const MORPHEUS_TRANSPOSE trans, /*!< Specifies whether to transpose matrix A */
                  const int nrows,
                  const int ncols,
                  const double alpha,
                  const double *A,
                  const double *x,
                  const double beta,
                  double *y);

/*! Constant times a vector plus a vector.
  y = alpha*x + y;
*/
void morpheus_daxpy(const int n,  /*!< number of elements in vectors x and y */
                    const double alpha, /*!< scalar alpha */
                    const double *x, /*!< vector x */
                    double *y /*!< vector y */);
/*! \} */

#endif  /* MORHEPUS_morpheus_BLAS_H */
