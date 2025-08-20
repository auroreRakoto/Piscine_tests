
#include "../common/assert.h"
#include "../common/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifndef DATA_PATH
# define DATA_PATH "C02/data.txt"
#endif
#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

/* ---------- Prototypes (guarded) ---------- */
#ifdef HAVE_EX00
char *ft_strcpy(char *dest, char *src);
#endif
#ifdef HAVE_EX01
char *ft_strncpy(char *dest, char *src, unsigned int n);
#endif
#ifdef HAVE_EX02
int   ft_str_is_alpha(char *str);
#endif
#ifdef HAVE_EX03
int   ft_str_is_numeric(char *str);
#endif
#ifdef HAVE_EX04
int   ft_str_is_lowercase(char *str);
#endif
#ifdef HAVE_EX05
int   ft_str_is_uppercase(char *str);
#endif
#ifdef HAVE_EX06
int   ft_str_is_printable(char *str);
#endif
#ifdef HAVE_EX07
char *ft_strupcase(char *str);
#endif
#ifdef HAVE_EX08
char *ft_strlowcase(char *str);
#endif
#ifdef HAVE_EX09
char *ft_strcapitalize(char *str);
#endif
#ifdef HAVE_EX10
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
#endif
#ifdef HAVE_EX11
void  ft_putstr_non_printable(char *str);
#endif
#ifdef HAVE_EX12
void *ft_print_memory(void *addr, unsigned int size);
#endif

/* small util */
static char *xdup(const char *s){ size_t n=strlen(s); char *p=malloc(n+1); if(p) memcpy(p,s,n+1); return p; }

/* ========== ex00 ft_strcpy ========== */
#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t;
	if (data_load_section(DATA_PATH, "ex00_strcpy", '|', &t)!=0){ printf("WARN no data [ex00_strcpy]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		const char *src = t.rows[i].cols[0];
		char buf[256]; memset(buf, '#', sizeof buf); buf[255]='\0';
#if TEST_VERBOSE
		printf("ex00[%d] BEFORE dest=\"%s\"\n", i, buf);
#endif
		char *ret = ft_strcpy(buf, (char*)(*src?src:""));
#if TEST_VERBOSE
		printf("ex00[%d] AFTER  dest=\"%s\"\n", i, buf);
#endif
		assert_true(ret==buf, "ex00 ret==dest");
		assert_str_eq(buf, (*src?src:""), "ex00 content copied");
	}
	data_free(&t);
}
#endif

/* ========== ex01 ft_strncpy ========== */
#ifdef HAVE_EX01
static void test_ex01(void)
{
	t_data_table t;
	if (data_load_section(DATA_PATH, "ex01_strncpy", '|', &t)!=0){ printf("WARN no data [ex01_strncpy]\n"); return; }
	for (int i=0;i<t.count;i++)
	{
		const char *src=t.rows[i].cols[0]; unsigned n=(unsigned)strtoul(t.rows[i].cols[1],NULL,10);
		char buf[256]; memset(buf,'@',sizeof buf); buf[255]='\0';
		char exp[256]; memset(exp,0,sizeof exp); /* pad with \0 */
		size_t sl=strlen(src); size_t m = n<sl?n:sl; memcpy(exp, src, m);
#if TEST_VERBOSE
		printf("ex01[%d] BEFORE dest head=\"%.32s\"\n", i, buf);
#endif
		char *ret=ft_strncpy(buf,(char*)src,n);
#if TEST_VERBOSE
		printf("ex01[%d] AFTER  dest head=\"%.32s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex01 ret==dest");
		assert_mem_eq(buf, exp, n, "ex01 first n bytes match");
	}
	data_free(&t);
}
#endif

/* ========== ex02..ex06 ft_str_is_* ========== */
#define GEN_IS_TEST(SEC, FN, TAG) \
static void TAG(void){ \
	t_data_table t; if (data_load_section(DATA_PATH, SEC, '|', &t)!=0){ printf("WARN no data [%s]\n", SEC); return; } \
	for(int i=0;i<t.count;i++){ const char *s=t.rows[i].cols[0]; int want=atoi(t.rows[i].cols[1]); \
		int got = FN((char*)(*s?s:"")); \
		char msg[128]; snprintf(msg,sizeof msg,"%s[%d] \"%s\"", SEC, i, *s?s:"(empty)"); \
		assert_int_eq(got,want,msg);} data_free(&t); }
