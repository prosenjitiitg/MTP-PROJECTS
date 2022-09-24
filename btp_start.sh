#!/usr/bin/env bash
fo=./TestCases/test_eq
f1=./TestCases/test_eq/test1.c
f2=./TestCases/test_eq/ccode_test.c
f3=./TestCases/test_eq/cut_point.txt
f4=./script.txt

cu1=( $(sed -n '1 p' $f3) )
cu2=( $(sed -n '2 p' $f3) )


let b=0
rm -r invarients
rm -r variables
mkdir invarients
mkdir variables
h=${#cu1[@]}

b=0
for ((i=0; i<$h; i++));
do
    let b++
    echo "Line from first file:  ${cu1[$i]}"
    echo "Line from second file: ${cu2[$i]}"
    python print_vars.py $f1 ${cu1[$i]} 1
    cat var_names_int1.txt
    python print_vars.py $f2 ${cu2[$i]} 2
    cat var_names_int2.txt
    cp var_names_int1.txt "variables/var_names_int1_${b}.txt"
    cp var_names_int2.txt "variables/var_names_int2_${b}.txt"
    cp var_names_int_test1.txt "variables/var_names_int_test1_${b}.txt"
    cp var_names_int_test2.txt "variables/var_names_int_test2_${b}.txt"
    echo "------------------------------------------------------------"
done

# write invarients/invarient0 , vararibles/var_names_int1_0.txt
awk '{print substr($1,1,length($1)-2)"21 == "substr($1,1,length($1)-2)"22"}' reintiate.txt > invarients/invarient0.txt
awk '{print substr($1,1,length($1)-2)"11"}' reintiate.txt > variables/var_names_int1_0.txt
awk '{print substr($1,1,length($1)-2)"12"}' reintiate.txt > variables/var_names_int2_0.txt
awk '{print substr($1,1,length($1)-2)"21"}' reintiate.txt > variables/var_names_int_test1_0.txt
awk '{print substr($1,1,length($1)-2)"22"}' reintiate.txt > variables/var_names_int_test2_0.txt
