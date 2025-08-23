#include "../common/assert.h"
#include "../common/data.h"
#include "../common/list_helpers.h"
#include "ft_stock_str.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ————— ex00 : ft.h ————— */
#ifdef HAVE_EX00
# include "../C08/ex00/ft.h"
static void test_ex00(void)
{
	/* compile-only presence check */
	assert_true(1, "ex00 ft.h present");
}
#endif

/* ————— ex01 : ft_boolean.h ————— */
#ifdef HAVE_EX01
# include "../C08/ex01/ft_boolean.h"
static void test_ex01(void)
{
	t_bool b;

	b = EVEN(2);
	assert_true(b == TRUE, "ex01 EVEN(2) is TRUE");
	b = EVEN(3);
	assert_true(b == FALSE, "ex01 EVEN(3) is FALSE");
}
#endif

/* ————— ex02 : ft_abs.h ————— */
#ifdef HAVE_EX02
# include "../C08/ex02/ft_abs.h"
static void test_ex02(void)
{
	assert_int_eq(ABS(-42), 42, "ex02 ABS(-42)=42");
	assert_int_eq(ABS(5), 5, "ex02 ABS(5)=5");
}
#endif

/* ————— ex03 : ft_point.h ————— */
#ifdef HAVE_EX03
# include "../C08/ex03/ft_point.h"
static void test_ex03(void)
{
	t_point p;

	p.x = 42;
	p.y = 21;
	assert_int_eq(p.x, 42, "ex03 point.x=42");
	assert_int_eq(p.y, 21, "ex03 point.y=21");
}
#endif

/* ————— ex04/05 : need ft_stock_str.h ————— */
#if defined(HAVE_EX04) || defined(HAVE_EX05)
# include "ft_stock_str.h"
#endif

/* ex04 : ft_strs_to_tab */
#ifdef HAVE_EX04
struct s_stock_str *ft_strs_to_tab(int ac, char **av);
static void test_ex04(void)
{
	char *av[] = {"hello", "world", "!"};
	struct s_stock_str *tab = ft_strs_to_tab(3, av);

	assert_true(tab != NULL, "ex04 returns non-NULL");
	if (!tab)
		return;
	for (int i = 0; i < 3; ++i)
	{
		assert_int_eq((size_t)tab[i].size, strlen(av[i]), "ex04 size ok");
		assert_str_eq(tab[i].str, av[i], "ex04 str points to input");
		assert_true(tab[i].copy != NULL, "ex04 copy non-NULL");
		assert_str_eq(tab[i].copy, av[i], "ex04 copy matches");
		free(tab[i].copy);
	}
	assert_true(tab[3].str == 0, "ex04 sentinel str==0");
	free(tab);
}
#endif

/* ex05 : ft_show_tab (no strict stdout check here: “no crash”) */
#ifdef HAVE_EX05
void ft_show_tab(struct s_stock_str *par);
static void test_ex05(void)
{
	char *av[] = {"hi", "there"};
	struct s_stock_str t[3];

	t[0].str = av[0]; t[0].copy = av[0]; t[0].size = (int)strlen(av[0]);
	t[1].str = av[1]; t[1].copy = av[1]; t[1].size = (int)strlen(av[1]);
	t[2].str = 0;     t[2].copy = 0;     t[2].size = 0;
	ft_show_tab(t); /* should not crash */
	assert_true(1, "ex05 show_tab no-crash");
}
#endif

/* ————— Aggregator ————— */
void	test_C08(void)
{
	t_set_suite("C08");
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
