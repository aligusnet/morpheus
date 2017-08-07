/*! \file least_squares.h
  \brief Least Squares Implementation
*/

#ifndef MORHEPUS_LEAST_SQUARES_H
#define MORHEPUS_LEAST_SQUARES_H

#include "types.h"
#include "regularization.h"

/*! \defgroup least_squares least_squares
  \brief Least Squares Implementation
  \{
*/

/** Least Squares Hypothesis function */
void morpheus_ls_hypothesis(const morpheus_data_t *data,
                            const double *theta,
                            double *y);


/*! Least Squares Cost function.

  memory_buffer of params must be at least as big as theta
*/
double morpheus_ls_cost(const double *theta,  /*!< vector of size data->num_features */
                        morpheus_params_t *params);


/*! Least Squares Gradient function
  memory_buffer of params must be at least as big as grad
*/
void morpheus_ls_gradient(const double *theta, /*!< vector of size data->num_features */
                          morpheus_params_t *params,
                          double *grad /*!< vector of size data->num_features */);

/*! \} */

#endif  /* MORHEPUS_LEAST_SQUARES_H */
