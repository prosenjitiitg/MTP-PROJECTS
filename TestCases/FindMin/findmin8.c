#include <stdio.h>

int main(){
 	  int a1, a2, a3, a4, a5, a6, a7, a8;
 	  int a12, a34, a56, a78;
 	  int a14, a58;
 	  int a18;
   	  klee_make_symbolic(&a1,sizeof(a1),"a1");
   	  klee_make_symbolic(&a2,sizeof(a2),"a2");
   	  klee_make_symbolic(&a3,sizeof(a3),"a3");
   	  klee_make_symbolic(&a4,sizeof(a4),"a4");
   	  klee_make_symbolic(&a5,sizeof(a5),"a5");
   	  klee_make_symbolic(&a6,sizeof(a6),"a6");
   	  klee_make_symbolic(&a7,sizeof(a7),"a7");
   	  klee_make_symbolic(&a8,sizeof(a8),"a8");
 	   	  
 	  
 	  if(a1<a2) a12 = a1;
 	  else a12 = a2;
 	  
 	  if(a3<a4) a34 = a3;
 	  else a34= a4;
 	  
 	  if(a5<a6) a56 = a5;
 	  else a56 = a6;
 	  
 	  if(a7<a8) a78 = a7;
 	  else a78 = a8;
 	  
 	  if(a12<a34) a14 = a12;
 	  else a14 = a34;

 	  if(a56<a78) a58 = a56;
 	  else a58 = a78;
 	  
 	  if(a14<a58) a18 = a14;
 	  else a18 = a58;
 	  
 	  freopen("klee_output1.txt","a+",stderr);
	  klee_print_expr("a18:=", a18);
 	  //printf("%d\n",a18);
	  return a18;
}

