
#include<stdio.h>
int main()
{

	int in1;
    int in2;
    int in3;
    int in4;
    int in5;
    int in6;
    int in7;
    int in8;
    int in9;
    int in10;

    int out1;
    int out2;
    int out3;

    int mult1;
    int mult2;
    int mult3;
    int mult4;
    int mult5;
    int mult6;
    int mult7;
    int mult8;
    int mult9;
    int mult10;
    int mult11;
    int mult12;
    int mult13;
    int mult14;

    int add1;
    int add2;
    int add3;
    int add4;
    int add5;
    int add6;
    int add7;
    int add8;
    int add9;
    int add10;
    int add11;
    int add13;
    int add14;
    int add15;
    int shf1;
    int shf2;
    
   klee_make_symbolic(&in1,sizeof(in1),"in1");
   klee_make_symbolic(&in2,sizeof(in2),"in2");
   klee_make_symbolic(&in3,sizeof(in3),"in3");
   klee_make_symbolic(&in4,sizeof(in4),"in4");
   klee_make_symbolic(&in5,sizeof(in5),"in5");
   klee_make_symbolic(&in6,sizeof(in6),"in6");
   klee_make_symbolic(&in7,sizeof(in7),"in7");
   klee_make_symbolic(&in8,sizeof(in8),"in8");
   klee_make_symbolic(&in9,sizeof(in9),"in9");
   klee_make_symbolic(&in10,sizeof(in10),"in10");

  mult1 = in1 * in2;
  mult2 = in1 * in3;

  mult3 = in3 * in7;
  mult4 = in4 * in5;
  mult5 = in3 * in2;
  mult6 = in2 * in5;
  mult7 = in3 * in6;
  mult8 = in4 * in7;
  mult9 = in4 * in8;
  mult10 = in6 * in9;
  mult11 = in6 * in8;
  mult12 = in7 * in9;
  mult13 = in7 * in8;
  mult14 = in9 * in10;

  add1 = in1 * mult2;
  add2 = in4 * mult4;
  add3 = in5 * mult8;
  add4 = mult10 * in4;
  add5 = in10 * mult14;


  add6 = mult1 + add1;
   out1 = add6;

  add7 = mult3 + add2;
  add8 = mult5 + add7;

  add10 = mult7 + add3;
  add9 = mult6 + add10;

  shf1 = add9 << 3;
   out2 = add8 + shf1;

  add13 = mult9 + add4;
  add11 = add13 + mult11;

  add15 = mult13 + add5;
  add14 = mult12 + add15;

  shf2 = add14 >> 3;
   out3 = add11 + shf2;
   

   freopen("klee_output1.txt","a+",stderr);
   klee_print_expr("out1:=",out1);
   klee_print_expr("out2:=",out2);
   klee_print_expr("out3:=",out3);

   return 0;
}

