#include "../src/wolfe.h"
#include <Unity/unity.h>


double func(const double *x, void *data) {
  double a = x[0]*x[0] - x[1];
  double b = x[0]-1;
  return 100*a*a + b*b;
}

void dfunc(const double *x, void *data, double *grad) {
  grad[0] = 400*x[0]*(x[0]*x[0]-x[1]) + 2*(x[0]-1);
  grad[1] = -200*(x[0]*x[0] - x[1]);
}

void test_wolfe() {
  double memory_buffer[2];
  morheus_wolfe_params_t params;
  params.f = func;
  params.df = dfunc;
  params.num_variables = 2;
  params.max_iters = 10;
  params.c1 = 0.15;
  params.c2 = 0.3;
  params.memory_buffer = memory_buffer;

  double x[] = {0.6, 0.5};
  double direction[] = {-0.3, -0.4};
  double result[2];
  morpheus_wolfe(&params, x, direction, 0, result);

  double expected_result[] = {0.225, 0};
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_result, result, 2);
}
