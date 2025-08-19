#include "assert.h"
#include <stdio.h>
#include <string.h>

static unsigned long g_total = 0;
static unsigned long g_failed = 0;
static const char   *g_suite = NULL;

#define C_GREEN  "\x1b[32m"
#define C_RED    "\x1b[31m"
#define C_BOLD   "\x1b[1m"
#define C_RESET  "\x1b[0m"

static void	report(int ok, const char *msg)
{
	g_total++;
	if (ok)
		printf("  " C_GREEN "✔" C_RESET " %s\n", msg ? msg : "(no message)");
	else
	{
		g_failed++;
		printf("  " C_RED "✘" C_RESET " %s\n", msg ? msg : "(no message)");
	}
}

void	t_set_suite(const char *name)
{
	g_suite = name;
	if (g_suite && *g_suite)
		printf(C_BOLD "%s" C_RESET "\n", g_suite);
}

void	t_reset(void)
{
	g_total = 0;
	g_failed = 0;
}

static void	print_summary(void)
{
	unsigned long passed = g_total - g_failed;
	printf(C_BOLD "Summary:" C_RESET " %lu passed, %lu failed, %lu total\n",
		passed, g_failed, g_total);
}

int	t_summary(void)
{
	print_summary();
	return (int)g_failed;
}

int	assert_true(int cond, const char *msg)
{
	report(cond != 0, msg);
	return (cond ? 0 : -1);
}

int	assert_int_eq(long got, long expected, const char *msg)
{
	int ok = (got == expected);
	report(ok, msg);
	if (!ok)
		printf("     got=%ld expected=%ld\n", got, expected);
	return (ok ? 0 : -1);
}
/*
int	assert_size_eq(size_t got, size_t expected, const char *msg)
{
	int ok = (got == expected);
	report(ok, msg);
	if (!ok)
		printf("     got=%llu expected=%llu\n",
			(unsigned long long)got, (unsigned long long)expected);
	return (ok ? 0 : -1);
}
*/
int	assert_str_eq(const char *got, const char *expected, const char *msg)
{
	int ok = (got && expected) ? (strcmp(got, expected) == 0) : (got == expected);
	report(ok, msg);
	if (!ok)
	{
		printf("     got=\"%s\"\n", got ? got : "(null)");
		printf("     expected=\"%s\"\n", expected ? expected : "(null)");
	}
	return (ok ? 0 : -1);
}
/*
int	assert_mem_eq(const void *a, const void *b, size_t n, const char *msg)
{
	int ok = (memcmp(a, b, n) == 0);
	report(ok, msg);
	if (!ok)
		printf("     first %llu bytes differ\n", (unsigned long long)n);
	return (ok ? 0 : -1);
}
*/

/* --- Legacy compatibility (from older tests / lib_C04.h) --- */
int	assert_int(int expected, int actual, char *msg)
{
	return assert_int_eq((long)actual, (long)expected, msg);
}

int	assert_str(char *expected, char *actual, char *msg)
{
	return assert_str_eq((const char *)actual, (const char *)expected, msg);
}

int	assert_self(int expected, int actual, char *msg)
{
	return assert_int(expected, actual, msg);
}
