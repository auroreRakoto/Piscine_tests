
#include "../common/assert.h"
#include "../common/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C04/data.txt"
#endif
#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

#ifdef HAVE_EX00
int  ft_strlen(char *str);
#endif
#ifdef HAVE_EX01
void ft_putstr(char *str);
#endif
#ifdef HAVE_EX02
void ft_putnbr(int nb);
#endif
#ifdef HAVE_EX03
int  ft_atoi(char *str);
#endif
#ifdef HAVE_EX04
void ft_putnbr_base(int nbr, char *base);
#endif
#ifdef HAVE_EX05
int  ft_atoi_base(char *str, char *base);
#endif

#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex00_strlen",'|',&t)!=0){ printf("WARN no data [ex00_strlen]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *s=t.rows[i].cols[0]; int exp=atoi(t.rows[i].cols[1]);
		char msg[128]; snprintf(msg,sizeof msg,"ex00 strlen(\"%s\")", *s?s:"(empty)");
		assert_int_eq(ft_strlen((char*)(*s?s:"")), exp, msg);
	}
	data_free(&t);
}
#endif

#ifdef HAVE_EX01
static void test_ex01(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_putstr",'|',&t)!=0){ printf("WARN no data [ex01_putstr]\n"); return; }
	for(int i=0;i<t.count;i++){ ft_putstr((char*)t.rows[i].cols[0]); }
	assert_true(1,"ex01 putstr no-crash");
	data_free(&t);
}
#endif

#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex02_putnbr",'|',&t)!=0){ printf("WARN no data [ex02_putnbr]\n"); return; }
	for(int i=0;i<t.count;i++){ int v=atoi(t.rows[i].cols[0]); ft_putnbr(v); }
	assert_true(1,"ex02 putnbr no-crash");
	data_free(&t);
}
#endif

#ifdef HAVE_EX03
static void test_ex03(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex03_atoi",'|',&t)!=0){ printf("WARN no data [ex03_atoi]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *s=t.rows[i].cols[0]; int exp=atoi(t.rows[i].cols[1]);
		char msg[160]; snprintf(msg,sizeof msg,"ex03 atoi(\"%s\")", *s?s:"(empty)");
		assert_int_eq(ft_atoi((char*)(*s?s:"")), exp, msg);
	}
	data_free(&t);
}
#endif

#ifdef HAVE_EX04
static void test_ex04(void)
{
	/* printing to base: just ensure no crash for a small set */
	t_data_table t; if (data_load_section(DATA_PATH,"ex04_putnbr_base",'|',&t)!=0){ printf("WARN no data [ex04_putnbr_base]\n"); return; }
	for(int i=0;i<t.count;i++){
		int v=atoi(t.rows[i].cols[0]); char *base=(char*)t.rows[i].cols[1];
		ft_putnbr_base(v, base);
	}
	assert_true(1,"ex04 putnbr_base no-crash");
	data_free(&t);
}
#endif

#ifdef HAVE_EX05
static void test_ex05(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex05_atoi_base",'|',&t)!=0){ printf("WARN no data [ex05_atoi_base]\n"); return; }
	for(int i=0;i<t.count;i++){
		char *s=(char*)t.rows[i].cols[0]; char *base=(char*)t.rows[i].cols[1]; int exp=atoi(t.rows[i].cols[2]);
		char msg[160]; snprintf(msg,sizeof msg,"ex05 atoi_base(\"%s\",\"%s\")", s, base);
		assert_int_eq(ft_atoi_base(s, base), exp, msg);
	}
	data_free(&t);
}
#endif

void test_C04(void)
{
	t_set_suite("C04");
#ifdef HAVE_EX00
	test_ex00();
#endif
#ifdef HAVE_EX01
	test_ex01();
#endif
#ifdef HAVE_EX02
	test_ex02();
#endif
#ifdef HAVE_EX03
	test_ex03();
#endif
#ifdef HAVE_EX04
	test_ex04();
#endif
#ifdef HAVE_EX05
	test_ex05();
#endif
	t_summary();
}
