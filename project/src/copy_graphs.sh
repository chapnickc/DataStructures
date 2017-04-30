#!/bin/bash
for f in $(ls ../data/*.gph); do ./go $f done
