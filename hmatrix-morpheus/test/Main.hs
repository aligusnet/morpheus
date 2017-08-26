import Test.Framework (defaultMain, testGroup)

import qualified Numeric.Morpheus.MatrixReduceTest as MatrixReduce
import qualified Numeric.Morpheus.ActivationTest as Activation

main = defaultMain tests

tests = [ testGroup "Morpheus.MatrixReduce" MatrixReduce.tests
        , testGroup "Morpheus.Activation" Activation.tests
        ]