#ifdef HAVE_EX02
int   ft_str_is_alpha(char *str);
GEN_IS_TEST("ex02_is_alpha", ft_str_is_alpha, test_ex02)
#endif
#ifdef HAVE_EX03
int   ft_str_is_numeric(char *str);
GEN_IS_TEST("ex03_is_numeric", ft_str_is_numeric, test_ex03)
#endif
#ifdef HAVE_EX04
int   ft_str_is_lowercase(char *str);
GEN_IS_TEST("ex04_is_lowercase", ft_str_is_lowercase, test_ex04)
#endif
#ifdef HAVE_EX05
int   ft_str_is_uppercase(char *str);
GEN_IS_TEST("ex05_is_uppercase", ft_str_is_uppercase, test_ex05)
#endif
#ifdef HAVE_EX06
int   ft_str_is_printable(char *str);
GEN_IS_TEST("ex06_is_printable", ft_str_is_printable, test_ex06)
#endif
#undef GEN_IS_TEST

/* ========== ex07 ft_strupcase ========== */
#ifdef HAVE_EX07
static void test_ex07(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex07_upcase",'|',&t)!=0){ printf("WARN no data [ex07_upcase]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *in=t.rows[i].cols[0]; const char *want=t.rows[i].cols[1];
		char *buf=xdup(in);
#if TEST_VERBOSE
		printf("ex07[%d] BEFORE \"%s\"\n", i, buf);
#endif
		char *ret=ft_strupcase(buf);
#if TEST_VERBOSE
		printf("ex07[%d] AFTER  \"%s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex07 ret==arg");
		assert_str_eq(buf,want,"ex07 upcased");
		free(buf);
	}
	data_free(&t);
}
#endif

/* ========== ex08 ft_strlowcase ========== */
#ifdef HAVE_EX08
static void test_ex08(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex08_lowcase",'|',&t)!=0){ printf("WARN no data [ex08_lowcase]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *in=t.rows[i].cols[0]; const char *want=t.rows[i].cols[1];
		char *buf=xdup(in);
#if TEST_VERBOSE
		printf("ex08[%d] BEFORE \"%s\"\n", i, buf);
#endif
		char *ret=ft_strlowcase(buf);
#if TEST_VERBOSE
		printf("ex08[%d] AFTER  \"%s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex08 ret==arg");
		assert_str_eq(buf,want,"ex08 lowcased");
		free(buf);
	}
	data_free(&t);
}
#endif

/* ========== ex09 ft_strcapitalize ========== */
#ifdef HAVE_EX09
static void test_ex09(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex09_capitalize",'|',&t)!=0){ printf("WARN no data [ex09_capitalize]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *in=t.rows[i].cols[0]; const char *want=t.rows[i].cols[1];
		char *buf=xdup(in);
#if TEST_VERBOSE
		printf("ex09[%d] BEFORE \"%s\"\n", i, buf);
#endif
		char *ret=ft_strcapitalize(buf);
#if TEST_VERBOSE
		printf("ex09[%d] AFTER  \"%s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex09 ret==arg");
		assert_str_eq(buf,want,"ex09 capitalized");
		free(buf);
	}
	data_free(&t);
}
#endif

/* ========== ex10 ft_strlcpy ========== */
#ifdef HAVE_EX10
static void test_ex10(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex10_strlcpy",'|',&t)!=0){ printf("WARN no data [ex10_strlcpy]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *src=t.rows[i].cols[0]; unsigned size=(unsigned)strtoul(t.rows[i].cols[1],NULL,10);
		const char *exp=t.rows[i].cols[2];
		char dst[256]; memset(dst,'%',sizeof dst); dst[255]='\0';
#if TEST_VERBOSE
		printf("ex10[%d] BEFORE dst head=\"%.32s\"\n", i, dst);
#endif
		unsigned ret=ft_strlcpy(dst,(char*)src,size);
#if TEST_VERBOSE
		printf("ex10[%d] AFTER  dst=\"%s\" (ret=%u)\n", i, dst, ret);
#endif
		assert_int_eq((int)ret,(int)strlen(src),"ex10 return==strlen(src)");
		assert_str_eq(dst, exp, "ex10 dst content");
	}
	data_free(&t);
}
#endif

/* ========== ex11/12 print-only (no capture) ========== */
#ifdef HAVE_EX11
static void test_ex11(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex11_non_printable",'|',&t)!=0){ printf("WARN no data [ex11_non_printable]\n"); return; }
	for(int i=0;i<t.count;i++){ ft_putstr_non_printable((char*)t.rows[i].cols[0]); }
	assert_true(1,"ex11 printed (no-crash)");
	data_free(&t);
}
#endif
#ifdef HAVE_EX12
static void test_ex12(void)
{
	static unsigned char sample[16]={0,1,2,3,'A','B','C',127,128,255,42,0,9,10,11,12};
	(void)ft_print_memory(sample,16);
	assert_true(1,"ex12 print_memory no-crash");
}
#endif

/* ========== aggregator ========== */
void test_C02(void)
{
	t_set_suite("C02");
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
#ifdef HAVE_EX09
	test_ex09();
#endif
#ifdef HAVE_EX10
	test_ex10();
#endif
#ifdef HAVE_EX11
	test_ex11();
#endif
#ifdef HAVE_EX12
	test_ex12();
#endif
	t_summary();
}
