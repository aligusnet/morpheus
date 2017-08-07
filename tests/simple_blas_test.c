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
