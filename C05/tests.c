#include "../common/assert.h"
#include "../common/data.h"
#include <unistd.h>

#ifndef DATA_PATH
# define DATA_PATH "C05/data.txt"
#endif

#ifdef HAVE_EX00
int	ft_iterative_factorial(int nb);
#endif
#ifdef HAVE_EX01
int	ft_recursive_factorial(int nb);
#endif
#ifdef HAVE_EX02
int	ft_iterative_power(int nb, int power);
#endif
#ifdef HAVE_EX03
int	ft_recursive_power(int nb, int power);
#endif
#ifdef HAVE_EX04
int	ft_fibonacci(int index);
#endif
#ifdef HAVE_EX05
int	ft_sqrt(int nb);
#endif
#ifdef HAVE_EX06
int	ft_is_prime(int nb);
#endif
#ifdef HAVE_EX07
int	ft_find_next_prime(int nb);
#endif
#ifdef HAVE_EX08
int	ft_ten_queens_puzzle(void);
#endif

static int	s_len(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	s_warn_no_data(const char *tag)
{
	const char	*p1;
	const char	*p2;

	p1 = "WARN no data [";
	p2 = "]\n";
	write(2, p1, s_len(p1));
	write(2, tag, s_len(tag));
	write(2, p2, s_len(p2));
}

static void	s_run_pairs(const char *sect, int (*fn)(int), const char *label)
{
	t_data_table	t;
	int				i;
	int				a;
	int				exp;

	if (data_load_section(DATA_PATH, sect, '|', &t) != 0)
	{
		s_warn_no_data(sect);
		return ;
	}
	i = 0;
	while (i < t.count)
	{
		if (safe_atoi(t.rows[i].cols[0], &a)
			&& safe_atoi(t.rows[i].cols[1], &exp))
			assert_int_eq(fn(a), exp, (char *)label);
		i++;
	}
	data_free(&t);
}

static void	s_run_triplet(const char *sect,
	int (*fn)(int, int), const char *label)
{
	t_data_table	t;
	int				i;
	int				a;
	int				b;
	int				exp;

	if (data_load_section(DATA_PATH, sect, '|', &t) != 0)
	{
		s_warn_no_data(sect);
		return ;
	}
	i = 0;
	while (i < t.count)
	{
		if (safe_atoi(t.rows[i].cols[0], &a)
			&& safe_atoi(t.rows[i].cols[1], &b)
			&& safe_atoi(t.rows[i].cols[2], &exp))
			assert_int_eq(fn(a, b), exp, (char *)label);
		i++;
	}
	data_free(&t);
}

#ifdef HAVE_EX00
static void	test_ex00(void)
{
	s_run_pairs("ex00_iter_fact", &ft_iterative_factorial, "iter_fact");
}
#endif

#ifdef HAVE_EX01
static void	test_ex01(void)
{
	s_run_pairs("ex01_rec_fact", &ft_recursive_factorial, "rec_fact");
}
#endif

#ifdef HAVE_EX02
static void	test_ex02(void)
{
	s_run_triplet("ex02_iter_pow", &ft_iterative_power, "iter_pow");
}
#endif

#ifdef HAVE_EX03
static void	test_ex03(void)
{
	s_run_triplet("ex03_rec_pow", &ft_recursive_power, "rec_pow");
}
#endif

#ifdef HAVE_EX04
static void	test_ex04(void)
{
	s_run_pairs("ex04_fibo", &ft_fibonacci, "fibo");
}
#endif

#ifdef HAVE_EX05
static void	test_ex05(void)
{
	s_run_pairs("ex05_sqrt", &ft_sqrt, "sqrt");
}
#endif

#ifdef HAVE_EX06
static void	test_ex06(void)
{
	s_run_pairs("ex06_is_prime", &ft_is_prime, "is_prime");
}
#endif

#ifdef HAVE_EX07
static void	test_ex07(void)
{
	s_run_pairs("ex07_next_prime", &ft_find_next_prime, "next_prime");
}
#endif

#ifdef HAVE_EX08
static void	test_ex08(void)
{
	assert_int_eq(ft_ten_queens_puzzle(), 724, "ten_queens");
}
#endif

void	test_C05(void)
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
