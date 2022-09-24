gcc -gdwarf-2 -no-pie mips_fun.c -o mips_fun
kvasir-dtrace ./mips_fun < testcases.txt
java -cp $DAIKONDIR/daikon.jar daikon.Daikon            daikon-output/mips_fun.decls daikon-output/mips_fun.dtrace  > output.txt
# python invarient_parse.py > const.txt