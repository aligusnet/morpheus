#include "statistics.h"

#include <math.h>

double morpheus_mean(int n, const double *x) {
  double m = 0;
  for (int i = 0; i < n; ++i) {
    m += x[i];
  }
  return m/n;
}

double morpheus_stddev_m(double mean, int n, const double *x) {
  if (n < 2) return 0;

  double s = 0;
  for (int i = 0; i < n; ++i) {
    double v = x[i] - mean;
    s += v*v;
  }
  return sqrt(s/(n-1));
}

double morpheus_stddev(int n, const double *x) {
  if (n < 2) return 0;
  
  double m = morpheus_mean(n, x);
  return morpheus_stddev_m(m, n, x);
}
