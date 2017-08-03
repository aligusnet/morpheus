#include "gradient.h"
#include "simple_blas.h"

void morpheus_numeric_gradient(morpheus_cost_f cf,
                               const morpheus_reg_t *reg,
                               const morpheus_data_t *data,
                               const double *theta,
                               double eps,
                               double *grad,
                               double *tmp_buffer) {
  double *bumped_theta = tmp_buffer;
  morpheus_dcopy(data->num_features, theta, bumped_theta);
  tmp_buffer = &tmp_buffer[data->num_features];
  for (int i = 0; i < data->num_features; i++) {
    double diff = theta[i]*eps+eps;
    bumped_theta[i] += diff;
    grad[i] = cf(reg, data, bumped_theta, tmp_buffer);
    diff *= 2;
    bumped_theta[i] -= diff;
    grad[i] -= cf(reg, data, bumped_theta, tmp_buffer);
    grad[i] /= diff;
    bumped_theta[i] = theta[i];
  }
}
