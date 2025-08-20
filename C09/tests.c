
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

/* ================= ex02: ft_split ================= */
#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex05_split", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex05_split] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		char *str = (char *)t.rows[i].cols[0];
		char *charset = (char *)t.rows[i].cols[1];
		const char *exp_csv = t.rows[i].cols[2];

		int exp_n = 0;
		char **exp = lh_split_csv_trim(exp_csv, &exp_n);

#if TEST_VERBOSE
		printf("ex05[%d] BEFORE split \"%s\" by \"%s\"\n", i, str, charset);
#endif
		char **out = ft_split(str, charset);
#if TEST_VERBOSE
		printf("ex05[%d] AFTER  tokens:", i);
		if (!out) printf(" (null)\n");
		else {
			printf(" [");
			for (int k=0; out[k]; ++k){ if(k) printf(", "); printf("\"%s\"", out[k]); }
			printf("]\n");
		}
#endif
		/* count */
		int n = 0; if (out) while (out[n]) ++n;
		assert_int_eq(n, exp_n, "ex05 token count");
		/* compare */
		for (int k = 0; k < exp_n; ++k)
			assert_str_eq(out[k], exp[k], "ex05 token matches");

		/* free result */
		if (out)
		{
			for (int k = 0; out[k]; ++k) free(out[k]);
			free(out);
		}
		lh_free_tokens(exp, exp_n);
	}
	data_free(&t);
}
#endif

/* ================= ex02: ft_split ================= */
#ifdef HAVE_EX02
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
#ifdef HAVE_EX02
	test_ex02();
#else
	printf("C09: no ex01 sources detected; skipping function tests.\n");
#endif
	t_summary();
}
