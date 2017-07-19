#include "simple_blas.h"
#include <stdlib.h>
#include <stdio.h>

void ls_hypothesis(const double *X, const double *theta,
                  int num_examples, int num_features, double *y) {
  const double alpha = 1;
  const double beta = 0;
  simple_dgemv(CblasNoTrans, num_examples, num_features,
               alpha, X, theta, beta, y);
}

double ls_cost(const double *X, const double *y, const double *theta,
               int num_examples, int num_features,
               double *m) {
  const double alpha = 1;
  const double beta = -1;

  simple_dcopy(num_examples, y, m);
  simple_dgemv(CblasNoTrans, num_examples, num_features,
               alpha, X, theta, beta, m);
  double v = cblas_ddot(num_examples, m, 1, m , 1);
  v = v*0.5 / num_examples;
  return v;
}

void ls_gradient(const double *X, const double *y, const double *theta,
                 int num_examples, int num_features, double *grad,
                 double *m) {
  simple_dcopy(num_examples, y, m);
  simple_dgemv(CblasNoTrans, num_examples, num_features,
               1, X, theta, -1, m);
  simple_dgemv(CblasTrans, num_examples, num_features,
               1, X, m, 0, grad);
  simple_dscal(num_features, 1.0/num_examples, grad);
}
