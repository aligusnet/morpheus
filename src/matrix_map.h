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

  Returns accumulator values for every column.
 */
void morpheus_column_predicate(double (*pred)(double, double),
                               morpheus_layout_e layout,
                               int nrows,
                               int ncols,
                               const double *x,
                               double *y                  /*!< vector of size ncols */);

/*! Scan every row if matrix x.

 Pred takes and accumulator and next value of the row, returns new accumulator.

 Returns accumulator values for every row.
*/
void morpheus_row_predicate(double (*pred)(double, double),
                            morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y             /*!< vector of size ncols */);


/*! Finds maximum values and their indices of every column of the matrix x */
void morpheus_column_max_index(morpheus_layout_e layout,
                               int nrows, int ncols,
                               const double *x,
                               double *y,     /*!< vector of maximum values of size ncols */
                               int *is        /*!< vector of indices of size ncols */);

/*! Finds minimum values and their indices of every column of the matrix x */
void morpheus_column_min_index(morpheus_layout_e layout,
                               int nrows, int ncols,
                               const double *x,
                               double *y,     /*!< vector of minimum values of size ncols */
                               int *is        /*!< vector of indices of size ncols */);

/*! Finds maximum values and their indices of every row of the matrix x */
void morpheus_row_max_index(morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y,        /*!< vector of maximum values of size nrows */
                            int *is           /*!< vector of indices of size nrows */);

/*! Finds minimum values and their indices of every row of the matrix x */
void morpheus_row_min_index(morpheus_layout_e layout,
                            int nrows, int ncols,
                            const double *x,
                            double *y,        /*!< vector of minimum values of size nrows */
                            int *is           /*!< vector of indices of size nrows */);
/*! \} */

#endif /* MORPHEPUS_MATRIX_MAP_H */
