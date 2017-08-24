import Test.Framework (defaultMain, testGroup)

import qualified Numeric.MorpheusTest as Morpheus

main = defaultMain tests

tests = [testGroup "Morpheus" Morpheus.tests
        ]
