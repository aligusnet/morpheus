/*! \file least_squares.h
  \brief Least Squares Implementation
*/

#ifndef MORHEPUS_LEAST_SQUARES_H
#define MORHEPUS_LEAST_SQUARES_H

#include "types.h"

/*! \defgroup least_squares least_squares
  \brief Least Squares Implementation
  \{
*/

/** Least Squares Hypothesis function */
void morpheus_ls_hypothesis(const morpheus_data_t *data,
                            const double *theta,
                            double *y);


/*! Least Squares Cost function */
// tmp_buffer must be at least as big as theta
double morheus_ls_cost(const morpheus_data_t *data,
                       const double *theta,
                       double *tmp_buffer);


/*! Least Squares Gradient function */
// tmp_buffer must be at least as big as grad
void morpheus_ls_gradient(const morpheus_data_t *data,
                          const double *theta,
                          double *grad,
                          double *tmp_buffer);

/*! \} */

#endif  /* MORHEPUS_LEAST_SQUARES_H */
