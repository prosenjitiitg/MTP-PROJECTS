#include<stdio.h>
#include <stdbool.h>
#include <stdio.h>


int main(){

  int ap_clk=1;
  int ap_done=0;
  int ap_idle=0;
  int ap_ready=1;
  int ap_return=0;
  int ap_rst=1;
  int ap_start=1;
  int in1;
  int in10;
  int in12;
  int in14;
  int in15;
  int in17;
  int in19;
  int in2;
  int in20;
  int in22;
  int in24;
  int in27;
  int in28;
  int in29;
  int in3;
  int in32;
  int in4;
  int in7;
  int in8;
  int in9;
  int out13;
  int out30;
  int out31;


  klee_make_symbolic(&in1,sizeof(in1),"in1");
  klee_make_symbolic(&in2,sizeof(in2),"in2");
  klee_make_symbolic(&in3,sizeof(in3),"in3");
  klee_make_symbolic(&in4,sizeof(in4),"in4");
  klee_make_symbolic(&in7,sizeof(in7),"in7");
  klee_make_symbolic(&in8,sizeof(in8),"in8");
  klee_make_symbolic(&in9,sizeof(in9),"in9");
  klee_make_symbolic(&in10,sizeof(in10),"in10");
  klee_make_symbolic(&in14,sizeof(in14),"in14");
  klee_make_symbolic(&in15,sizeof(in15),"in15");
  klee_make_symbolic(&in12,sizeof(in12),"in12");
  klee_make_symbolic(&in17,sizeof(in17),"in17");
  klee_make_symbolic(&in19,sizeof(in19),"in19");
  klee_make_symbolic(&in20,sizeof(in20),"in20");
  klee_make_symbolic(&in22,sizeof(in22),"in22");
  klee_make_symbolic(&in24,sizeof(in24),"in24");
  klee_make_symbolic(&in27,sizeof(in27),"in27");
  klee_make_symbolic(&in28,sizeof(in28),"in28");
  klee_make_symbolic(&in29,sizeof(in29),"in29");
  klee_make_symbolic(&in32,sizeof(in32),"in32");


  int ap_CS_fsm=1;
  int ap_CS_fsm__temp=1;
  int ap_CS_fsm_state1=1;
  int ap_CS_fsm_state1__temp=1;
  int ap_CS_fsm_state2=1;
  int ap_CS_fsm_state2__temp=1;
  int ap_CS_fsm_state3=1;
  int ap_CS_fsm_state3__temp=1;
  int ap_CS_fsm_state4=1;
  int ap_CS_fsm_state4__temp=1;
  int ap_NS_fsm=0;
  int ap_NS_fsm__temp=0;
  int ap_clk__temp=0;
  int ap_rst__temp=0;
  int ap_start__temp=0;
  int in10__temp=0;
  int in12__temp=0;
  int in14__temp=0;
  int in15__temp=0;
  int in17__temp=0;
  int in19__temp=0;
  int in1__temp=0;
  int in20__temp=0;
  int in22__temp=0;
  int in24__temp=0;
  int in27__temp=0;
  int in28__temp=0;
  int in29__temp=0;
  int in2__temp=0;
  int in32__temp=0;
  int in3__temp=0;
  int in4__temp=0;
  int in7__temp=0;
  int in8__temp=0;
  int in9__temp=0;
  int out13__temp=0;
  int out13_assign_fu_281_p2=0;
  int out13_assign_fu_281_p2__temp=0;
  int out30__temp=0;
  int out30_assign_1_fu_270_p3=0;
  int out30_assign_1_fu_270_p3__temp=0;
  int out30_assign_fu_264_p2=0;
  int out30_assign_fu_264_p2__temp=0;
  int out30_assign_reg_337=0;
  int out30_assign_reg_337__temp=0;
  int out31__temp=0;
  int t11_fu_188_p2=0;
  int t11_fu_188_p2__temp=0;
  int t11_reg_305=0;
  int t11_reg_305__temp=0;
  int t16_1_fu_258_p2=0;
  int t16_1_fu_258_p2__temp=0;
  int t16_1_reg_332=0;
  int t16_1_reg_332__temp=0;
  int t16_2_fu_276_p3=0;
  int t16_2_fu_276_p3__temp=0;
  int t16_fu_217_p2=0;
  int t16_fu_217_p2__temp=0;
  int t16_reg_327=0;
  int t16_reg_327__temp=0;
  int t23_fu_206_p2=0;
  int t23_fu_206_p2__temp=0;
  int t23_reg_316=0;
  int t23_reg_316__temp=0;
  int t25_fu_228_p2=0;
  int t25_fu_228_p2__temp=0;
  int t26_1_fu_245_p2=0;
  int t26_1_fu_245_p2__temp=0;
  int t26_2_fu_250_p3=0;
  int t26_2_fu_250_p3__temp=0;
  int t26_fu_233_p2=0;
  int t26_fu_233_p2__temp=0;
  int t5_fu_194_p2=0;
  int t5_fu_194_p2__temp=0;
  int t5_reg_311=0;
  int t5_reg_311__temp=0;
  int tmp1_fu_182_p2=0;
  int tmp1_fu_182_p2__temp=0;
  int tmp2_fu_200_p2=0;
  int tmp2_fu_200_p2__temp=0;
  int tmp3_fu_239_p2=0;
  int tmp3_fu_239_p2__temp=0;
  int tmp4_fu_287_p2=0;
  int tmp4_fu_287_p2__temp=0;
  int tmp5_fu_293_p2=0;
  int tmp5_fu_293_p2__temp=0;
  int tmp_2_fu_222_p2=0;
  int tmp_2_fu_222_p2__temp=0;
  int tmp_2_fu_222_p2_temp=0;
  int tmp_2_fu_222_p2_temp__temp=0;
  int tmp_fu_211_p2=0;
  int tmp_fu_211_p2__temp=0;
  int tmp_reg_321=0;
  int tmp_reg_321__temp=0;
  int tmp_reg_321_temp=0;
  int tmp_reg_321_temp__temp=0;

  ap_ST_fsm_state1:
   
  ap_CS_fsm_state1 = 1;
  ap_CS_fsm_state2 = 0;
  ap_CS_fsm_state3 = 0;
  ap_CS_fsm_state4 = 0;
  t11_fu_188_p2__temp = t11_fu_188_p2 ;
  tmp2_fu_200_p2__temp = tmp2_fu_200_p2 ;
  out13_assign_fu_281_p2__temp = out13_assign_fu_281_p2 ;
  t16_reg_327__temp = t16_reg_327 ;
  out30_assign_reg_337__temp = out30_assign_reg_337 ;
  t16_2_fu_276_p3__temp = t16_2_fu_276_p3 ;
  t25_fu_228_p2__temp = t25_fu_228_p2 ;
  t26_2_fu_250_p3__temp = t26_2_fu_250_p3 ;
  tmp_reg_321__temp = tmp_reg_321 ;
  t23_fu_206_p2__temp = t23_fu_206_p2 ;
  tmp4_fu_287_p2__temp = tmp4_fu_287_p2 ;
  ap_CS_fsm_state3__temp = ap_CS_fsm_state3 ;
  ap_NS_fsm__temp = ap_NS_fsm ;
  tmp5_fu_293_p2__temp = tmp5_fu_293_p2 ;
  t11_reg_305__temp = t11_reg_305 ;
  tmp1_fu_182_p2__temp = tmp1_fu_182_p2 ;
  t16_fu_217_p2__temp = t16_fu_217_p2 ;
  t5_fu_194_p2__temp = t5_fu_194_p2 ;
  ap_CS_fsm_state2__temp = ap_CS_fsm_state2 ;
  out30_assign_1_fu_270_p3__temp = out30_assign_1_fu_270_p3 ;
  t16_1_fu_258_p2__temp = t16_1_fu_258_p2 ;
  t5_reg_311__temp = t5_reg_311 ;
  t16_1_reg_332__temp = t16_1_reg_332 ;
  ap_CS_fsm_state4__temp = ap_CS_fsm_state4 ;
  tmp_reg_321_temp__temp = tmp_reg_321_temp ;
  tmp_2_fu_222_p2_temp__temp = tmp_2_fu_222_p2_temp ;
  t26_fu_233_p2__temp = t26_fu_233_p2 ;
  t23_reg_316__temp = t23_reg_316 ;
  tmp3_fu_239_p2__temp = tmp3_fu_239_p2 ;
  tmp_fu_211_p2__temp = tmp_fu_211_p2 ;
  ap_CS_fsm__temp = ap_CS_fsm ;
  out30_assign_fu_264_p2__temp = out30_assign_fu_264_p2 ;
  ap_CS_fsm_state1__temp = ap_CS_fsm_state1 ;
  tmp_2_fu_222_p2__temp = tmp_2_fu_222_p2 ;
  t26_1_fu_245_p2__temp = t26_1_fu_245_p2 ;

  if(((ap_start == 1) && (1 == ap_CS_fsm_state1)) == 1){
     if((ap_start == 1) && (1 == ap_CS_fsm_state1))
     {
         t11_reg_305 =   (  ( in7 + in12 )  + in8 ) ;
     }
     if((ap_start == 0) && (1 == ap_CS_fsm_state1))
     {
         ap_idle =  1;
     }
     goto ap_ST_fsm_state2;
  }
  if(((ap_start == 1) && (1 == ap_CS_fsm_state1)) == 0){
     if((ap_start == 1) && (1 == ap_CS_fsm_state1))
     {
             t11_reg_305 =   (  ( in7 + in12 )  + in8 ) ;
     }
     if((ap_start == 0) && (1 == ap_CS_fsm_state1))
     {
             ap_idle =  1;
     }
     goto ap_ST_fsm_state1;
  }

  ap_ST_fsm_state2:
  ap_CS_fsm_state1 = 0;
  ap_CS_fsm_state2 = 1;
  ap_CS_fsm_state3 = 0;
  ap_CS_fsm_state4 = 0;
   t11_fu_188_p2__temp = t11_fu_188_p2 ;
   tmp2_fu_200_p2__temp = tmp2_fu_200_p2 ;
   out13_assign_fu_281_p2__temp = out13_assign_fu_281_p2 ;
   t16_reg_327__temp = t16_reg_327 ;
   out30_assign_reg_337__temp = out30_assign_reg_337 ;
   t16_2_fu_276_p3__temp = t16_2_fu_276_p3 ;
   t25_fu_228_p2__temp = t25_fu_228_p2 ;
   t26_2_fu_250_p3__temp = t26_2_fu_250_p3 ;
   tmp_reg_321__temp = tmp_reg_321 ;
   t23_fu_206_p2__temp = t23_fu_206_p2 ;
   tmp4_fu_287_p2__temp = tmp4_fu_287_p2 ;
   ap_CS_fsm_state3__temp = ap_CS_fsm_state3 ;
   ap_NS_fsm__temp = ap_NS_fsm ;
   tmp5_fu_293_p2__temp = tmp5_fu_293_p2 ;
   t11_reg_305__temp = t11_reg_305 ;
   tmp1_fu_182_p2__temp = tmp1_fu_182_p2 ;
   t16_fu_217_p2__temp = t16_fu_217_p2 ;
   t5_fu_194_p2__temp = t5_fu_194_p2 ;
   ap_CS_fsm_state2__temp = ap_CS_fsm_state2 ;
   out30_assign_1_fu_270_p3__temp = out30_assign_1_fu_270_p3 ;
   t16_1_fu_258_p2__temp = t16_1_fu_258_p2 ;
   t5_reg_311__temp = t5_reg_311 ;
   t16_1_reg_332__temp = t16_1_reg_332 ;
   ap_CS_fsm_state4__temp = ap_CS_fsm_state4 ;
   tmp_reg_321_temp__temp = tmp_reg_321_temp ;
   tmp_2_fu_222_p2_temp__temp = tmp_2_fu_222_p2_temp ;
   t26_fu_233_p2__temp = t26_fu_233_p2 ;
   t23_reg_316__temp = t23_reg_316 ;
   tmp3_fu_239_p2__temp = tmp3_fu_239_p2 ;
   tmp_fu_211_p2__temp = tmp_fu_211_p2 ;
   ap_CS_fsm__temp = ap_CS_fsm ;
   out30_assign_fu_264_p2__temp = out30_assign_fu_264_p2 ;
   ap_CS_fsm_state1__temp = ap_CS_fsm_state1 ;
   tmp_2_fu_222_p2__temp = tmp_2_fu_222_p2 ;
   t26_1_fu_245_p2__temp = t26_1_fu_245_p2 ;

       if(1 == ap_CS_fsm_state2)
       {
           t5_reg_311 =   ( in3 - in4 ) ;
           t23_reg_316 =   (  (  ( in3 - in4 )  + in22 )  + t11_reg_305__temp  ) ;
       }
       goto ap_ST_fsm_state3;

   ap_ST_fsm_state3:

  ap_CS_fsm_state1 = 0;
  ap_CS_fsm_state2 = 0;
  ap_CS_fsm_state3 = 1;
  ap_CS_fsm_state4 = 0;
   t11_fu_188_p2__temp = t11_fu_188_p2 ;
   tmp2_fu_200_p2__temp = tmp2_fu_200_p2 ;
   out13_assign_fu_281_p2__temp = out13_assign_fu_281_p2 ;
   t16_reg_327__temp = t16_reg_327 ;
   out30_assign_reg_337__temp = out30_assign_reg_337 ;
   t16_2_fu_276_p3__temp = t16_2_fu_276_p3 ;
   t25_fu_228_p2__temp = t25_fu_228_p2 ;
   t26_2_fu_250_p3__temp = t26_2_fu_250_p3 ;
   tmp_reg_321__temp = tmp_reg_321 ;
   t23_fu_206_p2__temp = t23_fu_206_p2 ;
   tmp4_fu_287_p2__temp = tmp4_fu_287_p2 ;
   ap_CS_fsm_state3__temp = ap_CS_fsm_state3 ;
   ap_NS_fsm__temp = ap_NS_fsm ;
   tmp5_fu_293_p2__temp = tmp5_fu_293_p2 ;
   t11_reg_305__temp = t11_reg_305 ;
   tmp1_fu_182_p2__temp = tmp1_fu_182_p2 ;
   t16_fu_217_p2__temp = t16_fu_217_p2 ;
   t5_fu_194_p2__temp = t5_fu_194_p2 ;
   ap_CS_fsm_state2__temp = ap_CS_fsm_state2 ;
   out30_assign_1_fu_270_p3__temp = out30_assign_1_fu_270_p3 ;
   t16_1_fu_258_p2__temp = t16_1_fu_258_p2 ;
   t5_reg_311__temp = t5_reg_311 ;
   t16_1_reg_332__temp = t16_1_reg_332 ;
   ap_CS_fsm_state4__temp = ap_CS_fsm_state4 ;
   tmp_reg_321_temp__temp = tmp_reg_321_temp ;
   tmp_2_fu_222_p2_temp__temp = tmp_2_fu_222_p2_temp ;
   t26_fu_233_p2__temp = t26_fu_233_p2 ;
   t23_reg_316__temp = t23_reg_316 ;
   tmp3_fu_239_p2__temp = tmp3_fu_239_p2 ;
   tmp_fu_211_p2__temp = tmp_fu_211_p2 ;
   ap_CS_fsm__temp = ap_CS_fsm ;
   out30_assign_fu_264_p2__temp = out30_assign_fu_264_p2 ;
   ap_CS_fsm_state1__temp = ap_CS_fsm_state1 ;
   tmp_2_fu_222_p2__temp = tmp_2_fu_222_p2 ;
   t26_1_fu_245_p2__temp = t26_1_fu_245_p2 ;

       if(1 == ap_CS_fsm_state3)
       {
          if(in2==in1)
            tmp_reg_321 = 1;
          else
            tmp_reg_321 = 0;
          t16_reg_327 =   ( t11_reg_305__temp  - in17 ) ;
          if(in9<in10){
            t16_1_reg_332 = (  ( t23_reg_316__temp  - in24 )  + in27 ) - in28;
            out30_assign_reg_337 = (  ( t23_reg_316__temp  - in24 )  + in27 ) + in29;
          }
          else{
            t16_1_reg_332 = (  ( in19 + in20 )  + t5_reg_311__temp  ) - in28;
            out30_assign_reg_337 = (  ( in19 + in20 )  + t5_reg_311__temp  ) + in29;
          }
       }
       goto ap_ST_fsm_state4;

   ap_ST_fsm_state4:

  ap_CS_fsm_state1 = 0;
  ap_CS_fsm_state2 = 0;
  ap_CS_fsm_state3 = 0;
  ap_CS_fsm_state4 = 1;
   t11_fu_188_p2__temp = t11_fu_188_p2 ;
   tmp2_fu_200_p2__temp = tmp2_fu_200_p2 ;
   out13_assign_fu_281_p2__temp = out13_assign_fu_281_p2 ;
   t16_reg_327__temp = t16_reg_327 ;
   out30_assign_reg_337__temp = out30_assign_reg_337 ;
   t16_2_fu_276_p3__temp = t16_2_fu_276_p3 ;
   t25_fu_228_p2__temp = t25_fu_228_p2 ;
   t26_2_fu_250_p3__temp = t26_2_fu_250_p3 ;
   tmp_reg_321__temp = tmp_reg_321 ;
   t23_fu_206_p2__temp = t23_fu_206_p2 ;
   tmp4_fu_287_p2__temp = tmp4_fu_287_p2 ;
   ap_CS_fsm_state3__temp = ap_CS_fsm_state3 ;
   ap_NS_fsm__temp = ap_NS_fsm ;
   tmp5_fu_293_p2__temp = tmp5_fu_293_p2 ;
   t11_reg_305__temp = t11_reg_305 ;
   tmp1_fu_182_p2__temp = tmp1_fu_182_p2 ;
   t16_fu_217_p2__temp = t16_fu_217_p2 ;
   t5_fu_194_p2__temp = t5_fu_194_p2 ;
   ap_CS_fsm_state2__temp = ap_CS_fsm_state2 ;
   out30_assign_1_fu_270_p3__temp = out30_assign_1_fu_270_p3 ;
   t16_1_fu_258_p2__temp = t16_1_fu_258_p2 ;
   t5_reg_311__temp = t5_reg_311 ;
   t16_1_reg_332__temp = t16_1_reg_332 ;
   ap_CS_fsm_state4__temp = ap_CS_fsm_state4 ;
   tmp_reg_321_temp__temp = tmp_reg_321_temp ;
   tmp_2_fu_222_p2_temp__temp = tmp_2_fu_222_p2_temp ;
   t26_fu_233_p2__temp = t26_fu_233_p2 ;
   t23_reg_316__temp = t23_reg_316 ;
   tmp3_fu_239_p2__temp = tmp3_fu_239_p2 ;
   tmp_fu_211_p2__temp = tmp_fu_211_p2 ;
   ap_CS_fsm__temp = ap_CS_fsm ;
   out30_assign_fu_264_p2__temp = out30_assign_fu_264_p2 ;
   ap_CS_fsm_state1__temp = ap_CS_fsm_state1 ;
   tmp_2_fu_222_p2__temp = tmp_2_fu_222_p2 ;
   t26_1_fu_245_p2__temp = t26_1_fu_245_p2 ;

       if(1 == ap_CS_fsm_state4)
       {
          ap_done =  1;
          if(tmp_reg_321__temp == 1){
            ap_return = out30__temp + t16_reg_327__temp + (  ( in14 - in15 )  + in32 );
          }
          else{
            ap_return = out30_assign_reg_337__temp + t16_1_reg_332__temp + (  ( in14 - in15 )  + in32 );
          }
       }
       if(1 == ap_CS_fsm_state4)
       {
           ap_ready =  1;
       }
       if(ap_done==1){
       goto end;
       }
       goto ap_ST_fsm_state1;
   end:

    freopen("klee_output2.txt","a+",stderr);
    klee_print_expr("return_port:=",ap_return);
    return ap_return;
}
