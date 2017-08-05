#include "../src/matrix_map.h"

#include <Unity/unity.h>

#include <math.h>

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


void test_column_min() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];

  double expected_row_major[] = {1, 7, 2, 9, 7};
  morpheus_column_min(morpheus_row_major, 4, 5, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_row_major, y, 5);

  double expected_col_major[] = {3, 2, 11, 1};
  morpheus_column_min(morpheus_col_major, 5, 4, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_col_major, y, 4);
}

void test_column_pred() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];

  double expected_row_major[] = {1, 7, 2, 9, 7};
  morpheus_column_predicate(fmin, morpheus_row_major, 4, 5, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_row_major, y, 5);

  double expected_col_major[] = {3, 2, 11, 1};
  morpheus_column_predicate(fmin, morpheus_col_major, 5, 4, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_col_major, y, 4);
}

void test_row_pred() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];

  double expected_row_major[] = {71, 23, 53, 90};
  morpheus_row_predicate(fmax, morpheus_row_major, 4, 5, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_row_major, y, 4);

  double expected_col_major[] = {71, 32, 78, 90, 37};
  morpheus_row_predicate(fmax, morpheus_col_major, 5, 4, x, y);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_col_major, y, 5);
}
