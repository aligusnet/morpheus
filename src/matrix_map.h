/*! \file matrix_map.h
  \brief Matrix column/row map operations.
*/

#ifndef MORPHEPUS_MATRIX_MAP_H
#define MORPHEPUS_MATRIX_MAP_H

#include "simple_blas.h"

/*! \defgroup matrix_map matrix_map
  \brief Matrix column/row map operations.
  \{
*/

/*! Scan every column if matrix x.

  Pred takes and accumulator and next value of the column, returns new accumulator.

  Return accumulator values for every column.
 */
void morpheus_column_predicate(morpheus_layout_e layout,
                               int nrows,
                               int ncols,
                               const double *x,
                               double *y,                  /*!< vector of maximum values of size ncols */
                               double (*pred)(double, double));

/*! Finds maximum values of every column of the matrix x */
void morpheus_column_max(morpheus_layout_e layout,
                         int nrows,
                         int ncols,
                         const double *x,
                         double *y                  /*!< vector of maximum values of size ncols */);


/*! Finds minimum values of every column of the matrix x */
void morpheus_column_min(morpheus_layout_e layout,
                         int nrows, int ncols,
                         const double *x,
                         double *y                 /*!< vector of minimum values of size ncols */);
/*! \} */

#endif /* MORPHEPUS_MATRIX_MAP_H */
