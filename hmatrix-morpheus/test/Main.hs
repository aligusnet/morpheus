import Test.Framework (defaultMain, testGroup)

import qualified Numeric.LinearAlgebra.MorpheusTest as LAMorpheus

main = defaultMain tests

tests = [testGroup "LinearAlgebra.Morpheus" LAMorpheus.tests
        ]
