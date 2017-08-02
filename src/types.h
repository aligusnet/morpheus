#ifndef MORHEPUS_TYPES_H
#define MORHEPUS_TYPES_H

typedef struct morpheus_data_t {
  const double *x;  /* (num_examples x num_features) matrix */
  const double *y;  /* (num_examples) vector */
  int num_features;  /* number of features including bias dimension */
  int num_examples;  /* number of examples */
} morpheus_data_t;


typedef double (*morheus_cost_f)(const morpheus_data_t *data,
                                 const double *theta,
                                 double *tmp_buffer);

#endif /* MORHEPUS_TYPES_H */
