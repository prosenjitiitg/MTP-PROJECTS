#!/usr/bin/env bash
fo=./TestCases/test_eq
f1=./TestCases/test_eq/test1.c
f2=./TestCases/test_eq/ccode_test.c
f3=./TestCases/test_eq/cut_point.txt
f4=./script.txt
c=1
let IDX=1
let Ln_bf=0;

start (){
	echo $1
	echo $2
}







#loading cutpoint
start_iteration() {
    
    ## different file need to check every time testcase is changing
    cu1=( $(sed -n '3 p' $f3) )
    let p=($2-1)
    a=${cu1[$p]}
    cu2=( $(sed -n '4 p' $f3) )
    b=${cu2[$p]}

    ./run_daikon.sh $fo $a $b $2
    echo "IDX value is:::::::::::: $IDX"
    # cat invarient_condition.txt


    let Ln_bf=$(wc -l < invarient_condition.txt)
    rm invarient_condition.txt
    ./create_var_cond.sh "variables/var_names_int_test1_$2.txt" "variables/var_names_int_test2_$2.txt" "invarients/invarient$2.txt"
    # python3 parse.py "klee_output_combine_1.txt" "klee_output_combine_2.txt"  "test.smt" "invarient_condition.txt" $IDX

    cat "invarients/invarient$2.txt" > invarient.txt

    rm TestCase.txt
    touch TestCase.txt
    python3 check_cut.py "conditions1.txt" "outputs1.txt" "conditions2.txt" "outputs2.txt" "test.smt" "invarient_condition.txt" $IDX $Ln_bf
    let IDX=$?
    if [ $IDX -gt 0 ]
    then
        # update testcases
        { python3 insert_testcase.py ; cat testcases.txt; } > new_testcases.txt
        cat new_testcases.txt > testcases.txt
        rm new_testcases.txt
        start_iteration $1 $2
    fi
}












recheck_inv() {

	let Ln_bf=$(wc -l < recheck.txt)
	if [ $Ln_bf -eq 0 ]
    then
        echo "recheck file is empty"
        let IDX=0
        return 1
    fi

    a=$1
	b=$2

	cu1=( $(sed -n '3 p' $f3) )
    let p=($2-1)
    l1=${cu1[$p]}
    cu2=( $(sed -n '4 p' $f3) )
    l2=${cu2[$p]}


	head -$l1 $fo"/sr_code.txt" > sr_code_temp.txt
	head -$l2 $fo"/ge_code.txt" > ge_code_temp.txt
	


	rm combine_code_1.c
    rm combine_code_2.c

    touch combine_code_1.c
    touch combine_code_2.c

	python3 change_var_names.py "invarients/invarient${a%%[[:cntrl:]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]}.txt" > inv_bf.txt
    python3 write_combine_code.py "variables/var_names_int1_${a%%[[:cntrl:]}.txt" "variables/var_names_int2_${a%%[[:cntrl:]}.txt" "variables/var_names_int1_${b%%[[:cntrl:]}.txt" "variables/var_names_int2_${b%%[[:cntrl:]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]}.txt" "variables/var_names_int_test1_${b%%[[:cntrl:]}.txt" "variables/var_names_int_test2_${b%%[[:cntrl:]}.txt" inv_bf.txt 1
    python3 write_combine_code.py "variables/var_names_int1_${a%%[[:cntrl:]}.txt" "variables/var_names_int2_${a%%[[:cntrl:]}.txt" "variables/var_names_int1_${b%%[[:cntrl:]}.txt" "variables/var_names_int2_${b%%[[:cntrl:]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]}.txt" "variables/var_names_int_test1_${b%%[[:cntrl:]}.txt" "variables/var_names_int_test2_${b%%[[:cntrl:]}.txt" inv_bf.txt 2
    rm klee_output_combine_1.txt
    rm klee_output_combine_2.txt

    clang-10 -Wimplicit-function-declaration -I ../../include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone combine_code_1.c
    klee --warnings-only-to-file --write-smt2s combine_code_1.bc

    clang-10 -Wno-implicit-function-declaration -I ../../include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone combine_code_2.c
    klee --warnings-only-to-file --write-smt2s combine_code_2.bc

    # #klee_output_combine_1.txt
    # #klee_output_combine_2.txt
    python3 convert.py klee_output_combine_1.txt conditions1.txt outputs1.txt
    python3 convert.py klee_output_combine_2.txt conditions2.txt outputs2.txt

    rm -r klee-*
    rm -r klee-*

    echo "reached here----->"

    let IDX=1
    while [ $IDX -ne 0 ]
    do
    	echo "===============================>>>>>>>>>>> $IDX"
    	rm TestCase.txt
		touch TestCase.txt

    	python3 check_cut.py "conditions1.txt" "outputs1.txt" "conditions2.txt" "outputs2.txt" "test.smt" "recheck.txt" $IDX 0
    	let IDX=$?
    	if [ $IDX -gt 0 ]
	    then
	        # update testcases
	        { python3 insert_testcase.py ; cat testcases.txt; } > new_testcases.txt
	        cat new_testcases.txt > testcases.txt
	        rm new_testcases.txt
	        let IDX=($IDX+1)
	    fi
    done

    ## update the final invariants
    ./run_daikon.sh $fo $l1 $l2 $2

}





