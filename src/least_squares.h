#ifndef MORHEPUS_LEAST_SQUARES_H
#define MORHEPUS_LEAST_SQUARES_H

void ls_hypothesis(const double *X, const double *theta,
                  int num_examples, int num_features, double *y);

// tmp_buuffer must be at least as big as theta
double ls_cost(const double *X, const double *y, const double *theta,
               int num_examples, int num_features,
               double *tmp_buffer);

// tmp_buuffer must be at least as big as grad
void ls_gradient(const double *X, const double *y, const double *theta,
                int num_examples, int num_features, double *grad,
                double *tmp_buffer);

#endif  /* MORHEPUS_LEAST_SQUARES_H */
