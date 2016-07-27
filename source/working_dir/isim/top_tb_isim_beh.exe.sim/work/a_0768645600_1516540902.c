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
static const char *ng0 = "D:/Nate/dev/FPGA_stuff/fpgaProjects/serial_switch/uart_rx.vhd";
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_0768645600_1516540902_p_0(char *t0)
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

LAB0:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6264);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(68, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(73, ng0);
    t1 = (t0 + 1352U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 6408);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(74, ng0);
    t1 = (t0 + 2472U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 6472);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(75, ng0);
    t1 = (t0 + 2632U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (t0 + 6536);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = t2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(69, ng0);
    t3 = (t0 + 6408);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(70, ng0);
    t1 = (t0 + 6472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(71, ng0);
    t1 = (t0 + 6472);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

}

static void work_a_0768645600_1516540902_p_1(char *t0)
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

LAB0:    xsi_set_current_line(82, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6280);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(83, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(86, ng0);
    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)3);
    if (t6 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:    t1 = (t0 + 2792U);
    t3 = *((char **)t1);
    t5 = *((unsigned char *)t3);
    t6 = (t5 == (unsigned char)2);
    if (t6 == 1)
        goto LAB16;

LAB17:    t2 = (unsigned char)0;

LAB18:    if (t2 != 0)
        goto LAB14;

LAB15:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(84, ng0);
    t3 = (t0 + 6600);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(87, ng0);
    t1 = (t0 + 6600);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB11:    t1 = (t0 + 2632U);
    t4 = *((char **)t1);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    t2 = t12;
    goto LAB13;

LAB14:    xsi_set_current_line(89, ng0);
    t1 = (t0 + 6600);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB9;

LAB16:    t1 = (t0 + 2632U);
    t4 = *((char **)t1);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    t2 = t12;
    goto LAB18;

}

static void work_a_0768645600_1516540902_p_2(char *t0)
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
    unsigned char t13;
    unsigned char t14;
    int t15;
    int t16;
    int t17;
    unsigned char t18;
    char *t19;
    char *t20;
    char *t21;

LAB0:    xsi_set_current_line(114, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6296);
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
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t2 = (t11 == 0);
    if (t2 != 0)
        goto LAB8;

LAB10:    xsi_set_current_line(130, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t1 = (t0 + 3728U);
    t4 = *((char **)t1);
    t15 = *((int *)t4);
    t16 = (t15 - 1);
    t2 = (t11 == t16);
    if (t2 != 0)
        goto LAB20;

LAB22:    xsi_set_current_line(138, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t15 = (t11 + 1);
    t1 = (t0 + 6728);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t15;
    xsi_driver_first_trans_fast(t1);

LAB21:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(116, ng0);
    t3 = (t0 + 6664);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 2792U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t12 = (t6 == (unsigned char)2);
    if (t12 == 1)
        goto LAB14;

LAB15:    t5 = (unsigned char)0;

LAB16:    if (t5 != 0)
        goto LAB11;

LAB13:    xsi_set_current_line(127, ng0);
    t1 = (t0 + 6728);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);

LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 2312U);
    t8 = *((char **)t1);
    t15 = *((int *)t8);
    t1 = (t0 + 3728U);
    t9 = *((char **)t1);
    t16 = *((int *)t9);
    t17 = (t16 - 1);
    t18 = (t15 == t17);
    if (t18 != 0)
        goto LAB17;

LAB19:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 2312U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t15 = (t11 + 1);
    t1 = (t0 + 6728);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t15;
    xsi_driver_first_trans_fast(t1);

LAB18:    goto LAB12;

LAB14:    t1 = (t0 + 2952U);
    t7 = *((char **)t1);
    t13 = *((unsigned char *)t7);
    t14 = (t13 == (unsigned char)3);
    t5 = t14;
    goto LAB16;

LAB17:    xsi_set_current_line(121, ng0);
    t1 = (t0 + 6664);
    t10 = (t1 + 56U);
    t19 = *((char **)t10);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    *((int *)t21) = 1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(122, ng0);
    t1 = (t0 + 6728);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((int *)t8) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB18;

LAB20:    xsi_set_current_line(131, ng0);
    t1 = (t0 + 6728);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(132, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t1 = (t0 + 3608U);
    t4 = *((char **)t1);
    t15 = *((int *)t4);
    t16 = (t15 - 1);
    t2 = (t11 == t16);
    if (t2 != 0)
        goto LAB23;

LAB25:    xsi_set_current_line(135, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t15 = (t11 + 1);
    t1 = (t0 + 6664);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    *((int *)t9) = t15;
    xsi_driver_first_trans_fast(t1);

LAB24:    goto LAB21;

LAB23:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 6664);
    t7 = (t1 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((int *)t10) = 0;
    xsi_driver_first_trans_fast(t1);
    goto LAB24;

}

static void work_a_0768645600_1516540902_p_3(char *t0)
{
    char t33[16];
    char t35[16];
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
    char *t11;
    char *t12;
    int t13;
    int t14;
    int t15;
    int t16;
    int t17;
    int t18;
    int t19;
    int t20;
    unsigned char t21;
    int t22;
    int t23;
    int t24;
    int t25;
    unsigned char t26;
    unsigned char t27;
    char *t28;
    unsigned int t29;
    unsigned int t30;
    unsigned int t31;
    char *t32;
    char *t34;
    char *t36;
    char *t37;
    int t38;
    unsigned int t39;
    unsigned char t40;
    char *t41;
    char *t42;
    char *t43;
    char *t44;

LAB0:    xsi_set_current_line(147, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6312);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(148, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(151, ng0);
    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t13 = *((int *)t3);
    t1 = (t0 + 3248U);
    t4 = *((char **)t1);
    t14 = *((int *)t4);
    t15 = (t14 - 1);
    t6 = (t13 > t15);
    if (t6 == 1)
        goto LAB14;

LAB15:    t5 = (unsigned char)0;

LAB16:    if (t5 == 1)
        goto LAB11;

LAB12:    t2 = (unsigned char)0;

LAB13:    if (t2 != 0)
        goto LAB8;

LAB10:
LAB9:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(149, ng0);
    t3 = xsi_get_transient_memory(8U);
    memset(t3, 0, 8U);
    t7 = t3;
    memset(t7, (unsigned char)2, 8U);
    t8 = (t0 + 6792);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    t11 = (t10 + 56U);
    t12 = *((char **)t11);
    memcpy(t12, t3, 8U);
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB8:    xsi_set_current_line(152, ng0);
    t1 = (t0 + 2792U);
    t12 = *((char **)t1);
    t27 = *((unsigned char *)t12);
    t1 = (t0 + 1992U);
    t28 = *((char **)t1);
    t29 = (7 - 7);
    t30 = (t29 * 1U);
    t31 = (0 + t30);
    t1 = (t28 + t31);
    t34 = ((IEEE_P_2592010699) + 4024);
    t36 = (t35 + 0U);
    t37 = (t36 + 0U);
    *((int *)t37) = 7;
    t37 = (t36 + 4U);
    *((int *)t37) = 1;
    t37 = (t36 + 8U);
    *((int *)t37) = -1;
    t38 = (1 - 7);
    t39 = (t38 * -1);
    t39 = (t39 + 1);
    t37 = (t36 + 12U);
    *((unsigned int *)t37) = t39;
    t32 = xsi_base_array_concat(t32, t33, t34, (char)99, t27, (char)97, t1, t35, (char)101);
    t39 = (1U + 7U);
    t40 = (8U != t39);
    if (t40 == 1)
        goto LAB17;

LAB18:    t37 = (t0 + 6792);
    t41 = (t37 + 56U);
    t42 = *((char **)t41);
    t43 = (t42 + 56U);
    t44 = *((char **)t43);
    memcpy(t44, t32, 8U);
    xsi_driver_first_trans_fast(t37);
    goto LAB9;

LAB11:    t1 = (t0 + 2312U);
    t10 = *((char **)t1);
    t22 = *((int *)t10);
    t1 = (t0 + 3728U);
    t11 = *((char **)t1);
    t23 = *((int *)t11);
    t24 = (t23 / 2);
    t25 = (t24 - 1);
    t26 = (t22 == t25);
    t2 = t26;
    goto LAB13;

LAB14:    t1 = (t0 + 2152U);
    t7 = *((char **)t1);
    t16 = *((int *)t7);
    t1 = (t0 + 3248U);
    t8 = *((char **)t1);
    t17 = *((int *)t8);
    t1 = (t0 + 3368U);
    t9 = *((char **)t1);
    t18 = *((int *)t9);
    t19 = (t17 + t18);
    t20 = (t19 - 1);
    t21 = (t16 <= t20);
    t5 = t21;
    goto LAB16;

LAB17:    xsi_size_not_matching(8U, t39, 0);
    goto LAB18;

}

static void work_a_0768645600_1516540902_p_4(char *t0)
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
    int t13;
    int t14;
    int t15;
    int t16;
    int t17;
    char *t18;
    char *t19;
    char *t20;

LAB0:    xsi_set_current_line(160, ng0);
    t1 = (t0 + 992U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 6328);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(161, ng0);
    t3 = (t0 + 1192U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    t1 = (t0 + 2152U);
    t3 = *((char **)t1);
    t11 = *((int *)t3);
    t1 = (t0 + 3248U);
    t4 = *((char **)t1);
    t12 = *((int *)t4);
    t1 = (t0 + 3368U);
    t7 = *((char **)t1);
    t13 = *((int *)t7);
    t14 = (t12 + t13);
    t5 = (t11 == t14);
    if (t5 == 1)
        goto LAB10;

LAB11:    t2 = (unsigned char)0;

LAB12:    if (t2 != 0)
        goto LAB8;

LAB9:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 6856);
    t3 = (t1 + 56U);
    t4 = *((char **)t3);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(162, ng0);
    t3 = (t0 + 6856);
    t7 = (t3 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(163, ng0);
    t1 = xsi_get_transient_memory(8U);
    memset(t1, 0, 8U);
    t3 = t1;
    memset(t3, (unsigned char)2, 8U);
    t4 = (t0 + 6920);
    t7 = (t4 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t4);
    goto LAB6;

LAB8:    xsi_set_current_line(165, ng0);
    t1 = (t0 + 6856);
    t10 = (t1 + 56U);
    t18 = *((char **)t10);
    t19 = (t18 + 56U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(166, ng0);
    t1 = (t0 + 1992U);
    t3 = *((char **)t1);
    t1 = (t0 + 6920);
    t4 = (t1 + 56U);
    t7 = *((char **)t4);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 8U);
    xsi_driver_first_trans_fast_port(t1);
    goto LAB6;

LAB10:    t1 = (t0 + 2312U);
    t8 = *((char **)t1);
    t15 = *((int *)t8);
    t1 = (t0 + 3728U);
    t9 = *((char **)t1);
    t16 = *((int *)t9);
    t17 = (t16 - 1);
    t6 = (t15 == t17);
    t2 = t6;
    goto LAB12;

}


extern void work_a_0768645600_1516540902_init()
{
	static char *pe[] = {(void *)work_a_0768645600_1516540902_p_0,(void *)work_a_0768645600_1516540902_p_1,(void *)work_a_0768645600_1516540902_p_2,(void *)work_a_0768645600_1516540902_p_3,(void *)work_a_0768645600_1516540902_p_4};
	xsi_register_didat("work_a_0768645600_1516540902", "isim/top_tb_isim_beh.exe.sim/work/a_0768645600_1516540902.didat");
	xsi_register_executes(pe);
}
