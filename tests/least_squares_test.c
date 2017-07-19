#include "../src/least_squares.h"

#include <stdio.h>

int main (int argc, char **argv) {
  double X[] = {
    1, 3,
    1, 5,
    1, 10,
    1, 0,
    1, 4
  };

  double y[] = {
    9,
    13,
    23,
    3,
    11
  };

  double theta[] = {
    3,
    2
  };

  double X_to_predict[] = {
    1, 7,
    1, 9
  };

  double tmp_buffer[2*5];

  double prediction[2];

  printf("Least Squares Test\n------------------\n");
  ls_hypothesis(X_to_predict, theta, 2, 2, prediction);
  printf("Prediction: %5.2f, %5.2f, expected: 17.00, 21.00\n",
        prediction[0], prediction[1]);

  double v = ls_cost(X, y, theta, 5, 2, tmp_buffer);
  printf("Cost function: %5.2f, expected: 0.00\n", v);

  double grad[2];
  ls_gradient(X, y, theta, 5, 2, grad, tmp_buffer);
  printf("Gradient: %5.2f, %5.2f, expected: 0.00, 0.00\n",
         grad[0], grad[1]);
  return 0;
}
