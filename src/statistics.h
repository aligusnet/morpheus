/*! \file statistics.h
  \brief statistics functions
*/

#ifndef MORHEPUS_STATISTICS_H
#define MORHEPUS_STATISTICS_H


/*! \defgroup statistics statistics
  \brief statistics functions
  \{
*/

/*! Calculates mean (average). */
double morpheus_mean(int n, const double *x);

/*! Calculates sample standard deviation using given mean value. */
double morpheus_stddev_m(double mean, int n, const double *x);

/*! Calculates sample standard deviation.*/
double morpheus_stddev(int n, const double *x);

/*! \} */

#endif  /* MORHEPUS_STATISTICS_H */
