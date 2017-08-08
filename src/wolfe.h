/*! \file wolfe.h
  \brief Wolfe conditions.
*/

#ifndef MORPHEUS_WOLFE_H
#define MORPHEUS_WOLFE_H

#include "types.h"

/*! \defgroup wolfe wolfe
  \brief Wolfe conditions.
  \{
*/

/*! Wolfe conditions parameters */
typedef struct {
  morpheus_f f;
  morpheus_df df;
  int num_variables;
  int max_iters;
  double c1;
  double c2;
  double *memory_buffer;  /*!< must have at least num_variables elements */
} morheus_wolfe_params_t;

/*! Wolfe conditions */
void morpheus_wolfe(const morheus_wolfe_params_t *params,
                    const double *x,          /*!< num_variables elements vector */
                    const double *direction,  /*!< num_variables elements vector */
                    void *data,
                    double *values            /*!< num_variables elements vector */);
/*! \} */

#endif  /* MORPHEUS_WOLFE_H */
