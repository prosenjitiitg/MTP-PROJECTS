#include<stdlib.h>

int main(){
  int in1, in2, in3, in4, in5, in6;

  scanf("%d",in1);
  scanf("%d",in2);
  scanf("%d",in3);
  scanf("%d",in4);
  scanf("%d",in5);
  scanf("%d",in6);

  int out1;
  int t1, t2, t3, t4, t5, t6, t7;
 
 t1 = in5 - in6;
 t2 = in2 + in3;
 if (in5 != 0) 
  {
   if (t2 != 0) 
    {
     t3 = in1 - 4;
     if (t3 != 0) 
       t4 = in2 + 4;
     else 
       t4 = in3 - in5;
    } else {
     t3 = in4 - 5;
     t5 = t3+5;
     if (t5 != 0) 
       t6 = in1+in2;
     else {
      t7 = in1 - in2;
      t6 = t7 - in1;
     }
     t4 = t6 - in4;
    }
   t6 = t4+in4;
  } else {
   if (t1 != 0) 
     t6 = in2 + 5;
   else 
     t6 = 8 - in4;
  }
 if (t6 != 0) 
   out1 = in1 - 5;
 else 
   out1 = 8 + in5;

    return 0;
}

