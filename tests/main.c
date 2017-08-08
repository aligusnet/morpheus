#include "../src/least_squares.h"
#include "../src/gradient.h"
#include "../src/gradient_descent.h"
#include "../src/matrix_map.h"

#include <Unity/unity.h>

#include <stdio.h>

void test_least_squares () {
  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };
  double y[] = {9, 13, 23, 3, 11};

  double theta[] = {3, 2};

  double tmp_buffer[2*5];

  morpheus_params_t params;
  params.data.x = X;
  params.data.y = y;
  params.data.num_features = 2;
  params.data.num_examples = 5;
  params.data.layout = morpheus_row_major;
  params.reg.type = morpheus_reg_none;
  params.memory_buffer = tmp_buffer;

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
  double v = morpheus_ls_cost(theta, &params);
  TEST_ASSERT_EQUAL_DOUBLE(0, v);

  // gradient
  double grad[2];
  double grad_expected[] = {0, 0};
  morpheus_ls_gradient(theta, &params, grad);
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

extern void test_column_pred();
extern void test_row_pred();
extern void test_column_max_index();
extern void test_column_min_index();
extern void test_row_max_index();
extern void test_row_min_index();
extern void test_column_sum();
extern void test_row_sum();
extern void test_inverse();
extern void test_wolfe();

int main (int argc, char **argv) {
  UnityBegin("morpheus tests");
  RUN_TEST(test_least_squares);
  RUN_TEST(test_numeric_gradient);
  RUN_TEST(test_gradient_descent);
  RUN_TEST(test_column_pred);
  RUN_TEST(test_row_pred);
  RUN_TEST(test_column_max_index);
  RUN_TEST(test_column_min_index);
  RUN_TEST(test_row_max_index);
  RUN_TEST(test_row_min_index);
  RUN_TEST(test_column_sum);
  RUN_TEST(test_row_sum);
  RUN_TEST(test_inverse);
  RUN_TEST(test_wolfe);

  return (UnityEnd());
}
