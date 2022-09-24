rm invarient_combine_code.c
touch invarient_combine_code.c
printf "#include<stdio.h>\n #include <stdbool.h>\n #include <stdio.h>\n\n" >> invarient_combine_code.c
cat define_code.txt >> invarient_combine_code.c
printf "\n\n" >> invarient_combine_code.c

awk '{print  "int " $1 ";"}' $1 >> invarient_combine_code.c
awk '{print  "int " $1 ";"}' $2 >> invarient_combine_code.c


printf "\n\nvoid fun1(){\n" >> invarient_combine_code.c
awk '{print "\tint " substr($1,1,length($1)-2)" =" $1";"}' $1 >> invarient_combine_code.c
cat sr_code_temp.txt >> invarient_combine_code.c
printf  "\n" >> invarient_combine_code.c
awk '{print "\t"$1 "=" substr($1,1,length($1)-2) ";"}' $1 >> invarient_combine_code.c
printf "}\n\n\n" >> invarient_combine_code.c

printf "void fun2(){\n" >> invarient_combine_code.c
awk '{print "\tint " substr($1,1,length($1)-2)" =" $1";"}' $2 >> invarient_combine_code.c
cat ge_code_temp.txt >> invarient_combine_code.c
printf  "\n" >> invarient_combine_code.c
awk '{print "\t"$1 "=" substr($1,1,length($1)-2) ";"}' $2 >> invarient_combine_code.c
printf "}\n\n\n" >> invarient_combine_code.c

printf "void mine(int i){\n" >> invarient_combine_code.c
printf "\tfun1();\n\tfun2();\n">> invarient_combine_code.c
#printf "\tprintf(\"%%d -- %%d == %%d \\\n\",i,t23_reg_31622,(  (  ( in322 - in422 )  + in2222 )  + t11_reg_305__temp22));\n" >> invarient_combine_code.c
printf "}\n" >> invarient_combine_code.c

printf "int main(){\n" >> invarient_combine_code.c
printf "for( int i=0;i<100;i++)\n{\n" >> invarient_combine_code.c
awk '{print "\tscanf(\"%d\",&" substr($1,1,length($1)-2) "21);"}' reintiate.txt >> invarient_combine_code.c
awk '{print "\t"substr($1,1,length($1)-2)"22="substr($1,1,length($1)-2)"21;"  }' reintiate.txt >> invarient_combine_code.c
printf "\tmine(i);\n" >> invarient_combine_code.c
printf "}\nreturn 0;\n}\n" >> invarient_combine_code.c
