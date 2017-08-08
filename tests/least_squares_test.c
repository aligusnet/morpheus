#include "../src/least_squares.h"

#include <Unity/unity.h>

void test_least_squares() {
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
