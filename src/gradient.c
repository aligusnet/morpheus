#include "gradient.h"
#include "simple_blas.h"

#include <stdlib.h>

void morpheus_numeric_gradient(const morpheus_numeric_gradient_params_t *params,
                               const double *x,
                               void *data,
                               double *grad) {
  double *bumped_x = params->memory_buffer;
  int n = params->num_variables;
  morpheus_dcopy(n, x, bumped_x);
  for (int i = 0; i < n; i++) {
    double diff = x[i]*params->eps+params->eps;
    bumped_x[i] += diff;
    grad[i] = params->f(bumped_x, data);
    diff *= 2;
    bumped_x[i] -= diff;
    grad[i] -= params->f(bumped_x, data);
    grad[i] /= diff;
    bumped_x[i] = x[i];
  }
}
