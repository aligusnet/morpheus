#include "regularization.h"
#include "simple_blas.h"

double morpheus_cost_reg(const morpheus_reg_t *params,
                         const double num_features,
                         const double *theta) {
  if (params->type == morpheus_reg_l2) {
    theta = theta + 1;  /* skip the first element */
    return morpheus_ddot(num_features-1, theta, theta) * params->lambda * 0.5;
  }
  return 0;
}

void morpheus_gradient_reg(const morpheus_reg_t *params,
                           const double num_features,
                           const double *theta,
                           double *reg) {
  if (params->type == morpheus_reg_l2) {
    morpheus_dcopy(num_features, theta, reg);
    morpheus_dscal(num_features, params->lambda, reg);
    reg[0] = 0;
  } else {
    for (int i = 0; i < num_features; ++i) {
      reg[i] = 0;
    }
  }
}
