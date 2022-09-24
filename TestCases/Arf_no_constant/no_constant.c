#include<stdio.h>

int main(){

  int i1, i2, i3, i4, i6, o1, o2, o3, o4, G1, G2, G3, G4, GG1, GG2;
  klee_make_symbolic(&i1,sizeof(i1),"i1");
  klee_make_symbolic(&i2,sizeof(i2),"i2");
  klee_make_symbolic(&i3,sizeof(i3),"i3");
  klee_make_symbolic(&i4,sizeof(i4),"i4");
  klee_make_symbolic(&i6,sizeof(i6),"i6");
  klee_make_symbolic(&G1,sizeof(G1),"G1");
  klee_make_symbolic(&G2,sizeof(G2),"G2");
  klee_make_symbolic(&G3,sizeof(G3),"G3");
  klee_make_symbolic(&G4,sizeof(G4),"G4");
  klee_make_symbolic(&GG1,sizeof(GG1),"GG1");
  klee_make_symbolic(&GG2,sizeof(GG2),"GG2");
  int op1,op2,op3,op4,op5,op6,op7,op8;
  int op9,op10,op11,op12,op13,op14,op15,op16;
  int op17,op18,op19,op20,op21,op22,op23,op24;
  int op25,op26,op27,op28;

  op1 = GG1 * i1;
  op2 = GG2 * i2;
  op3 = G1 * i2;
  op4 = G2 * i1;
  if (G1 > 10)
  {
     op5 = G1 * i3;
     op5 = op5 + GG1;
     op6 = op5 - op4;
  }
  else
  {
     op5 = i3 * i4;
     op6 = op5 - op3;
  }
  if (op5 < op4)
  {
     op6 = G2 * i4;
     op6 = op6 - i3;
     op17 = op6 - G2;
  }
  else
  {
     op17 = op2 - op4;
     op2 = op4 - op17;
     op17 = op17 - op2;
  }
  op7 = G1 * i4;
  op8 = G2 * i3;

  op9 = op1 + op2;
  op10 = op3 + op4;
  op11 = op4 + op6;
  op12 = op7 + op8;

  op13 = op11 + G1;
  o1 = op13;
  op14 = i6 + op12;
  o2 = op14;
  freopen("klee_output1.txt","a+",stderr);
  klee_print_expr("o1:=", o1);
  klee_print_expr("o2:=", o2);
  
  return 0;
}


/*int main(){
	 int o11,o21,o31,o41,ap_return;
	 int *o1=&o11;
	 int *o2=&o21;
	 int *o3=&o31;
	 int *o4=&o41;
	int *ap_return1=&ap_return;
	hls_macc(1,2,3,4,5,o1,o2,o3,o4,10,11,12,13,14,15,ap_return1);	
	printf("%d\n",ap_return);
}*/
