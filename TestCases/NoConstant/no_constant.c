#include<stdio.h>

int main(){

  int i1, i2, i3, i4, i6, o1, o2, o3, o4, G1, G2, G3, G4, GG1, GG2;


   scanf(  "%d",&i1);
   scanf(  "%d",&i2);
   scanf(  "%d",&i3);
   scanf(  "%d",&i4);
   scanf(  "%d",&i6);
   scanf(  "%d",&G1);
   scanf(  "%d",&G2);
   scanf(  "%d",&G3);
   scanf(  "%d",&G4);
   scanf(  "%d",&GG1);
   scanf(  "%d",&GG2);

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
     op5 = G1 + i3;
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

  op13 = op11 + G1;  //(  (  (  ( tmp_6_reg_267__temp  & 1 )  == 1 ?  ( op6_3_reg_277__temp  - i3 )  :   (  ( tmp_reg_257__temp  & 1 )  == 1 ?  ( op5_1_reg_262__temp  - op4_reg_239__temp  )  :   ( op5_2_reg_251__temp  - op3_reg_272__temp  )  )  )  + G1 )  + op4_reg_239__temp  )
  o1 = op13;
  op14 = i6 + op12;
  o2 = op14;
  //cut2

  return 0;
}
// 31  * --> +
// G2*i1 + G1+i3+GG1-op4 + G1