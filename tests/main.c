#include "../src/least_squares.h"
#include "../src/gradient.h"

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

  morpheus_data_t data;
  data.x = X;
  data.y = y;
  data.num_features = 2;
  data.num_examples = 5;

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

  double prediction[2];
  double prediction_expected[] = {17, 21};
  morpheus_ls_hypothesis(&data_to_predict, theta, prediction);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(prediction_expected, prediction, data_to_predict.num_features);

  // cost function
  double v = morheus_ls_cost(&data, theta, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE(0, v);

  // gradient
  double grad[2];
  double grad_expected[] = {0, 0};
  morpheus_ls_gradient(&data, theta, grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(grad_expected, grad, 2);
}

void numeric_gradient_tes() {
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

  double theta[] = {3, 3};
  double tmp_buffer[2*5];

  double grad[2];
  morpheus_ls_gradient(&data, theta, grad, tmp_buffer);
  double num_grad[2];
  morpheus_numeric_gradient(morheus_ls_cost, &data, theta, 1e-5, num_grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);
}

int main (int argc, char **argv) {
  UnityBegin("morpheus tests");
  RUN_TEST(test_least_squares);
  RUN_TEST(numeric_gradient_tes);
  return (UnityEnd());
}
