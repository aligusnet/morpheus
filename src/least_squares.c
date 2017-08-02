#include "least_squares.h"
#include "simple_blas.h"

void morpheus_ls_hypothesis(const morpheus_data_t *data,
                            const double *theta,
                            double *y) {
  const double alpha = 1;
  const double beta = 0;
  morpheus_dgemv(MorpheusNoTrans, data->num_examples, data->num_features,
               alpha, data->x, theta, beta, y);
}

double morheus_ls_cost(const morpheus_data_t *data,
                       const double *theta,
                       double *m) {
  const double alpha = 1;
  const double beta = -1;

  morpheus_dcopy(data->num_examples, data->y, m);
  morpheus_dgemv(MorpheusNoTrans, data->num_examples, data->num_features,
              alpha, data->x, theta, beta, m);
  double v = cblas_ddot(data->num_examples, m, 1, m , 1);
  v = v*0.5 / data->num_examples;
  return v;
}


void morpheus_ls_gradient(const morpheus_data_t *data,
                          const double *theta,
                          double *grad,
                          double *m) {
  morpheus_dcopy(data->num_examples, data->y, m);
  morpheus_dgemv(MorpheusNoTrans, data->num_examples, data->num_features,
              1, data->x, theta, -1, m);
  morpheus_dgemv(MorpheusTrans, data->num_examples, data->num_features,
              1, data->x, m, 0, grad);
  morpheus_dscal(data->num_features, 1.0/data->num_examples, grad);
}
