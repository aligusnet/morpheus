#include "gradient_descent.h"
#include "simple_blas.h"

void morphius_gradient_descent(const morpheus_minfuncs_t *funcs,
                               const morpheus_data_t *data,
                               const morpheus_gradient_descent_params_t *params,
                               double *theta,
                               double *tmp_buffer) {

  double *grad = tmp_buffer;
  tmp_buffer = &tmp_buffer[data->num_features];

  int i;
  for (i = 0; i < params->max_iters; ++i) {
    funcs->gradient(data, theta, grad, tmp_buffer);
    morpheus_daxpy(data->num_features, -params->alpha, grad, theta);
  }
}