#include "../src/gradient.h"
#include "../src/least_squares.h"

#include <Unity/unity.h>

void test_numeric_gradient() {
  morpheus_reg_t reg_none;
  reg_none.type = morpheus_reg_none;

  morpheus_reg_t reg_l2;
  reg_l2.type = morpheus_reg_l2;
  reg_l2.lambda = 1;

  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };
  double y[] = {9, 13, 23, 3, 11};

  double tmp_buffer[2*5];

  morpheus_params_t data;
  data.data.x = X;
  data.data.y = y;
  data.data.num_features = 2;
  data.data.num_examples = 5;
  data.data.layout = morpheus_row_major;
  data.memory_buffer = tmp_buffer;

  double tmp_buffer2[2*5];
  morpheus_numeric_gradient_params_t params;
  params.f = (morpheus_f)morpheus_ls_cost;
  params.num_variables = data.data.num_features;
  params.eps = 1e-5;
  params.memory_buffer = tmp_buffer2;

  double theta[] = {3, 3};

  double grad[2];
  double num_grad[2];

  // No regularization
  data.reg = reg_none;
  morpheus_ls_gradient(theta, &data, grad);

  morpheus_numeric_gradient(&params, theta, &data, num_grad);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);

  // L2 regularization
  data.reg = reg_l2;
  morpheus_ls_gradient(theta, &data, grad);

  morpheus_numeric_gradient(&params, theta, &data, num_grad);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);
}
