#!/bin/bash
p=( $(sed -n '1 p' script.txt) )
# echo $l
# p=($l)
echo ${p[1]} 