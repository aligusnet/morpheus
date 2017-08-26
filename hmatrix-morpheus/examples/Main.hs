module Main where

import Numeric.LinearAlgebra
import Numeric.Morpheus


a = matrix 5 [
  71, 11, 3,  -9, -7,
  21, -7,  -2,  23, 11,
  -11, 32, 53, -49, 37,
  1,  -24, 78, 90, 17
  ]


main :: IO ()
main = do
  putStrLn "Numeric.Morpheus.MatrixReduce functions: "

  putStr "sum of elements of rows: "
  print $ rowSum a

  putStr "product of elements of rows: "
  print $ rowPredicate (*) a

  putStr "max values of columns: "
  print $ fst $ columnMaxIndex a

  putStr "indices of max values of columns: "
  print $ snd $ columnMaxIndex a


  putStrLn "Numeric.Morpheus.Activation functions: "

  putStrLn "\nSigmoid:"
  disp 3 (sigmoid a)

  putStrLn "ReLu:"
  disp 3 (relu a)

  putStrLn "ReLu gradient:"
  disp 3 (reluGradient a)
