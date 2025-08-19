#include "../common/assert.h"
#include <string.h>
#include <stdlib.h>

/* --------- Prototypes (guarded per ex) --------- */
#ifdef HAVE_EX00
void	ft_foreach(int *tab, int length, void (*f)(int));
#endif
#ifdef HAVE_EX01
int		*ft_map(int *tab, int length, int (*f)(int));
#endif
#ifdef HAVE_EX02
int		ft_any(char **tab, int (*f)(char *));
#endif
#ifdef HAVE_EX03
int		ft_count_if(char **tab, int length, int (*f)(char *));
#endif
#ifdef HAVE_EX04
int		ft_is_sort(int *tab, int length, int (*f)(int,int));
#endif
#ifdef HAVE_EX06
void	ft_sort_string_tab(char **tab);
#endif
#ifdef HAVE_EX07
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char*, char*));
#endif

/* ========================= ex00: ft_foreach ========================= */
#ifdef HAVE_EX00
static int g_sum;
static void add_to_sum(int x) { g_sum += x; }

static void test_ex00(void)
{
	int v[] = {1, 2, 3, 4};
	g_sum = 0;
	ft_foreach(v, 4, &add_to_sum);
	assert_int_eq(g_sum, 10, "ex00 foreach sum=10");

	g_sum = 0;
	ft_foreach(v, 0, &add_to_sum);
	assert_int_eq(g_sum, 0, "ex00 foreach length=0");
}
#endif

/* ========================= ex01: ft_map ============================= */
#ifdef HAVE_EX01
static int square(int x) { return x * x; }
static int arr_eq(const int *a, const int *b, int n)
{
	for (int i = 0; i < n; ++i)
		if (a[i] != b[i]) return 0;
	return 1;
}

static void test_ex01(void)
{
	int in[]  = {1, 2, 3, 4};
	int exp[] = {1, 4, 9, 16};
	int *out  = ft_map(in, 4, &square);

	assert_true(out != NULL, "ex01 map returns non-NULL");
	if (out)
	{
		assert_true(arr_eq(out, exp, 4), "ex01 map squares ok");
		free(out);
	}
}
#endif

/* ========================= ex02: ft_any ============================= */
#ifdef HAVE_EX02
static int has_a(char *s)
{
	if (!s) return 0;
	for (; *s; ++s)
		if (*s == 'a' || *s == 'A') return 1;
	return 0;
}

static void test_ex02(void)
{
	char *tab1[] = {"hello", "world", "!", NULL};
	char *tab2[] = {"hello", "Aurore", "!", NULL};

	assert_int_eq(ft_any(tab1, &has_a), 0, "ex02 any: no 'a'");
	assert_int_eq(ft_any(tab2, &has_a), 1, "ex02 any: has 'a'");
}
#endif

/* ========================= ex03: ft_count_if ======================== */
#ifdef HAVE_EX03
static int non_empty(char *s) { return (s && *s) ? 1 : 0; }

static void test_ex03(void)
{
	char *tab[]  = {"", "a", "bb", "abc"};
	char *tab2[] = {"", "", ""};

	assert_int_eq(ft_count_if(tab, 4, &non_empty), 3, "ex03 count_if length=4");
	assert_int_eq(ft_count_if(tab2, 3, &non_empty), 0, "ex03 count_if none");
}
#endif

/* ========================= ex04: ft_is_sort ========================= */
#ifdef HAVE_EX04
static int cmp_std(int a, int b) { return (a - b); }
static int cmp_rev(int a, int b) { return (b - a); }

static void test_ex04(void)
{
	int asc_ok[]  = {1, 2, 2, 3, 5};
	int desc_ok[] = {9, 7, 7, 1, -3};
	int bad[]     = {1, 3, 2, 4};

	assert_int_eq(ft_is_sort(asc_ok, 5, &cmp_std), 1, "ex04 is_sort ascending");
	assert_int_eq(ft_is_sort(desc_ok, 5, &cmp_rev), 1, "ex04 is_sort descending");
	assert_int_eq(ft_is_sort(bad, 4, &cmp_std), 0, "ex04 is_sort not sorted");
}
#endif

/* ========================= ex06: ft_sort_string_tab ================= */
#ifdef HAVE_EX06
static int strtab_eq(char **a, char **b)
{
	int i = 0;
	for (;; ++i)
	{
		if ((a[i] == NULL) != (b[i] == NULL)) return 0;
		if (a[i] == NULL) break;
		if (strcmp(a[i], b[i]) != 0) return 0;
	}
	return 1;
}

static void test_ex06(void)
{
	char *tab[] = {"banana", "apple", "pear", "apple", NULL};
	char *exp[] = {"apple", "apple", "banana", "pear", NULL};

	ft_sort_string_tab(tab);
	assert_true(strtab_eq(tab, exp), "ex06 sort_string_tab ascii order");
}
#endif

/* ========================= ex07: ft_advanced_sort_string_tab ======== */
#ifdef HAVE_EX07
static int cmp_str(char *a, char *b) { return strcmp(a, b); }
static int cmp_str_rev(char *a, char *b) { return -strcmp(a, b); }
static int strtab_eq2(char **a, char **b)
{
	int i = 0;
	for (;; ++i)
	{
		if ((a[i] == NULL) != (b[i] == NULL)) return 0;
		if (a[i] == NULL) break;
		if (strcmp(a[i], b[i]) != 0) return 0;
	}
	return 1;
}

static void test_ex07(void)
{
	char *tab1[] = {"banana", "apple", "pear", "apple", NULL};
	char *exp1[] = {"apple", "apple", "banana", "pear", NULL};
	ft_advanced_sort_string_tab(tab1, &cmp_str);
	assert_true(strtab_eq2(tab1, exp1), "ex07 advanced_sort strcmp asc");

	char *tab2[] = {"banana", "apple", "pear", "apple", NULL};
	char *exp2[] = {"pear", "banana", "apple", "apple", NULL};
	ft_advanced_sort_string_tab(tab2, &cmp_str_rev);
	assert_true(strtab_eq2(tab2, exp2), "ex07 advanced_sort custom desc");
}
#endif

/* ========================= Aggregator =============================== */
void test_C11(void)
{
	t_set_suite("C11");
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
#ifdef HAVE_EX06
	test_ex06();
#endif
#ifdef HAVE_EX07
	test_ex07();
#endif
	t_summary();
}
