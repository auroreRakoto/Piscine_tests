
#include "../common/assert.h"
#include "../common/data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C03/data.txt"
#endif
#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

#ifdef HAVE_EX00
int   ft_strcmp(char *s1, char *s2);
#endif
#ifdef HAVE_EX01
int   ft_strncmp(char *s1, char *s2, unsigned int n);
#endif
#ifdef HAVE_EX02
char *ft_strcat(char *dest, char *src);
#endif
#ifdef HAVE_EX03
char *ft_strncat(char *dest, char *src, unsigned int nb);
#endif
#ifdef HAVE_EX04
char *ft_strstr(char *str, char *to_find);
#endif
#ifdef HAVE_EX05
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
#endif

/* sign helper */
static int sgn(int x){ return (x>0)-(x<0); }

/* ex00 strcmp */
#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex00_strcmp",'|',&t)!=0){ printf("WARN no data [ex00_strcmp]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *a=t.rows[i].cols[0], *b=t.rows[i].cols[1]; int exp=atoi(t.rows[i].cols[2]);
		int got=sgn(ft_strcmp((char*)a,(char*)b));
		char msg[160]; snprintf(msg,sizeof msg,"ex00 strcmp(\"%s\",\"%s\")", a,b);
		assert_int_eq(got,exp,msg);
	}
	data_free(&t);
}
#endif

/* ex01 strncmp */
#ifdef HAVE_EX01
static void test_ex01(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex01_strncmp",'|',&t)!=0){ printf("WARN no data [ex01_strncmp]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *a=t.rows[i].cols[0], *b=t.rows[i].cols[1]; unsigned n=(unsigned)strtoul(t.rows[i].cols[2],NULL,10);
		int exp=atoi(t.rows[i].cols[3]); int got=sgn(ft_strncmp((char*)a,(char*)b,n));
		char msg[160]; snprintf(msg,sizeof msg,"ex01 strncmp(%u,\"%s\",\"%s\")", n,a,b);
		assert_int_eq(got,exp,msg);
	}
	data_free(&t);
}
#endif

/* ex02 strcat */
#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex02_strcat",'|',&t)!=0){ printf("WARN no data [ex02_strcat]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *base=t.rows[i].cols[0], *add=t.rows[i].cols[1], *want=t.rows[i].cols[2];
		char buf[512]; memset(buf,0,sizeof buf); strcpy(buf,base);
#if TEST_VERBOSE
		printf("ex02[%d] BEFORE \"%s\"\n", i, buf);
#endif
		char *ret=ft_strcat(buf,(char*)add);
#if TEST_VERBOSE
		printf("ex02[%d] AFTER  \"%s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex02 ret==dest");
		assert_str_eq(buf,want,"ex02 content");
	}
	data_free(&t);
}
#endif

/* ex03 strncat */
#ifdef HAVE_EX03
static void test_ex03(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex03_strncat",'|',&t)!=0){ printf("WARN no data [ex03_strncat]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *base=t.rows[i].cols[0], *add=t.rows[i].cols[1]; unsigned n=(unsigned)strtoul(t.rows[i].cols[2],NULL,10);
		const char *want=t.rows[i].cols[3];
		char buf[512]; memset(buf,0,sizeof buf); strcpy(buf,base);
#if TEST_VERBOSE
		printf("ex03[%d] BEFORE \"%s\"\n", i, buf);
#endif
		char *ret=ft_strncat(buf,(char*)add,n);
#if TEST_VERBOSE
		printf("ex03[%d] AFTER  \"%s\"\n", i, buf);
#endif
		assert_true(ret==buf,"ex03 ret==dest");
		assert_str_eq(buf,want,"ex03 content");
	}
	data_free(&t);
}
#endif

/* ex04 strstr */
#ifdef HAVE_EX04
static void test_ex04(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex04_strstr",'|',&t)!=0){ printf("WARN no data [ex04_strstr]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *hay=t.rows[i].cols[0], *needle=t.rows[i].cols[1];
		int exp_idx = atoi(t.rows[i].cols[2]); /* -1 for NULL */
		char buf[512]; strcpy(buf, hay);
		char *p = ft_strstr(buf,(char*)needle);
		if (exp_idx<0) assert_true(p==NULL,"ex04 strstr -> NULL");
		else           assert_true(p==buf+exp_idx,"ex04 strstr index");
	}
	data_free(&t);
}
#endif

/* ex05 strlcat */
#ifdef HAVE_EX05
static void test_ex05(void)
{
	t_data_table t; if (data_load_section(DATA_PATH,"ex05_strlcat",'|',&t)!=0){ printf("WARN no data [ex05_strlcat]\n"); return; }
	for(int i=0;i<t.count;i++){
		const char *dst0=t.rows[i].cols[0], *src=t.rows[i].cols[1];
		unsigned size=(unsigned)strtoul(t.rows[i].cols[2],NULL,10);
		const char *want_dst=t.rows[i].cols[3]; unsigned want_ret=(unsigned)strtoul(t.rows[i].cols[4],NULL,10);
		char buf[256]; memset(buf,0,sizeof buf); strncpy(buf,dst0,sizeof buf-1);
#if TEST_VERBOSE
		printf("ex05[%d] BEFORE dst=\"%s\"\n", i, buf);
#endif
		unsigned ret=ft_strlcat(buf,(char*)src,size);
#if TEST_VERBOSE
		printf("ex05[%d] AFTER  dst=\"%s\" ret=%u\n", i, buf, ret);
#endif
		assert_int_eq((int)ret,(int)want_ret,"ex05 return");
		assert_str_eq(buf,want_dst,"ex05 dst");
	}
	data_free(&t);
}
#endif

void test_C03(void)
{
	t_set_suite("C03");
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
