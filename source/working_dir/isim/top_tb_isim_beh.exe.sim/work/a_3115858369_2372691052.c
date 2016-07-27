/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x7708f090 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/top_tb.vhd";



static void work_a_3115858369_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(89, ng0);

LAB3:    t1 = (t0 + 2312U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 5264);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_delta(t1, 1U, 1, 0LL);

LAB2:    t8 = (t0 + 5184);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3115858369_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 4120U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3928);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 5328);
    t3 = (t2 + 56U);
    t4 = *((char **)t3);
    t5 = (t4 + 56U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 3928);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3115858369_2372691052_p_2(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int64 t10;
    int t11;
    int t12;
    int64 t13;

LAB0:    t1 = (t0 + 4368U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB4;

LAB6:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t4 = (t11 == 9);
    if (t4 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t12 = (t11 + 1);
    t2 = (t0 + 5392);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t2);

LAB12:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t10 = *((int64 *)t3);
    t2 = (t0 + 2888U);
    t6 = *((char **)t2);
    t11 = *((int *)t6);
    t13 = (t10 * t11);
    t2 = (t0 + 4176);
    xsi_process_wait(t2, t13);

LAB19:    *((char **)t1) = &&LAB20;

LAB1:    return;
LAB4:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 5392);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(105, ng0);
    t2 = (t0 + 5456);
    t3 = (t2 + 56U);
    t6 = *((char **)t3);
    t7 = (t6 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(106, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t10 = *((int64 *)t3);
    t2 = (t0 + 4176);
    xsi_process_wait(t2, t10);

LAB9:    *((char **)t1) = &&LAB10;
    goto LAB1;

LAB5:    goto LAB2;

LAB7:    goto LAB5;

LAB8:    goto LAB7;

LAB10:    goto LAB8;

LAB11:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 5392);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = 0;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 2152U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t4 = (t11 == 0);
    if (t4 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 2152U);
    t3 = *((char **)t2);
    t11 = *((int *)t3);
    t12 = (t11 - 1);
    t2 = (t0 + 5456);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t2);

LAB15:    goto LAB12;

LAB14:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 5456);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = 3;
    xsi_driver_first_trans_fast(t2);
    goto LAB15;

LAB17:    goto LAB5;

LAB18:    goto LAB17;

LAB20:    goto LAB18;

}

static void work_a_3115858369_2372691052_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    int t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    int t15;
    int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;
    int64 t24;

LAB0:    t1 = (t0 + 4616U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 1192U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 != 0)
        goto LAB4;

LAB6:    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t4 = (t10 == 0);
    if (t4 != 0)
        goto LAB7;

LAB8:    t2 = (t0 + 1992U);
    t3 = *((char **)t2);
    t10 = *((int *)t3);
    t4 = (t10 == 9);
    if (t4 != 0)
        goto LAB9;

LAB10:    xsi_set_current_line(131, ng0);
    t2 = (t0 + 1832U);
    t3 = *((char **)t2);
    t2 = (t0 + 1992U);
    t6 = *((char **)t2);
    t10 = *((int *)t6);
    t11 = (t10 - 1);
    t12 = (t11 - 7);
    t13 = (t12 * -1);
    xsi_vhdl_check_range_of_index(7, 0, -1, t11);
    t14 = (1U * t13);
    t2 = (t0 + 2152U);
    t7 = *((char **)t2);
    t15 = *((int *)t7);
    t16 = (t15 - 3);
    t17 = (t16 * -1);
    xsi_vhdl_check_range_of_index(3, 0, -1, t15);
    t18 = (8U * t17);
    t19 = (0 + t18);
    t20 = (t19 + t14);
    t2 = (t3 + t20);
    t4 = *((unsigned char *)t2);
    t8 = (t0 + 5520);
    t9 = (t8 + 56U);
    t21 = *((char **)t9);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    *((unsigned char *)t23) = t4;
    xsi_driver_first_trans_fast(t8);

LAB5:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2768U);
    t3 = *((char **)t2);
    t24 = *((int64 *)t3);
    t2 = (t0 + 4424);
    xsi_process_wait(t2, t24);

LAB13:    *((char **)t1) = &&LAB14;

LAB1:    return;
LAB4:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 5520);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB5;

LAB7:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 5520);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB5;

LAB9:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 5520);
    t6 = (t2 + 56U);
    t7 = *((char **)t6);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    goto LAB5;

LAB11:    goto LAB2;

LAB12:    goto LAB11;

LAB14:    goto LAB12;

}

static void work_a_3115858369_2372691052_p_4(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int64 t8;
    int t9;
    int64 t10;
    int64 t11;

LAB0:    t1 = (t0 + 4864U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(140, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 4672);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(141, ng0);
    t2 = (t0 + 5584);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(143, ng0);
    t2 = (t0 + 2768U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t8 = (t3 * 52);
    t2 = (t0 + 4672);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 5584);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(145, ng0);
    t2 = (t0 + 5648);
    t4 = (t2 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(146, ng0);
    t2 = (t0 + 2768U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t2 = (t0 + 2888U);
    t5 = *((char **)t2);
    t9 = *((int *)t5);
    t8 = (t3 * t9);
    t10 = (t8 * 4);
    t11 = (t10 * 8);
    t2 = (t0 + 4672);
    xsi_process_wait(t2, t11);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 2768U);
    t4 = *((char **)t2);
    t3 = *((int64 *)t4);
    t8 = (t3 * 10);
    t2 = (t0 + 4672);
    xsi_process_wait(t2, t8);

LAB18:    *((char **)t1) = &&LAB19;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    xsi_set_current_line(154, ng0);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB17:    goto LAB16;

LAB19:    goto LAB17;

LAB20:    goto LAB2;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

}


extern void work_a_3115858369_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3115858369_2372691052_p_0,(void *)work_a_3115858369_2372691052_p_1,(void *)work_a_3115858369_2372691052_p_2,(void *)work_a_3115858369_2372691052_p_3,(void *)work_a_3115858369_2372691052_p_4};
	xsi_register_didat("work_a_3115858369_2372691052", "isim/top_tb_isim_beh.exe.sim/work/a_3115858369_2372691052.didat");
	xsi_register_executes(pe);
}
