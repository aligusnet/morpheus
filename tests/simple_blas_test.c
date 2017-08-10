#include "../src/simple_blas.h"
#include <Unity/unity.h>

void test_inverse() {
  double x[] = {1.0, 0.0, 2.0,
                -1.0, 5.0, 0.0,
                0.0, 3.0, -9.0};

  const int n = 3;
  double inversed_x[] =
    {0.88235294117647067, -0.11764705882352944, 0.19607843137254904,
     0.17647058823529416, 0.17647058823529413, 0.03921568627450981,
     0.058823529411764663, 0.058823529411764719, -0.098039215686274522};

  int pivot[n];
  double workspace[n*n];

  int rc = morpheus_inverse(n, x, pivot, workspace);

  TEST_ASSERT_EQUAL_INT(0, rc);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(inversed_x, x, n*n);
}


void test_ger_rm() {
  double x[] = {1, 2, 3};
  double y[] = {4, 5, 6};
  double a[] = {29, 23, 19,
                17, 13, 11,
                7, 3, 1};
  double alpha = -1;
  double n = 3;

  double expected_a[] = {25, 18, 13,
                         9, 3, -1,
                         -5, -12, -17};
  morpheus_dger(morpheus_row_major, n, n, alpha, x, y, a);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_a, a, n*n);
}

void test_ger_cm() {
  double x[] = {1, 2, 3};
  double y[] = {4, 5, 6};
  double a[] = {29, 23, 19,
                17, 13, 11,
                7, 3, 1};
  double alpha = -1;
  double n = 3;

  double expected_a[] = {25, 15, 7,
                         12, 3, -4,
                         1, -9, -17};
  morpheus_dger(morpheus_col_major, n, n, alpha, x, y, a);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_a, a, n*n);
}

void test_ger_rm_nonsquare() {
  double x[] = {1, 2, 3, 4};
  double y[] = {5, 6, 7};
  double a[] = {41, 37, 31,
                29, 23, 19,
                17, 13, 11,
                7, 3, 1};
  double alpha = -2;
  double m = 4;
  double n = 3;

  double expected_a[] = {31, 25, 17,
                         9, -1, -9,
                         -13, -23, -31,
                         -33, -45, -55};
  morpheus_dger(morpheus_row_major, m, n, alpha, x, y, a);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_a, a, m*n);
}

void test_ger_cm_nonsquare() {
  double x[] = {1, 2, 3, 4};
  double y[] = {5, 6, 7};
  double a[] = {41, 37, 31, 29,
                23, 19, 17, 13,
                11, 7, 3, 1};
  double alpha = -2;
  double m = 4;
  double n = 3;

  double expected_a[] = {31, 17, 1, -11,
                         11, -5, -19, -35,
                         -3,-21, -39, -55};
  morpheus_dger(morpheus_col_major, m, n, alpha, x, y, a);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_a, a, m*n);
}
