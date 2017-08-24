import Test.Framework (defaultMain, testGroup)

import qualified Numeric.MorpheusTest as Morpheus
import qualified Numeric.Morpheus.ActivationTest as Activation

main = defaultMain tests

tests = [ testGroup "Morpheus" Morpheus.tests
        , testGroup "Morpheus.Activation" Activation.tests
        ]
