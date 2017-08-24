module Numeric.Morpheus.ActivationTest
(
  tests
)

where

import Test.Framework (testGroup)
import Test.Framework.Providers.HUnit
import Test.HUnit
import Test.HUnit.Plus

import Numeric.LinearAlgebra
import Numeric.Morpheus.Activation


x = row [10e10, 0, -10e10]
x_sigmoid = row [1, 0.5, 0]
x_sigmoid_gradient = row [0, 0.25, 0]


tests = [ testGroup "Sigmoid" [
            testCase "Sigmoid" $ assertMatrix "" 1e-10 x_sigmoid (sigmoid x)
            , testCase "Sigmoid Gradient" $ assertMatrix "" 1e-10 x_sigmoid_gradient (sigmoidGradient x)
            ]
        ]
