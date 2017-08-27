#include "../src/statistics.h"
#include <Unity/unity.h>

void test_mean() {
  double x[] = {35,32,213,54,81,92,63,70};
  int n = sizeof(x)/sizeof(x[0]);

  double m = morpheus_mean(n, x);
  TEST_ASSERT_EQUAL_DOUBLE(80, m);
}

void test_stddev_m() {
  double x[] = {35,32,213,54,81,92,63,70};
  int n = sizeof(x)/sizeof(x[0]);
  double m = 80;

  double s = morpheus_stddev_m(m, n, x);
  TEST_ASSERT_EQUAL_DOUBLE(57.60456, s);
}

void test_stddev() {
  double x[] = {35,32,213,54,81,92,63,70};
  int n = sizeof(x)/sizeof(x[0]);

  double s = morpheus_stddev(n, x);
  TEST_ASSERT_EQUAL_DOUBLE(57.60456, s);
}
