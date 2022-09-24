while IFS= read -r line; do
    rm in_condition.c
    rm klee_output1.txt
    printf "#include<stdio.h>\n #include <stdbool.h>\n #include <stdio.h>\nint main()\n{\nint weird=0;\n" >> in_condition.c
    awk '{ print "int  " $1 ";"}' $1 >> in_condition.c
    awk '{ print "int  " $1 ";"}' $2 >> in_condition.c
    awk '{ print "klee_make_symbolic(&"$1",sizeof("$1"),\""$1"\");" }' $1 >> in_condition.c
    awk '{ print "klee_make_symbolic(&"$1",sizeof("$1"),\""$1"\");" }' $2 >> in_condition.c
    printf "klee_assume($line);\n" >> in_condition.c
    printf "freopen(\"klee_output1.txt\",\"a+\",stderr);\n" >> in_condition.c
    printf "klee_print_expr(\"weird:=\",weird);\n" >> in_condition.c
    printf "return 0;\n}\n" >> in_condition.c
    clang-10 -Wno-implicit-function-declaration -I ../../include -emit-llvm -c -g -O0 -Xclang -disable-O0-optnone in_condition.c
    klee --warnings-only-to-file --write-smt2s in_condition.bc
    python3 find_condition.py >> invarient_condition.txt
done < $3
rm -rf klee-*

# python invarient_2_smt.py $1 $2 $3 "in_condition.c"
