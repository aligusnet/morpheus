/*! \file simple_blas.h
  \brief Simple Wrappers around BLAS functions
*/

#ifndef MORHEPUS_SIMPLE_BLAS_H
#define MORHEPUS_SIMPLE_BLAS_H

#ifdef ACCELERATE
#include <Accelerate/Accelerate.h>
#else
#include <cblas.h>
#include "lapack.h"
#endif

/*! \defgroup simple_blas simple_blas
  \brief Simple Wrappers around BLAS functions
  \{
*/


/*! Whether to transpose matrix */
typedef enum {
    morpheus_no_trans = CblasNoTrans,
    morpheus_trans = CblasTrans
} morpheus_transpose_e;


/*! Matrix Layout */
typedef enum {
  morpheus_row_major = CblasRowMajor,  /*!< C-style layout */
  morpheus_col_major = CblasColMajor   /*!< Fortran-style layout */
} morpheus_layout_e;


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
void morpheus_dgemv(const morpheus_layout_e layout,
                    const morpheus_transpose_e trans, /*!< Specifies whether to transpose matrix A */
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
void morpheus_daxpy(const int n,          /*!< number of elements in vectors x and y */
                    const double alpha,   /*!< scalar alpha */
                    const double *x,      /*!< vector x */
                    double *y             /*!< vector y */);


/*! Returns the euclidean norm of a vector

    sqrt( x'*x )
*/
double morpheus_dnrm2(const int n, const double *x);

/*! Forms the dot product of two vectors. */
double morpheus_ddot(const int n, const double *x, const double *y);

/*! Compute the inverse of a given square matrix. */
int morpheus_inverse(int n,      /*!< size of the matrix to inverse */
                     double *x,        /*!< matrix to inverse */
                     int *pivot,       /*!< vector of size n */
                     double *workspace /*!< vector of size of n*n */);

/*!
  A = alpha * x * yT + A
*/
void morpheus_dger(const morpheus_layout_e layout,
                   const int nrows,
                   const int ncols,
                   const double alpha,
                   const double *x,
                   const double *y,
                   double *a);
/*! \} */

#endif  /* MORHEPUS_SIMPLE_BLAS_H */
