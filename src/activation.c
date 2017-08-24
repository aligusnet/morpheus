#include "activation.h"

#include <math.h>

void morpheus_sigmoid(int n, const double *x, double *y) {
  for (int i = 0; i < n; ++i) {
    y[i] = 1.0/(1.0+exp(-x[i]));
  }
}

void morpheus_sigmoid_gradient(int n, const double *x, double *y) {
  for (int i = 0; i < n; ++i) {
    const double s = 1.0/(1.0+exp(-x[i]));
    y[i] = s * (1-s);
  }
}
