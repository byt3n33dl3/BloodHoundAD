#!/bin/bash

# $RANDOM is an internal Bash function (not a constant) that returns a
# pseudorandom integer in the range 0 - 32767. It should not be used to
# generate an encryption key.
# Taken from the documentation

# Create array with nucleobases
nucleobases[0]="A"
nucleobases[1]="C"
nucleobases[2]="G"
nucleobases[3]="T"

result_genome=""

for in in {1..500}
do
  for j in {1..100}
  do
     # Randomly choose an index between 0 and 3 from nucleobases
     # and append the nucleobase to the result_genome string
     result_genome+=${nucleobases[((RANDOM%4))]}
  done
  # add a newline after 100 characters
  result_genome+=$'\n'
done

echo "$result_genome"
