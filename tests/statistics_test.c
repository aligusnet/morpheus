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

void test_column_mean() {
  double a[] = {35,32,213,54,
                81,92,63,70,
                77,14,91,20};
  int m = 3;
  int n = 4;

  double expected_means_rm[] = {64.33333, 46, 122.33333, 48};
  double expected_stddev_rm[] = {25.48202, 40.84116, 79.75797, 25.53429};

  double expected_means_cm[] = {83.5, 76.5, 50.5};
  double expected_stddev_cm[] = {86.88114, 12.71482, 39.17908};

  double means[4];

  morpheus_column_mean(morpheus_row_major, m, n, a, means);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_means_rm, means, n);

  morpheus_column_mean(morpheus_col_major, n, m, a, means);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_means_cm, means, m);
}

void test_row_mean() {
  double a[] = {35,32,213,54,
                81,92,63,70,
                77,14,91,20};
  int m = 3;
  int n = 4;

  double expected_means_rm[] = {83.5, 76.5, 50.5};
  double expected_means_cm[] = {64.33333, 46, 122.33333, 48};

  double means[4];

  morpheus_row_mean(morpheus_row_major, m, n, a, means);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_means_rm, means, m);

  morpheus_row_mean(morpheus_col_major, n, m, a, means);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_means_cm, means, n);
}

void test_column_stddev_m() {
  double a[] = {35,32,213,54,
                81,92,63,70,
                77,14,91,20};
  int m = 3;
  int n = 4;

  double means_rm[] = {64.33333, 46, 122.33333, 48};
  double expected_stddev_rm[] = {25.48202, 40.84116, 79.75797, 25.53429};

  double means_cm[] = {83.5, 76.5, 50.5};
  double expected_stddev_cm[] = {86.88114, 12.71482, 39.17908};

  double stddevs[4];

  morpheus_column_stddev_m(morpheus_row_major, m, n, means_rm, a, stddevs);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_stddev_rm, stddevs, n);

  morpheus_column_stddev_m(morpheus_col_major, n, m, means_cm, a, stddevs);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_stddev_cm, stddevs, m);
}

void test_row_stddev_m() {
  double a[] = {35,32,213,54,
                81,92,63,70,
                77,14,91,20};
  int m = 3;
  int n = 4;

  double means_rm[] = {83.5, 76.5, 50.5};
  double expected_stddev_rm[] = {86.88114, 12.71482, 39.17908};

  double means_cm[] = {64.33333, 46, 122.33333, 48};
  double expected_stddev_cm[] = {25.48202, 40.84116, 79.75797, 25.53429};

  double stddevs[4];

  morpheus_row_stddev_m(morpheus_row_major, m, n, means_rm, a, stddevs);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_stddev_rm, stddevs, m);

  morpheus_row_stddev_m(morpheus_col_major, n, m, means_cm, a, stddevs);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_stddev_cm, stddevs, n);
}
