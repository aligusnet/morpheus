#ifndef MORHEPUS_GRADIENT_H
#define MORHEPUS_GRADIENT_H

#include "types.h"


void morpheus_numeric_gradient(morheus_cost_f cf,
                               const morpheus_data_t *data,
                               const double *theta,
                               double eps,
                               double *grad,
                               double *tmp_buffer);

#endif /* MORHEPUS_GRADIENT_H */
