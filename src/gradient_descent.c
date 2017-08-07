#include "gradient_descent.h"
#include "simple_blas.h"

#include <math.h>

void morpheus_gradient_descent(const morpheus_gradient_descent_params_t *params,
                               double *theta,
                               void *data) {

  double *grad = params->memory_buffer;

  int i;
  for (i = 0; i < params->max_iters; ++i) {
    params->df(theta, data, grad);
    morpheus_daxpy(params->num_variables, -params->alpha, grad, theta);

    double change = fabs(params->alpha)*morpheus_dnrm2(params->num_variables, grad);
    if (change < params->epsilon) {
      return;
    }
  }
}