while IFS= read -r line;
do
    ar=($line)
    a=${ar[0]}
    b=${ar[1]}
    cat "codes/sr/code${c}.txt" > sr_code_temp.txt
    cat "codes/ge/code${c}.txt" > ge_code_temp.txt

    rm combine_code_1.c
    rm combine_code_2.c

    touch combine_code_1.c
    touch combine_code_2.c

    python3 change_var_names.py "invarients/invarient${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]]}.txt" > inv_bf.txt
    python3 write_combine_code.py "variables/var_names_int1_${a%%[[:cntrl:]]}.txt" "variables/var_names_int2_${a%%[[:cntrl:]]}.txt" "variables/var_names_int1_${b%%[[:cntrl:]]}.txt" "variables/var_names_int2_${b%%[[:cntrl:]]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test1_${b%%[[:cntrl:]]}.txt" "variables/var_names_int_test2_${b%%[[:cntrl:]]}.txt" inv_bf.txt 1
    python3 write_combine_code.py "variables/var_names_int1_${a%%[[:cntrl:]]}.txt" "variables/var_names_int2_${a%%[[:cntrl:]]}.txt" "variables/var_names_int1_${b%%[[:cntrl:]]}.txt" "variables/var_names_int2_${b%%[[:cntrl:]]}.txt" "variables/var_names_int_test1_${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test2_${a%%[[:cntrl:]]}.txt" "variables/var_names_int_test1_${b%%[[:cntrl:]]}.txt" "variables/var_names_int_test2_${b%%[[:cntrl:]]}.txt" inv_bf.txt 2
    rm klee_output_combine_1.txt
    rm klee_output_combine_2.txt

    clang-10 -Wno-implicit-function-declaration -I ../../include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone combine_code_1.c
    klee --warnings-only-to-file --write-smt2s combine_code_1.bc

    clang-10 -Wno-implicit-function-declaration -I ../../include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone combine_code_2.c
    klee --warnings-only-to-file --write-smt2s combine_code_2.bc

    # #klee_output_combine_1.txt
    # #klee_output_combine_2.txt
    #not working next two lines
    python3 convert.py klee_output_combine_1.txt conditions1.txt outputs1.txt
    python3 convert.py klee_output_combine_2.txt conditions2.txt outputs2.txt

    rm -r klee-*
    rm -r klee-*
    let IDX=1
    let Ln_bf=0;

    ## clearing invarient_condition.txt
    rm invarient_condition.txt
    touch invarient_condition.txt

    rm recheck.txt
    touch recheck.txt
    start_iteration $a $b
    echo "check recheck.txt file"
    a=${ar[0]}
    b=${ar[1]}
    recheck_inv $a $b
    # read stop

    if [ $IDX -ne 0 ]
    then
        echo "files are not same"
        exit
    fi

    let c++
done < $f4
echo "files are same"
