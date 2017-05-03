#!/bin/bash
for f in $(ls ./dijk?); do 
    ./$f; 
done
