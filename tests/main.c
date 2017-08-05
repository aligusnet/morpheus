#include "../src/least_squares.h"
#include "../src/gradient.h"
#include "../src/gradient_descent.h"
#include "../src/matrix_map.h"

#include <Unity/unity.h>

#include <stdio.h>

void test_least_squares () {
  morpheus_reg_t reg_none;
  reg_none.type = morpheus_reg_none;

  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };
  double y[] = {9, 13, 23, 3, 11};

  morpheus_data_t data;
  data.x = X;
  data.y = y;
  data.num_features = 2;
  data.num_examples = 5;
  data.layout = morpheus_row_major;

  double theta[] = {3, 2};

  double tmp_buffer[2*5];

  // prediction
  double X_to_predict[] = {
    1, 7,
    1, 9
  };

  morpheus_data_t data_to_predict;
  data_to_predict.x = X_to_predict;
  data_to_predict.y = 0;
  data_to_predict.num_features = 2;
  data_to_predict.num_examples = 2;
  data_to_predict.layout = morpheus_row_major;

  double prediction[2];
  double prediction_expected[] = {17, 21};
  morpheus_ls_hypothesis(&data_to_predict, theta, prediction);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(prediction_expected, prediction, data_to_predict.num_features);

  // cost function
  double v = morpheus_ls_cost(&reg_none, &data, theta, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE(0, v);

  // gradient
  double grad[2];
  double grad_expected[] = {0, 0};
  morpheus_ls_gradient(&reg_none, &data, theta, grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(grad_expected, grad, 2);
}

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
  morpheus_data_t data;
  data.x = X;
  data.y = y;
  data.num_features = 2;
  data.num_examples = 5;
  data.layout = morpheus_row_major;

  double theta[] = {3, 3};
  double tmp_buffer[2*5];

  double grad[2];
  double num_grad[2];

  /* No regularization */
  morpheus_ls_gradient(&reg_none, &data, theta, grad, tmp_buffer);

  morpheus_numeric_gradient(morpheus_ls_cost, &reg_none, &data, theta, 1e-5, num_grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);

  /* L2 regularization */
  morpheus_ls_gradient(&reg_l2, &data, theta, grad, tmp_buffer);

  morpheus_numeric_gradient(morpheus_ls_cost, &reg_l2, &data, theta, 1e-5, num_grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);
}

void test_gradient_descent() {
  morpheus_reg_t reg_none;
  reg_none.type = morpheus_reg_none;

  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };
  double y[] = {9, 13, 23, 3, 11};
  morpheus_data_t data;
  data.x = X;
  data.y = y;
  data.num_features = 2;
  data.num_examples = 5;
  data.layout = morpheus_row_major;

  double theta[] = {1, 1};
  double tmp_buffer[2*5];

  morpheus_gradient_descent_params_t params;
  params.max_iters = 4000;
  params.epsilon = 1e-10;
  params.alpha = 1e-2;

  morpheus_minfuncs_t funcs;
  funcs.cost = morpheus_ls_cost;
  funcs.gradient = morpheus_ls_gradient;

  double theta_expected[] = {3, 2};
  morpheus_gradient_descent(&funcs, &reg_none, &data, &params, theta, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(theta_expected, theta, data.num_features);
}

void test_column_max() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];

  double expected_row_major[] = {71, 32, 78, 90, 37};
  morpheus_column_max(morpheus_row_major, 4, 5, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_row_major, y, 5);

  double expected_col_major[] = {71, 23, 53, 90};
  morpheus_column_max(morpheus_col_major, 5, 4, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_col_major, y, 4);
}

int main (int argc, char **argv) {
  UnityBegin("morpheus tests");
  RUN_TEST(test_least_squares);
  RUN_TEST(test_numeric_gradient);
  RUN_TEST(test_gradient_descent);
  RUN_TEST(test_column_max);
  return (UnityEnd());
}
