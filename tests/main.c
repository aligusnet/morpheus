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
  double theta[] = {3, 2};

  double tmp_buffer[2*5];

  // prediction
  double X_to_predict[] = {
    1, 7,
    1, 9
  };
  double prediction[2];
  double prediction_expected[] = {17, 21};
  ls_hypothesis(X_to_predict, theta, 2, 2, prediction);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(prediction_expected, prediction, 2);

  // cost function
  double v = ls_cost(X, y, theta, 5, 2, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE(0, v);

  // gradient
  double grad[2];
  double grad_expected[] = {0, 0};
  ls_gradient(X, y, theta, 5, 2, grad, tmp_buffer);
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
  double theta[] = {3, 3};
  double tmp_buffer[2*5];

  double grad[2];
  ls_gradient(X, y, theta, 5, 2, grad, tmp_buffer);
  double num_grad[2];
  numeric_gradient(ls_cost, X, y, theta, 5, 2, 1e-5, num_grad, tmp_buffer);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(num_grad, grad, 2);
}

int main (int argc, char **argv) {
  UnityBegin("morpheus tests");
  RUN_TEST(test_least_squares);
  RUN_TEST(numeric_gradient_tes);
  return (UnityEnd());
}
