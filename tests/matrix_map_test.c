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

void test_column_max_index() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];
  int is[5];

  double expected_y_row_major[] = {71, 32, 78, 90, 37};
  int expected_is_row_major[] = {0, 2, 3, 3, 2};
  morpheus_column_max_index(morpheus_row_major, 4, 5, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_row_major, y, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_is_row_major, is, 5);

  double expected_y_col_major[] = {71, 23, 53, 90};
  int expected_is_col_major[] = {0, 3, 2, 3};
  morpheus_column_max_index(morpheus_col_major, 5, 4, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_col_major, y, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_is_col_major, is, 4);
}

void test_column_min_index() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];
  int is[5];

  double expected_y_row_major[] = {1, 7, 2, 9, 7};
  int expected_is_row_major[] = {3, 1, 1, 0, 0};
  morpheus_column_min_index(morpheus_row_major, 4, 5, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_row_major, y, 5);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_is_row_major, is, 5);

  double expected_y_col_major[] = {3, 2, 11, 1};
  int expected_is_col_major[] = {2, 2, 0, 0};
  morpheus_column_min_index(morpheus_col_major, 5, 4, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_col_major, y, 4);
  TEST_ASSERT_EQUAL_INT_ARRAY(expected_is_col_major, is, 4);
}

void test_row_max_index() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];
  int is[5];

  double expected_y_row_major[] = {71, 23, 53, 90};
  int expected_is_row_major[] = {0, 3, 2, 3};
  morpheus_row_max_index(morpheus_row_major, 4, 5, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_row_major, y, 4);

  double expected_y_col_major[] = {71, 32, 78, 90, 37};
  int expected_is_col_major[] = {0, 2, 3, 3, 2};
  morpheus_row_max_index(morpheus_col_major, 5, 4, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_col_major, y, 5);
}

void test_row_min_index() {
  double x[] = {
    71, 11, 3,  9, 7,
    21, 7,  2,  23, 11,
    11, 32, 53, 49, 37,
    1,  24, 78, 90, 17
  };

  double y[5];
  int is[5];

  double expected_y_row_major[] = {3, 2, 11, 1};
  int expected_is_row_major[] = {2, 2, 0, 0};
  morpheus_row_min_index(morpheus_row_major, 4, 5, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_row_major, y, 4);

  double expected_y_col_major[] = {1, 7, 2, 9, 7};
  int expected_is_col_major[] = {3, 1, 1, 0, 0};
  morpheus_row_min_index(morpheus_col_major, 5, 4, x, y, is);
  TEST_ASSERT_EQUAL_DOUBLE_ARRAY(expected_y_col_major, y, 5);
}
