#include<stdio.h>
#include <stdbool.h>
#include <stdio.h>
//#include "../../../../klee/include/klee/klee.h"

int main(){

	int in1, in2, in3, in4, in7, in8, in9, in10, in14, in12, in15, in17, in19, in20, in22, in24, in27, in28, in29, in32, out13, out30, out31;
	int t5, t6, t11, t16, t18, t21, t23, t25, t26;
	int return_port;

	scanf(  "%d",&in1);
  	scanf(  "%d",&in2);
	scanf(  "%d",&in3);
	scanf(  "%d",&in4);
	scanf(  "%d",&in7);
	scanf(  "%d",&in8);
	scanf(  "%d",&in9);
	scanf(  "%d",&in12);
	scanf(  "%d",&in10);
	scanf(  "%d",&in14);
	scanf(  "%d",&in15);
	scanf(  "%d",&in17);
	scanf(  "%d",&in19);
	scanf(  "%d",&in20);
	scanf(  "%d",&in22);
	scanf(  "%d",&in24);
	scanf(  "%d",&in27);
	scanf(  "%d",&in28);
	scanf(  "%d",&in29);
	scanf(  "%d",&in32);

	out30 = 0;
	t5 = in3 - in4;
	t6 = in7 + in8;
	out13 = in14 - in15;
	t11 = t6 + in12;
	//cut 1
	if (in2 == in1)
		t16 = t11 - in17;
	else
	{
		t18 = in19 + in20;
		if (in9 < in10)
		{
		t21 = t11 + in22;
		t23 = t5 - in24;
		t25 = t21 + t23;
		t26 = t25 + in27;
		}
		else
		t26 = t5 + t18;
		t16 = t26 - in28;
		out30 = t26 + in29;
	}
	out31 = t16 + in32;
	return_port = out13 + out30 + out31;

	//cut 2
	return out13 + out30 + out31;
}