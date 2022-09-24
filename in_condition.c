#include<stdio.h>
 #include <stdbool.h>
 #include <stdio.h>
int main()
{
int weird=0;
klee_assume(o4_ap_vld22 == 1);
freopen("klee_output1.txt","a+",stderr);
klee_print_expr("weird:=",weird);
return 0;
}
