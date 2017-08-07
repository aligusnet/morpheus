/*! \file gradient.h
  \brief Gradient help functions
*/

#ifndef MORHEPUS_GRADIENT_H
#define MORHEPUS_GRADIENT_H

#include "types.h"


/*! \defgroup gradient gradient
  \brief Gradient help functions
  \{
*/

typedef struct {
  morpheus_f f;          /*!< pointer to function to minimize */
  int num_variables;     /*!< number of the variable of the function */
  double eps;
  double *memory_buffer; /*!< must holds at least num_variables elements */
} morpheus_numeric_gradient_params_t;
/*! \brief Calculates numerical gradient.

Numerical gradient calculation is very slow and analytical method should be preferred.
However the former is useful to test the latter.
 */
void morpheus_numeric_gradient(const morpheus_numeric_gradient_params_t *params,
                               const double *x,
                               void *data,
                               double *grad);

/*! \} */

#endif /* MORHEPUS_GRADIENT_H */
