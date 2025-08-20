
#include "../common/assert.h"
#include "../common/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C09/data.txt"
#endif
#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

/* C09 “libft” set — we test when ex01 sources are present */
#ifdef HAVE_EX01
void ft_putchar(char c);
void ft_putstr(char *str);
void ft_swap(int *a, int *b);
int  ft_strlen(char *str);
int  ft_strcmp(char *s1, char *s2);
#endif

/* ================= ex01: strlen ================= */
#ifdef HAVE_EX01
static void test_ex01_strlen(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_strlen",'|',&t)!=0){ printf("WARNING: no data [ex01_strlen]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		const char *s=t.rows[i].cols[0];
		int want=atoi(t.rows[i].cols[1]);
		char msg[160]; snprintf(msg,sizeof msg,"ex01 strlen(\"%s\")", *s?s:"(empty)");
		assert_int_eq(ft_strlen((char*)(*s?s:"")), want, msg);
	}
	data_free(&t);
}
#endif

/* ================= ex01: strcmp ================= */
#ifdef HAVE_EX01
static int sgn(int x){ return (x>0)-(x<0); }

static void test_ex01_strcmp(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_strcmp",'|',&t)!=0){ printf("WARNING: no data [ex01_strcmp]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		const char *a=t.rows[i].cols[0], *b=t.rows[i].cols[1];
		int want=atoi(t.rows[i].cols[2]);
		char msg[160]; snprintf(msg,sizeof msg,"ex01 strcmp(\"%s\",\"%s\")", a,b);
		assert_int_eq(sgn(ft_strcmp((char*)a,(char*)b)), want, msg);
	}
	data_free(&t);
}
#endif

/* ================= ex01: swap ================= */
#ifdef HAVE_EX01
static void test_ex01_swap(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_swap",'|',&t)!=0){ printf("WARNING: no data [ex01_swap]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		int a = atoi(t.rows[i].cols[0]);
		int b = atoi(t.rows[i].cols[1]);
		int want_a = atoi(t.rows[i].cols[2]);
		int want_b = atoi(t.rows[i].cols[3]);
#if TEST_VERBOSE
		printf("ex01[%d] BEFORE swap a=%d b=%d\n", i, a, b);
#endif
		ft_swap(&a, &b);
#if TEST_VERBOSE
		printf("ex01[%d] AFTER  swap a=%d b=%d\n", i, a, b);
#endif
		assert_int_eq(a, want_a, "ex01 swap a");
		assert_int_eq(b, want_b, "ex01 swap b");
	}
	data_free(&t);
}
#endif

/* ================= ex01: putstr / putchar (no-crash) ================= */
#ifdef HAVE_EX01
static void test_ex01_puts(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_putstr",'|',&t)!=0){ printf("WARNING: no data [ex01_putstr]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		char *s=(char*)t.rows[i].cols[0];
#if TEST_VERBOSE
		printf("ex01 putstr(\"%s\") + putchar('\\n')\n", s);
#endif
		ft_putstr(s);
		ft_putchar('\n');
	}
	assert_true(1, "ex01 putstr/putchar no-crash");
	data_free(&t);
}
#endif

/* -------- aggregator -------- */
void test_C09(void)
{
	t_set_suite("C09");
#ifdef HAVE_EX01
	test_ex01_strlen();
	test_ex01_strcmp();
	test_ex01_swap();
	test_ex01_puts();
#else
	printf("C09: no ex01 sources detected; skipping function tests.\n");
#endif
	t_summary();
}
