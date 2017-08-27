module Numeric.Morpheus.StatisticsTest
(
  tests
)

where

import Test.Framework (testGroup)
import Test.Framework.Providers.HUnit
import Test.HUnit
import Test.HUnit.Approx
import Test.HUnit.Plus

import Numeric.LinearAlgebra
import Numeric.Morpheus.Statistics


x = fromList [35,32,213,54,81,92,63,70]
meanValue = 80
stddevValue = 57.60456

tests = [ testGroup "Statistics" [
            testCase "mean" $ assertApproxEqual "" 1e-5 meanValue (mean x)
          , testCase "stddev_m" $ assertApproxEqual "" 1e-5 stddevValue (stddev_m meanValue x)
          , testCase "stddev" $ assertApproxEqual "" 1e-5 stddevValue (stddev x)
          ]
        ]
