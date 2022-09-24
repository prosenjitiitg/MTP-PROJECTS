#include<stdio.h>
int main()
{
    int in11,in21,in31,in41,in51,in61,in71,in81,in91;
    int in12,in22,in32,in42,in52,in62,in72,in82,in92;

    klee_make_symbolic(&in11,sizeof(in11),"in11");
    klee_make_symbolic(&in21,sizeof(in21),"in21");
    klee_make_symbolic(&in31,sizeof(in31),"in31");
    klee_make_symbolic(&in41,sizeof(in41),"in41");
    klee_make_symbolic(&in51,sizeof(in51),"in51");
    klee_make_symbolic(&in61,sizeof(in61),"in61");
    klee_make_symbolic(&in71,sizeof(in71),"in71");
    klee_make_symbolic(&in81,sizeof(in81),"in81");
    klee_make_symbolic(&in91,sizeof(in91),"in91");
    klee_make_symbolic(&in12,sizeof(in12),"in12");
    klee_make_symbolic(&in22,sizeof(in22),"in22");
    klee_make_symbolic(&in32,sizeof(in32),"in32");
    klee_make_symbolic(&in42,sizeof(in42),"in42");
    klee_make_symbolic(&in52,sizeof(in52),"in52");
    klee_make_symbolic(&in62,sizeof(in62),"in62");
    klee_make_symbolic(&in72,sizeof(in72),"in72");
    klee_make_symbolic(&in82,sizeof(in82),"in82");
    klee_make_symbolic(&in92,sizeof(in92),"in92");

    int a[3][3];
    int b[3][3];
    int res[3][3];

    int i,j;
    int a1[3][3];

    int b1[3][3];

    int res1[3][3];



    a[0][0] = in11;
    a[0][1] = in21;
    a[0][2] = in31;
    a[1][0] = in41;
    a[1][1] = in51;
    a[1][2] = in61;
    a[2][0] = in71;
    a[2][1] = in81;
    a[2][2] = in91;


    b[0][0] = in12;
    b[0][1] = in22;
    b[0][2] = in32;
    b[1][0] = in42;
    b[1][1] = in52;
    b[1][2] = in62;
    b[2][0] = in72;
    b[2][1] = in82;
    b[2][2] = in92;




 for(i = 0; i < 3; i++) {
       for(j = 0; j < 3; j++) {
        a1[i][j] = a[i][j];
      }
    }

 for(i = 0; i < 3; i++) {
       for(j = 0; j < 3; j++) {
        b1[i][j] = b[i][j];
      }
    }

   for(i = 0; i < 3; i++) {
       for(j = 0; j < 3; j++) {
        res1[i][j] = a1[i][j] + b1[i][j];
      }
    }

  for(i = 0; i < 3; i++) {
      //Iterate over the columns of the B matrix
       for(j = 0; j < 3; j++) {

           res[i][j] = res1[i][j];
         }
      }

}