/*! \file regularization.h
  \brief Regularization.
*/

#ifndef MORHEPUS_REGULARIZATION_H
#define MORHEPUS_REGULARIZATION_H

/*! \defgroup regularization regularization
  \brief regularization.
  \{
*/

/*! Regularization Type */
typedef enum {
  morpheus_reg_none,  /*!< No regularization */
  morpheus_reg_l2     /*!< L2 regularization */
} morpheus_reg_e;


/*! Regularization Params */
typedef struct {
  morpheus_reg_e type;     /*!< Regularization  type */
  double lambda;           /*!< Regularization parameter lambda */
} morpheus_reg_t;


/*! Calculates regularization for cost function */
double morpheus_cost_reg(const morpheus_reg_t *params,
                         const double num_features,
                         const double *theta);

/*! Calculates regularization for gradient function */
void morpheus_gradient_reg(const morpheus_reg_t *params,
                           const double num_features,
                           const double *theta,
                           double *reg);
/*! \} */

#endif  /* MORHEPUS_REGULARIZATION_H */
