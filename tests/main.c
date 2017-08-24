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
extern void test_wolfe();

// simple_blas_test
extern void test_inverse();
extern void test_ger_rm();
extern void test_ger_cm();
extern void test_ger_rm_nonsquare();
extern void test_ger_cm_nonsquare();
extern void test_gemm_rm_notransp();
extern void test_gemm_cm_notransp();
extern void test_gemm_rm_transp();
extern void test_gemm_cm_transp();
extern void test_gemv_rm_notransp();
extern void test_gemv_cm_notransp();
extern void test_gemv_rm_transp();
extern void test_gemv_cm_transp();
extern void test_dcopy();
extern void test_dcopy_scalar();
extern void test_dnrm2();
extern void test_ddot();
extern void test_dscal();
extern void test_daxpy();
extern void test_identity();

// activation
extern void test_sigmoid();
extern void test_sigmoid_gradient();

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
  RUN_TEST(test_wolfe);

  // simple_blas_test
  RUN_TEST(test_inverse);
  RUN_TEST(test_ger_rm);
  RUN_TEST(test_ger_cm);
  RUN_TEST(test_ger_rm_nonsquare);
  RUN_TEST(test_ger_cm_nonsquare);
  RUN_TEST(test_gemm_rm_notransp);
  RUN_TEST(test_gemm_cm_notransp);
  RUN_TEST(test_gemm_rm_transp);
  RUN_TEST(test_gemm_cm_transp);
  RUN_TEST(test_gemv_rm_notransp);
  RUN_TEST(test_gemv_cm_notransp);
  RUN_TEST(test_gemv_rm_transp);
  RUN_TEST(test_gemv_cm_transp);
  RUN_TEST(test_dcopy);
  RUN_TEST(test_dcopy_scalar);
  RUN_TEST(test_ddot);
  RUN_TEST(test_dnrm2);
  RUN_TEST(test_dscal);
  RUN_TEST(test_daxpy);
  RUN_TEST(test_identity);

  // activation
  RUN_TEST(test_sigmoid);
  RUN_TEST(test_sigmoid_gradient);

  return (UnityEnd());
}
