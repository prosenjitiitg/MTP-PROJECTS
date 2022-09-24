#include<stdio.h>

int main(){
   int G1;
   int G2;
   int G3;
   int G4;
   int GG1;
   int GG2;
   int i1;
   int i2;
   int i3;
   int i4;
   int i5;
   int i6;
   int o1;
   int o2;
   int o3;
   int o4;

   klee_make_symbolic(&i1,sizeof(i1),"i1");
   klee_make_symbolic(&i2,sizeof(i2),"i2");
   klee_make_symbolic(&i3,sizeof(i3),"i3");
   klee_make_symbolic(&i4,sizeof(i4),"i4");
   klee_make_symbolic(&i5,sizeof(i5),"i5");
   klee_make_symbolic(&i6,sizeof(i6),"i6");
   klee_make_symbolic(&G1,sizeof(G1),"G1");
   klee_make_symbolic(&G2,sizeof(G2),"G2");
   klee_make_symbolic(&G3,sizeof(G3),"G3");
   klee_make_symbolic(&G4,sizeof(G4),"G4");
   klee_make_symbolic(&GG1,sizeof(GG1),"GG1");
   klee_make_symbolic(&GG2,sizeof(GG2),"GG2");
   klee_make_symbolic(&o1,sizeof(o1),"o1");
   klee_make_symbolic(&o2,sizeof(o2),"o2");
   klee_make_symbolic(&o3,sizeof(o3),"o3");
   klee_make_symbolic(&o4,sizeof(o4),"o4");
  int op1,op2,op3,op4,op5,op6,op7,op8;
  int op9,op10,op11,op12,op13,op14,op15,op16;
  int op17,op18,op19,op20,op21,op22,op23,op24;
  int op25,op26,op27,op28;

  op1 = GG1 * i1;
  op2 = GG2 * i2;
  op3 = G1 * i2;
  op4 = G2 * i1;
  op5 = G1 * i3;
  op6 = G2 * i4;
  op7 = G1 * i4;
  op8 = G2 * i3;

  op9 = op1 + op2;
  op10 = op3 + op4;
  op11 = op5 + op6;
  op12 = op7 + op8;

  op13 = op11 + i5;
  o1 = op13;
  op14 = i6 + op12;
  o2 = op14;
  op15 = G1 * op14;
  op16 = op13 * G2;
  op17 = op13 * G1;
  op18 = op14 * G2;
  op19 = op15 * op16;
  op20 = op17 + op18;
  op21 = G1 * op20;
  op22 = op19 * G2;
  op23 = op19 * G1;
  op24 = op20 * G2;
  op25 = op21 + op22;
  op26 = op23 + op24;
  op27 = op9 + op25;
  o3 = op27;
  op28 = op10 + op26;
  o4 = op28;


  freopen("klee_output1.txt","a+",stderr);
  klee_print_expr("o1:=", o1);
  klee_print_expr("o2:=", o2);
  klee_print_expr("o3:=", o3);
  klee_print_expr("o4:=", o4);
  return 0;
}


