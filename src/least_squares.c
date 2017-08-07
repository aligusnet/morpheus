#include "least_squares.h"
#include "simple_blas.h"

void morpheus_ls_hypothesis(const morpheus_data_t *data,
                            const double *theta,
                            double *y) {
  const double alpha = 1;
  const double beta = 0;
  morpheus_dgemv(data->layout, morpheus_no_trans, data->num_examples,
                 data->num_features, alpha, data->x, theta, beta, y);
}


double morpheus_ls_cost_old(const morpheus_reg_t *reg,
                        const morpheus_data_t *data,
                        const double *theta,
                        double *m) {
  const double alpha = 1;
  const double beta = -1;

  morpheus_dcopy(data->num_examples, data->y, m);
  morpheus_dgemv(data->layout, morpheus_no_trans, data->num_examples,
                 data->num_features, alpha, data->x, theta, beta, m);
  double v = morpheus_ddot(data->num_examples, m, m);
  double reg_term = morpheus_cost_reg(reg, data->num_features, theta);
  v = (v*0.5 + reg_term) / data->num_examples;

  return v;
}


void morpheus_ls_gradient_old(const morpheus_reg_t *reg,
                          const morpheus_data_t *data,
                          const double *theta,
                          double *grad,
                          double *m) {
  morpheus_dcopy(data->num_examples, data->y, m);
  morpheus_dgemv(data->layout, morpheus_no_trans, data->num_examples,
                 data->num_features, 1, data->x, theta, -1, m);
  morpheus_dgemv(data->layout, morpheus_trans, data->num_examples,
                 data->num_features, 1, data->x, m, 0, grad);

  double *reg_term = m;
  morpheus_gradient_reg(reg, data->num_features, theta, reg_term);
  morpheus_daxpy(data->num_features, 1, reg_term, grad);

  morpheus_dscal(data->num_features, 1.0/data->num_examples, grad);
}

double morpheus_ls_cost(const double *theta,  /*!< vector of size data->num_features */
                        morpheus_params_t *params) {
  return morpheus_ls_cost_old(&params->reg, &params->data, theta, params->memory_buffer);
}

void morpheus_ls_gradient(const double *theta, /*!< vector of size data->num_features */
                          morpheus_params_t *params,
                          double *grad /*!< vector of size data->num_features */) {
  morpheus_ls_gradient_old(&params->reg, &params->data, theta, grad, params->memory_buffer);
}
