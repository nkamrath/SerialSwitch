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
static const char *ng0 = "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/fifo.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_3357731915_1516540902_p_0(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned char t12;
    unsigned char t13;
    int t14;
    int t15;
    unsigned char t16;
    int t17;
    int t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(68, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5752);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(69, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(72, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t6 = *((unsigned char *)t3);
    t11 = (t6 == (unsigned char)3);
    if (t11 == 1)
        goto LAB14;

LAB15:    t5 = (unsigned char)0;

LAB16:    if (t5 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t6 = *((unsigned char *)t3);
    t11 = (t6 == (unsigned char)2);
    if (t11 == 1)
        goto LAB22;

LAB23:    t5 = (unsigned char)0;

LAB24:    if (t5 == 1)
        goto LAB19;

LAB20:    t2 = (unsigned char)0;

LAB21:    if (t2 != 0)
        goto LAB17;

LAB18:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(70, ng0);
    t3 = (t0 + 5912);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 2472U);
    t8 = *((char **)t1);
    t17 = *((int *)t8);
    t18 = (t17 + 1);
    t1 = (t0 + 5912);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t19 = (t10 + 56U);
    t20 = *((char **)t19);
    *((int *)t20) = t18;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB11:    t1 = (t0 + 2472U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t15 = (100 - 1);
    t16 = (t14 < t15);
    t2 = t16;
    goto LAB13;

LAB14:    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t12 = *((unsigned char *)t4);
    t13 = (t12 == (unsigned char)2);
    t5 = t13;
    goto LAB16;

LAB17:    xsi_set_current_line(75, ng0);
    t1 = (t0 + 2472U);
    t8 = *((char **)t1);
    t15 = *((int *)t8);
    t17 = (t15 - 1);
    t1 = (t0 + 5912);
    t9 = (t1 + 56U);
    t10 = *((char **)t9);
    t19 = (t10 + 56U);
    t20 = *((char **)t19);
    *((int *)t20) = t17;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB19:    t1 = (t0 + 2472U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t16 = (t14 > 0);
    t2 = t16;
    goto LAB21;

LAB22:    t1 = (t0 + 1672U);
    t4 = *((char **)t1);
    t12 = *((unsigned char *)t4);
    t13 = (t12 == (unsigned char)3);
    t5 = t13;
    goto LAB24;

}

static void work_a_3357731915_1516540902_p_1(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    unsigned char t8;
    unsigned char t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(83, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5768);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(84, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(87, ng0);
    t3 = (t0 + 1512U);
    t7 = *((char **)t3);
    t8 = *((unsigned char *)t7);
    t9 = (t8 == (unsigned char)3);
    if (t9 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(90, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t1 = (t0 + 2632U);
    t4 = *((char **)t1);
    t12 = *((int *)t4);
    t13 = (t12 - 0);
    t14 = (t13 * 1);
    xsi_vhdl_check_range_of_index(0, 99, 1, t12);
    t15 = (8U * t14);
    t16 = (0 + t15);
    t1 = (t3 + t16);
    t7 = (t0 + 6040);
    t10 = (t7 + 56U);
    t11 = *((char **)t10);
    t17 = (t11 + 56U);
    t18 = *((char **)t17);
    memcpy(t18, t1, 8U);
    xsi_driver_first_trans_fast_port(t7);

LAB6:    goto LAB3;

LAB5:    goto LAB6;

LAB8:    xsi_set_current_line(88, ng0);
    t3 = (t0 + 1352U);
    t10 = *((char **)t3);
    t3 = (t0 + 2792U);
    t11 = *((char **)t3);
    t12 = *((int *)t11);
    t13 = (t12 - 0);
    t14 = (t13 * 1);
    t15 = (8U * t14);
    t16 = (0U + t15);
    t3 = (t0 + 5976);
    t17 = (t3 + 56U);
    t18 = *((char **)t17);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    memcpy(t20, t10, 8U);
    xsi_driver_first_trans_delta(t3, t16, 8U, 0LL);
    goto LAB9;

}

static void work_a_3357731915_1516540902_p_2(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    int t12;
    unsigned char t13;
    int t14;
    int t15;
    unsigned char t16;
    char *t17;

LAB0:    xsi_set_current_line(97, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5784);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(98, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(101, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(99, ng0);
    t3 = (t0 + 6104);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 2792U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t15 = (100 - 1);
    t16 = (t14 == t15);
    if (t16 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(105, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t12 = (t11 + 1);
    t1 = (t0 + 6104);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t12;
    xsi_driver_first_trans_fast(t1);

LAB15:    goto LAB9;

LAB11:    t1 = (t0 + 2472U);
    t4 = *((char **)t1);
    t11 = *((int *)t4);
    t12 = (100 - 1);
    t13 = (t11 < t12);
    t2 = t13;
    goto LAB13;

LAB14:    xsi_set_current_line(103, ng0);
    t1 = (t0 + 6104);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t17 = *((char **)t10);
    *((int *)t17) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

}

static void work_a_3357731915_1516540902_p_3(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    unsigned char t12;
    int t13;
    int t14;
    unsigned char t15;
    char *t16;
    int t17;

LAB0:    xsi_set_current_line(114, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5800);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(115, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 1672U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB19;

LAB20:    t2 = (unsigned char)0;

LAB21:    if (t2 != 0)
        goto LAB17;

LAB18:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(116, ng0);
    t3 = (t0 + 6168);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 2632U);
    t7 = *((char **)t1);
    t13 = *((int *)t7);
    t14 = (100 - 1);
    t15 = (t13 == t14);
    if (t15 != 0)
        goto LAB14;

LAB16:    xsi_set_current_line(122, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t13 = (t11 + 1);
    t1 = (t0 + 6168);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t13;
    xsi_driver_first_trans_fast(t1);

LAB15:    goto LAB9;

LAB11:    t1 = (t0 + 2472U);
    t4 = *((char **)t1);
    t11 = *((int *)t4);
    t12 = (t11 > 0);
    t2 = t12;
    goto LAB13;

LAB14:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 6168);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t16 = *((char **)t10);
    *((int *)t16) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB15;

LAB17:    xsi_set_current_line(125, ng0);
    t1 = (t0 + 2632U);
    t7 = *((char **)t1);
    t14 = *((int *)t7);
    t17 = (100 - 1);
    t15 = (t14 == t17);
    if (t15 != 0)
        goto LAB22;

LAB24:    xsi_set_current_line(128, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t13 = (t11 + 1);
    t1 = (t0 + 6168);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t13;
    xsi_driver_first_trans_fast(t1);

LAB23:    goto LAB9;

LAB19:    t1 = (t0 + 2472U);
    t4 = *((char **)t1);
    t11 = *((int *)t4);
    t13 = (100 - 1);
    t12 = (t11 == t13);
    t2 = t12;
    goto LAB21;

LAB22:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 6168);
    t8 = (t1 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t16 = *((char **)t10);
    *((int *)t16) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

}

static void work_a_3357731915_1516540902_p_4(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;

LAB0:    xsi_set_current_line(137, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 5816);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(138, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(141, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 > 0);
    if (t2 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 6232);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(139, ng0);
    t3 = (t0 + 6232);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(142, ng0);
    t1 = (t0 + 6232);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB9;

}

static void work_a_3357731915_1516540902_p_5(char *t0)
{
    char *t1;
    char *t2;
    int t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(150, ng0);

LAB3:    t1 = (t0 + 2472U);
    t2 = *((char **)t1);
    t3 = *((int *)t2);
    t1 = (t0 + 6296);
    t4 = (t1 + 56U);
    t5 = *((char **)t4);
    t6 = (t5 + 56U);
    t7 = *((char **)t6);
    *((int *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 5832);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_3357731915_1516540902_init()
{
	static char *pe[] = {(void *)work_a_3357731915_1516540902_p_0,(void *)work_a_3357731915_1516540902_p_1,(void *)work_a_3357731915_1516540902_p_2,(void *)work_a_3357731915_1516540902_p_3,(void *)work_a_3357731915_1516540902_p_4,(void *)work_a_3357731915_1516540902_p_5};
	xsi_register_didat("work_a_3357731915_1516540902", "isim/top_tb_isim_beh.exe.sim/work/a_3357731915_1516540902.didat");
	xsi_register_executes(pe);
}
