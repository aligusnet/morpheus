{-|
Module: Numeric.Morpheus.Statistics
Description: Statistics Functions
Copyright: (c) Alexander Ignatyev, 2017
License: BSD-3
Stability: experimental
Portability: POSIX
-}

module Numeric.Morpheus.Statistics
(
  mean
  , stddev_m
  , stddev
)

where

import Numeric.LinearAlgebra
import Numeric.LinearAlgebra.Devel
import System.IO.Unsafe(unsafePerformIO)
import Foreign.C.Types
import Foreign.Ptr(Ptr)
import Foreign.Storable

{- morpheus_mean -}
foreign import ccall unsafe "morpheus_mean"
  c_morpheus_mean :: CInt -> Ptr R -> IO R

-- | Calculates mean (average).
mean :: Vector R -> R
mean x = unsafePerformIO $ do
    apply x id c_morpheus_mean


{- morpheus_stddev_m -}
foreign import ccall unsafe "morpheus_stddev"
  c_morpheus_stddev_m :: R -> CInt -> Ptr R -> IO R

-- | Calculates sample standard deviation using given mean value.
stddev_m :: R -> Vector R -> R
stddev_m m x = unsafePerformIO $ do
    apply x id (c_morpheus_stddev_m m)


{- morpheus_stddev -}
foreign import ccall unsafe "morpheus_stddev"
  c_morpheus_stddev :: CInt -> Ptr R -> IO R

-- | Calculates sample standard deviation.
stddev :: Vector R -> R
stddev x = unsafePerformIO $ do
    apply x id c_morpheus_stddev
