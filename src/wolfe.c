#include "wolfe.h"

#define BIG_VALUE 100.0

void morpheus_wolfe(const morheus_wolfe_params_t *params,
                    const double *x,
                    const double *direction,
                    void *data,
                    double *values) {
  double alpha = 0;
  double beta = BIG_VALUE*10;
  double step = 5;
  int n = params->num_variables;
  double c1 = params->c1;
  double c2 = params->c2;
  morpheus_f f = params->f;
  morpheus_df df = params->df;
  double *grad = params->memory_buffer;

  for (int i = 0; i < params->max_iters; ++i) {
    morpheus_dcopy(n, x, values);
    morpheus_daxpy(n, step, direction, values);
    double left = f(values, data);
    df(x, data, grad);
    double grad_ddot_direction = morpheus_ddot(n, grad, direction);
    double right = f(x, data) + grad_ddot_direction;
    if (left > right) {
      beta = step;
      step = (alpha + beta) * 0.5;
    } else {
      df(values, data, grad);
      double grad_next_ddot_direction = morpheus_ddot(n, grad, direction);
      if (grad_next_ddot_direction < c2*grad_ddot_direction) {
        alpha = step;
        if (beta > BIG_VALUE) {
          step = 2*alpha;
        } else {
          step = (alpha + beta) * 0.5;
        }
      } else {
        break;
      }
    }
  }
}
