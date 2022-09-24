#include<stdio.h>

int main()
{

	int p,q,r,s,z,a,b,c,d;
	int op1,op2,op3;

	int x,y;

	klee_make_symbolic(&x,sizeof(x),"x");
	klee_make_symbolic(&y,sizeof(y),"y");

	p=0;
	q=0;
	r=0;
	s=0;
	z=0;
	a=x;
	b=y;
	c=0;
	d=1;
	op1=0;
	op2=0;
	op3=0;

	for(int i=0;i<16;i++)
	{
		op1 = a+d;
		a=c+b;
		c=d;
		d=2*c;
		p += x+y+1;
	}


	if(d<x*y)
	{
		op2 = p-d;
		op3 = (p*3)-d;
	}
	else
	{
		op2 = d-2*p;
		op3 = (3*d)-p;

	}



	if(op1<op2)
	{
		if(op2<op3)
		{
			z= op1+op2;
		}
		else
		{
			z = op1+op3;
		}
	}
	else
	{
		if(op1<op3)
		{
			z= op2+op1;
		}
		else
		{
			z=op2+op3;
		}
	}

	freopen("klee_output1.txt","a+",stderr);
	klee_print_expr("return_port:=",z);
	
	return z;

}



