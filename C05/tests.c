
#include "../common/assert.h"
#include "../common/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C05/data.txt"
#endif

#ifdef HAVE_EX00
int ft_iterative_factorial(int nb);
#endif
#ifdef HAVE_EX01
int ft_recursive_factorial(int nb);
#endif
#ifdef HAVE_EX02
int ft_iterative_power(int nb, int power);
#endif
#ifdef HAVE_EX03
int ft_recursive_power(int nb, int power);
#endif
#ifdef HAVE_EX04
int ft_fibonacci(int index);
#endif
#ifdef HAVE_EX05
int ft_sqrt(int nb);
#endif
#ifdef HAVE_EX06
int ft_is_prime(int nb);
#endif
#ifdef HAVE_EX07
int ft_find_next_prime(int nb);
#endif
#ifdef HAVE_EX08
int ft_ten_queens_puzzle(void);
#endif

#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex00_iter_fact",'|',&t)!=0){ printf("WARN no data [ex00_iter_fact]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"iter_fact(%d)",n);
		assert_int_eq(ft_iterative_factorial(n),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX01
static void test_ex01(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_rec_fact",'|',&t)!=0){ printf("WARN no data [ex01_rec_fact]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"rec_fact(%d)",n);
		assert_int_eq(ft_recursive_factorial(n),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex02_iter_pow",'|',&t)!=0){ printf("WARN no data [ex02_iter_pow]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int p=atoi(t.rows[i].cols[1]); int exp=atoi(t.rows[i].cols[2]);
		char msg[64]; snprintf(msg,sizeof msg,"iter_pow(%d,%d)",n,p);
		assert_int_eq(ft_iterative_power(n,p),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX03
static void test_ex03(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex03_rec_pow",'|',&t)!=0){ printf("WARN no data [ex03_rec_pow]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int p=atoi(t.rows[i].cols[1]); int exp=atoi(t.rows[i].cols[2]);
		char msg[64]; snprintf(msg,sizeof msg,"rec_pow(%d,%d)",n,p);
		assert_int_eq(ft_recursive_power(n,p),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX04
static void test_ex04(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex04_fibo",'|',&t)!=0){ printf("WARN no data [ex04_fibo]\n"); return; }
	for(int i=0;i<t.count;i++){ int idx=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"fibo(%d)",idx);
		assert_int_eq(ft_fibonacci(idx),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX05
static void test_ex05(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex05_sqrt",'|',&t)!=0){ printf("WARN no data [ex05_sqrt]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"sqrt(%d)",n);
		assert_int_eq(ft_sqrt(n),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX06
static void test_ex06(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex06_is_prime",'|',&t)!=0){ printf("WARN no data [ex06_is_prime]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"is_prime(%d)",n);
		assert_int_eq(ft_is_prime(n),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX07
static void test_ex07(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex07_next_prime",'|',&t)!=0){ printf("WARN no data [ex07_next_prime]\n"); return; }
	for(int i=0;i<t.count;i++){ int n=atoi(t.rows[i].cols[0]); int exp=atoi(t.rows[i].cols[1]);
		char msg[64]; snprintf(msg,sizeof msg,"next_prime(%d)",n);
		assert_int_eq(ft_find_next_prime(n),exp,msg); }
	data_free(&t);
}
#endif
#ifdef HAVE_EX08
static void test_ex08(void)
{
	/* optional: many implementations print solutions; we check returned count */
	assert_int_eq(ft_ten_queens_puzzle(), 724, "ten_queens returns 724");
}
#endif

void test_C05(void)
{
	t_set_suite("C05");
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
#ifdef HAVE_EX06
	test_ex06();
#endif
#ifdef HAVE_EX07
	test_ex07();
#endif
#ifdef HAVE_EX08
	test_ex08();
#endif
	t_summary();
}
