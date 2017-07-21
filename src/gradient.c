#include "gradient.h"
#include "simple_blas.h"

void numeric_gradient(cost_f cf,
                      const double *X, const double *y, const double *theta,
                      int num_examples, int num_features, double eps,
                      double *grad, double *tmp_buffer) {
  double *bumped_theta = tmp_buffer;
  simple_dcopy(num_features, theta, bumped_theta);
  tmp_buffer = &tmp_buffer[num_features];
  int i;
  double eps1 = 1+eps;
  for (i = 0; i < num_features; i++) {
    double diff = theta[i]*eps+eps;
    bumped_theta[i] += diff;
    grad[i] = cf(X, y, bumped_theta, num_examples, num_features, tmp_buffer);
    diff *= 2;
    bumped_theta[i] -= diff;
    grad[i] -= cf(X, y, bumped_theta, num_examples, num_features, tmp_buffer);
    grad[i] /= diff;
    bumped_theta[i] = theta[i];
  }
}
