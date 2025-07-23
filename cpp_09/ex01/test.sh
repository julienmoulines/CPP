#!/bin/bash

TESTS=(
  '3 4 +'
  '10 2 /'
  '8 9 * 9 -'
  '7 7 * 7 -'
  '1 2 + 4 * 5 +'
  '2 3 + 5 *'
  '5 1 2 + 4 * + 3 -'
  '6 2 * 3 / 1 +'
  '1 +'
  '1 2 + +'
  '1 0 /'
  'a b +'
  '1 2 3 +'
  '8 4 2 *'
  '4 *'
)

echo "==== BATTERIE DE TEST RPN ===="

for expr in "${TESTS[@]}"; do
  echo -n "./RPN \"$expr\" ➜  "
  ./RPN "$expr"
done
