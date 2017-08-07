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
  morpheus_f f;             /*!< pointer to function */
  morpheus_df df;           /*!< pointer to gradient function */
  int max_iters; /*!< maximum number of iterations allowed */
  double epsilon; /*!< desired precision of the solution */
  double alpha;  /*!< step size */
  int num_variables;  /*!< number of variable of the function */
  double *memory_buffer; /*!< must have at least num_variables elements */
} morpheus_gradient_descent_params_t;

/*! Gradient Descent Algorithm Implementation */
void morpheus_gradient_descent(const morpheus_gradient_descent_params_t *params,
                               double *theta, /*!< vector of size data->num_features */
                               void *data);
/* \} */

#endif /* MORHEPUS_GRADIENT_DESCENT_H */
