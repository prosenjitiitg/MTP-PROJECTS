#  1 = cut point line number of orignal_code file 
#  2 = cut point line number of ge_code file
#  3 = cut point number
fo=$1
head -$2 $fo"/sr_code.txt" > sr_code_temp.txt
head -$3 $fo"/ge_code.txt" > ge_code_temp.txt
# cat sr_code_temp.txt

./write_invarient_combine_codes.sh "variables/var_names_int_test1_$4.txt" "variables/var_names_int_test2_$4.txt"

# cat invarient_combine_code.c
# exit
# generate invarient
gcc -gdwarf-2 -no-pie invarient_combine_code.c -o invarient_combine_code
kvasir-dtrace ./invarient_combine_code < testcases.txt
java -cp $DAIKONDIR/daikon.jar daikon.Daikon      --config_option daikon.derive.Derivation.disable_derived_variables=true      daikon-output/invarient_combine_code.decls daikon-output/invarient_combine_code.dtrace  > output.txt
python3 invarient_parse.py > const.txt

cp const.txt "invarients/invarient$4.txt"
