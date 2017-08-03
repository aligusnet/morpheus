/*! \file gradient_descent.h
  \brief Iterative optimization algorithm Gradient Descent.
*/

#ifndef MORHEPUS_GRADIENT_DESCENT_H
#define MORHEPUS_GRADIENT_DESCENT_H

#include "types.h"

/*! \defgroup gradient_descent gradient_descent
  Iterative optimization algorithm Gradient Descent.
  \{
*/


/*! Gradient Descent Algorithm parameters */
typedef struct {
  int max_iters; /*!< maximum number of iterations allowed */
  double epsilon; /*!< desired precision of the solution */
  double alpha;  /*!< step size */
} morpheus_gradient_descent_params_t;

/*! Gradient Descent Algorithm Implementation */
void morpheus_gradient_descent(const morpheus_minfuncs_t *funcs,
                               const morpheus_data_t *data,
                               const morpheus_gradient_descent_params_t *params,
                               double *theta /*!< vector of size data->num_features */,
                               double *tmp_buffer /*!< must be at least as big as 2*theta */);
/* \} */

#endif /* MORHEPUS_GRADIENT_DESCENT_H */
