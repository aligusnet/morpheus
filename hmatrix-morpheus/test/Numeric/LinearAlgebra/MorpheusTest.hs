module Numeric.LinearAlgebra.MorpheusTest
(
  tests
)

where

import Test.Framework (testGroup)
import Test.Framework.Providers.HUnit
import Test.HUnit
import Test.HUnit.Plus

import Numeric.LinearAlgebra
import Numeric.LinearAlgebra.Morpheus


x = matrix 5 [
  71, 11, 3,  9, 7,
  21, 7,  2,  23, 11,
  11, 32, 53, 49, 37,
  1,  24, 78, 90, 17
  ]

columnSumRM = vector [104, 74, 136, 171, 72]
columnSumCM = vector [101, 64,182, 210]

rowSumRM = vector [101, 64,182, 210]
rowSumCM = vector [104, 74, 136, 171, 72]

tests = [testGroup "Column Sum" [
            testCase "row major" $ assertVector "" 1e-10 columnSumRM (columnSum x)
          , testCase "column major" $ assertVector "" 1e-10 columnSumCM (columnSum $ tr x)
          ]
        , testGroup "Row Sum" [
            testCase "row major" $ assertVector "" 1e-10 rowSumRM (rowSum x)
          , testCase "column major" $ assertVector "" 1e-10 rowSumCM (rowSum $ tr x)
          ]
        ]
