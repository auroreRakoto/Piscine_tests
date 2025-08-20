
#include "../common/assert.h"
#include "../common/data.h"
#include "../common/list_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef DATA_PATH
# define DATA_PATH "C07/data.txt"
#endif
#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

/* -------- Prototypes (guarded by HAVE_EXNN) -------- */
#ifdef HAVE_EX00
char *ft_strdup(char *src);
#endif
#ifdef HAVE_EX01
int  *ft_range(int min, int max);
#endif
#ifdef HAVE_EX02
int   ft_ultimate_range(int **range, int min, int max);
#endif
#ifdef HAVE_EX03
char *ft_strjoin(int size, char **strs, char *sep);
#endif
#ifdef HAVE_EX04
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
#endif
#ifdef HAVE_EX05
char **ft_split(char *str, char *charset);
#endif

/* -------- helpers -------- */
static int *csv_to_ints(const char *csv, int *out_n)
{
	char **tok = lh_split_csv_trim(csv, out_n);
	if (!tok) { if (out_n) *out_n = 0; return NULL; }
	int n = *out_n;
	int *a = (int *)malloc(sizeof(int) * (size_t)n);
	if (!a) { lh_free_tokens(tok, n); *out_n = 0; return NULL; }
	for (int i = 0; i < n; ++i) a[i] = atoi(tok[i]);
	lh_free_tokens(tok, n);
	return a;
}

static int intv_eq(const int *a, int na, const int *b, int nb)
{
	if (na != nb) return 0;
	for (int i = 0; i < na; ++i) if (a[i] != b[i]) return 0;
	return 1;
}

#if TEST_VERBOSE
static void print_intv(const char *label, const int *v, int n)
{
	printf("%s: [", label ? label : "");
	for (int i = 0; i < n; ++i)
	{
		if (i) printf(", ");
		printf("%d", v[i]);
	}
	printf("] (len=%d)\n", n);
}
#endif

/* ================= ex00: ft_strdup ================= */
#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex00_strdup", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex00_strdup] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *src = t.rows[i].cols[0];
		char *dup = ft_strdup((char *)(*src ? src : ""));
#if TEST_VERBOSE
		printf("ex00[%d] src=\"%s\" dup=\"%s\"\n", i, *src ? src : "(empty)", dup ? dup : "(null)");
#endif
		assert_true(dup != NULL, "ex00 strdup non-NULL");
		if (dup)
		{
			assert_str_eq(dup, (*src ? src : ""), "ex00 content matches");
			if (dup == src) assert_true(0, "ex00 must allocate (pointer must differ)");
			free(dup);
		}
	}
	data_free(&t);
}
#endif

/* ================= ex01: ft_range ================= */
#ifdef HAVE_EX01
static void test_ex01(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex01_range", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex01_range] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		int min = atoi(t.rows[i].cols[0]);
		int max = atoi(t.rows[i].cols[1]);
		const char *exp_csv = t.rows[i].cols[2];

		int exp_n = 0;
		int *exp = csv_to_ints(exp_csv, &exp_n);

		int *arr = ft_range(min, max);
		int got_n = (max > min) ? (max - min) : 0;

#if TEST_VERBOSE
		if (arr) print_intv("ex01 AFTER range", arr, got_n);
		else     printf("ex01 AFTER range: (null)\n");
#endif
		if (got_n == 0)
			assert_true(arr == NULL, "ex01 min>=max -> NULL");
		else
		{
			assert_true(arr != NULL, "ex01 non-NULL");
			if (arr && exp)
				assert_true(intv_eq(arr, got_n, exp, exp_n), "ex01 content ok");
		}
		free(arr);
		free(exp);
	}
	data_free(&t);
}
#endif

/* ================= ex02: ft_ultimate_range ================= */
#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex02_ultimate_range", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex02_ultimate_range] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		int min = atoi(t.rows[i].cols[0]);
		int max = atoi(t.rows[i].cols[1]);
		const char *exp_csv = t.rows[i].cols[2];

		int exp_n = 0;
		int *exp = csv_to_ints(exp_csv, &exp_n);

		int *buf = NULL;
		int len = ft_ultimate_range(&buf, min, max);

#if TEST_VERBOSE
		if (buf) print_intv("ex02 AFTER ult_range", buf, len);
		else     printf("ex02 AFTER ult_range: (null)\n");
#endif

		if (min >= max)
		{
			assert_int_eq(len, 0, "ex02 min>=max -> ret 0");
			assert_true(buf == NULL, "ex02 min>=max -> *range NULL");
		}
		else
		{
			assert_true(len == exp_n || len == -1, "ex02 ret length or -1");
			if (len >= 0)
			{
				assert_true(buf != NULL, "ex02 non-NULL buf");
				if (buf && exp) assert_true(intv_eq(buf, len, exp, exp_n), "ex02 content ok");
			}
		}
		free(buf);
		free(exp);
	}
	data_free(&t);
}
#endif

/* ================= ex03: ft_strjoin ================= */
#ifdef HAVE_EX03
static void test_ex03(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex03_strjoin", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex03_strjoin] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		int size = atoi(t.rows[i].cols[0]);
		const char *csv = t.rows[i].cols[1];
		char *sep = (char *)t.rows[i].cols[2];
		const char *want = t.rows[i].cols[3];

		int n = 0;
		char **tok = lh_split_csv_trim(csv, &n);
		if (size < 0 || size > n) size = n;

		char *res = ft_strjoin(size, tok, sep);

#if TEST_VERBOSE
		printf("ex03[%d] join size=%d sep=\"%s\" -> \"%s\"\n", i, size, sep, res ? res : "(null)");
#endif
		assert_true(res != NULL, "ex03 non-NULL");
		if (res) assert_str_eq(res, want, "ex03 result matches");

		free(res);
		lh_free_tokens(tok, n);
	}
	data_free(&t);
}
#endif

/* ================= ex04: ft_convert_base ================= */
#ifdef HAVE_EX04
static void test_ex04(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex04_convert_base", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex04_convert_base] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		char *nbr = (char *)t.rows[i].cols[0];
		char *bfrom = (char *)t.rows[i].cols[1];
		char *bto   = (char *)t.rows[i].cols[2];
		const char *want = t.rows[i].cols[3];

		char *res = ft_convert_base(nbr, bfrom, bto);

#if TEST_VERBOSE
		printf("ex04[%d] \"%s\" (%s)->(%s) -> \"%s\"\n", i, nbr, bfrom, bto, res ? res : "(null)");
#endif
		assert_true(res != NULL, "ex04 non-NULL");
		if (res) assert_str_eq(res, want, "ex04 converted ok");
		free(res);
	}
	data_free(&t);
}
#endif

/* ================= ex05: ft_split ================= */
#ifdef HAVE_EX05
static void test_ex05(void)
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

/* -------- aggregator -------- */
void test_C07(void)
{
	t_set_suite("C07");
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
