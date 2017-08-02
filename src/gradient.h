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

/*! \brief Calculates numerical gradient.

Numerical gradient calculation is very slow and analytical method should be preferred.
However the former is useful to test the latter.
 */
void morpheus_numeric_gradient(morpheus_cost_f cf,
                               const morpheus_data_t *data,
                               const double *theta,
                               double eps,
                               double *grad,
                               double *tmp_buffer);

/*! \} */

#endif /* MORHEPUS_GRADIENT_H */
