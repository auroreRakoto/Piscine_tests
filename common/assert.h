#ifndef ASSERT_H
#define ASSERT_H

#include <stddef.h>

/* Optional: set a suite name printed once at the start */
void	t_set_suite(const char *name);
/* Reset counters (useful when running multiple groups) */
void	t_reset(void);
/* Print summary and return number of failures */
int		t_summary(void);

/* Basic assertions: return 0 on success, -1 on failure */
int		assert_true(int cond, const char *msg);
int		assert_int_eq(long got, long expected, const char *msg);
int		assert_size_eq(size_t got, size_t expected, const char *msg);
int		assert_str_eq(const char *got, const char *expected, const char *msg);
int		assert_mem_eq(const void *a, const void *b, size_t n, const char *msg);
/* Legacy helpers kept for backward-compat with older tests */
int		assert_int(int expected, int actual, char *msg);
int		assert_str(char *expected, char *actual, char *msg);
int		assert_self(int expected, int actual, char *msg);

#endif /* ASSERT_H */
