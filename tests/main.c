#include <Unity/unity.h>

extern void test_least_squares();
extern void test_numeric_gradient();
extern void test_gradient_descent();
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
