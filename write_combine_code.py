import sys

args = sys.argv
if len(args) < 10:
	print ("Arguements not supplied")

output_txt = ""
var_names_int1_before = list()
var_names_int2_before = list()
var_names_int1 = list()
var_names_int2 = list()
var_names_int_test1_before = list()
var_names_int_test2_before = list()
var_names_int_test1 = list()
var_names_int_test2 = list()
invarient_before = list()

# extracting var_names_int1_before.txt
f = open(args[1],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int1_before.append(s)

# extracting var_names_int2_before.txt
f = open(args[2],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int2_before.append(s)


# extracting var_names_int1.txt
f = open(args[3],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int1.append(s)

# extracting var_names_int2.txt
f = open(args[4],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int2.append(s)

# extracting var_names_int__test1_before.txt
f = open(args[5],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int_test1_before.append(s)

# extracting var_names_int_test2_before.txt
f = open(args[6],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int_test2_before.append(s)


# extracting var_names_int_test1.txt
f = open(args[7],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int_test1.append(s)

# extracting var_names_int_test2.txt
f = open(args[8],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    var_names_int_test2.append(s)

# extracting invarient_before.txt
f = open(args[9],"r")
f1 = f.readlines()
f.close()
for s in f1:
    s = s.replace(" \n","")
    s = s.replace("\n","")
    invarient_before.append(s)


# extracting the values
pr = int(args[10])


# any define code
f = open("define_code.txt","r")
f1 = f.readlines()
f.close()

define_txt=""
for s in f1:
    define_txt = define_txt + s

# #include
output_txt += "#include<stdio.h>\n #include <stdbool.h>\n #include <stdio.h>\n\n"
#add define codes
output_txt += define_txt


# int x
for var in var_names_int1:
    output_txt += "int "+var+";\n"
for var in var_names_int2:
    output_txt += "int "+var+";\n"

# fun1
output_txt += "\n\nvoid fun1(){\n"
for var in var_names_int1:
    output_txt += "\tint "+var[:-2]+" ="+var+";\n"
f = open("sr_code_temp.txt","r")
f1 = f.readlines()
f.close()
for s in f1:
    output_txt += "\t"+s
for var in var_names_int1:
    output_txt += "\t"+var+"="+var[:-2]+";\n"
output_txt += "\n}\n\n\n"


# fun2
output_txt += "\n\nvoid fun2(){\n"
for var in var_names_int2:
    output_txt += "\tint "+var[:-2]+" ="+var+";\n"
f = open("ge_code_temp.txt","r")
f1 = f.readlines()
f.close()
for s in f1:
    output_txt += "\t"+s
for var in var_names_int2:
    output_txt += "\t"+var+" ="+var[:-2]+";\n"
output_txt += "\n}\n\n\n"

# int main()
output_txt += "int main(){\n"
for var in var_names_int1_before:
    output_txt += "\tklee_make_symbolic(&"+ var +",sizeof("+ var +"),\""+ var +"\");\n"

for var in var_names_int2_before:
    output_txt += "\tklee_make_symbolic(&"+ var +",sizeof("+ var +"),\""+ var +"\");\n"

for condition in invarient_before:

    output_txt += "\tklee_assume("+ condition +");\n"


if(pr == 1):
    output_txt += "\tfun1();\n"
    output_txt += "\tfreopen(\"klee_output_combine_1.txt\",\"a+\",stderr);\n"

    for var in var_names_int1:
        output_txt += "\tklee_print_expr(\""+var[:-2]+"21:=\","+var+");\n"

    output_txt += "return 0;\n}\n"

    f = open("combine_code_1.c","w")
    f.write(output_txt)
    f.close()

    #test.smt
    test_txt = ""

    for var in var_names_int1:
        test_txt = test_txt + "(declare-fun "+var+" () (Array (_ BitVec 32) (_ BitVec 8) ) )\n"

    for var in var_names_int2:
        test_txt = test_txt + "(declare-fun "+var+" () (Array (_ BitVec 32) (_ BitVec 8) ) )\n"

    for var in var_names_int_test1:
        test_txt = test_txt + "(declare-fun "+var+" () (Array (_ BitVec 32) (_ BitVec 8) ) )\n"

    for var in var_names_int_test2:
        test_txt = test_txt + "(declare-fun "+var+" () (Array (_ BitVec 32) (_ BitVec 8) ) )\n"

    f = open("test.smt","w")
    f.write(test_txt)
    f.close()
else:
    output_txt += "\tfun2();\n"
    output_txt += "\tfreopen(\"klee_output_combine_2.txt\",\"a+\",stderr);\n"

    for var in var_names_int2:
        output_txt += "\tklee_print_expr(\""+var[:-2]+"22:=\","+var+");\n"

    output_txt += "return 0;\n}\n"

    f = open("combine_code_2.c","w")
    f.write(output_txt)
    f.close()
