#!/bin/bash

for f in $(ls ./*.huff); do 
  ./go $f | grep -E "(Average|Entropy)"; 
done
