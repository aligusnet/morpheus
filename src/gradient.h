#ifndef MORHEPUS_GRADIENT_H
#define MORHEPUS_GRADIENT_H

typedef double (*cost_f)(const double *X, const double *y, const double *theta,
                         int num_examples, int num_features,
                         double *tmp_buffer);

void numeric_gradient(cost_f cf,
                      const double *X, const double *y, const double *theta,
                      int num_examples, int num_features, double eps,
                      double *grad, double *tmp_buffer);

#endif /* MORHEPUS_GRADIENT_H */
