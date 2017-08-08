#include "../src/gradient_descent.h"
#include "../src/least_squares.h"

#include <Unity/unity.h>

void test_gradient_descent() {
  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };
  double y[] = {9, 13, 23, 3, 11};

  double theta[] = {1, 1};
  double tmp_buffer[2*5];

  morpheus_params_t data;
  data.data.x = X;
  data.data.y = y;
  data.data.num_features = 2;
  data.data.num_examples = 5;
  data.data.layout = morpheus_row_major;
  data.memory_buffer = tmp_buffer;
  data.reg.type = morpheus_reg_none;

  double tmp_buffer2[2*5];
  morpheus_gradient_descent_params_t params;
  params.f = (morpheus_f)morpheus_ls_cost;
  params.df = (morpheus_df)morpheus_ls_gradient;
  params.max_iters = 4000;
  params.epsilon = 1e-10;
  params.alpha = 1e-2;
  params.memory_buffer = tmp_buffer2;
  params.num_variables = data.data.num_features;

  double theta_expected[] = {3, 2};
  morpheus_gradient_descent(&params, theta, &data);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(theta_expected, theta, data.data.num_features);
}
