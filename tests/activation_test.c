#include "../src/activation.h"

#include <Unity/unity.h>

void test_sigmoid() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {1, 0.5, 0};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_sigmoid(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}

void test_sigmoid_gradient() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {0, 0.25, 0};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_sigmoid_gradient(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}

void test_relu() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {10e10, 0, 0};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_relu(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}

void test_relu_gradient() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {1, 0, 0};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_relu_gradient(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}

void test_tanh() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {1, 0, -1};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_tanh(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}

void test_tanh_gradient() {
  double x[] = {10e10, 0, -10e10};
  double y[3];
  double expected[] = {0, 1, 0};
  int n = sizeof(x)/sizeof(x[0]);
  morpheus_tanh_gradient(n, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected, y, n);
}
