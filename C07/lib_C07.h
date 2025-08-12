#ifndef LIB_C07_H
# define LIB_C07_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <signal.h>
# include <stddef.h>

/* Pretty colors for terminals that support ANSI */
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RESET  "\033[0;0m"


/* ---------------- Test taxonomy ---------------- */
typedef enum e_test_type {
	TEST_STRDUP,       /* ex00 */
	TEST_RANGE,            /* ex01 */
	TEST_ULTIMATE_RANGE,   /* ex02 */
	TEST_STRJOIN,          /* ex03 */
	TEST_CONVERT_BASE,     /* ex04 */
	TEST_SPLIT             /* ex05 */
} t_test_type;

/* Generic test record */
typedef struct s_test {
	t_test_type type;
	const char *desc;      /* short description */
	void       *args;      /* points to the right args-struct per type */
	union {
		int         expected_int;
		const char *expected_str;
	};
} t_test;

/* ---------------- Args per exercise ---------------- */
/* ex00: ft_strdup */
typedef struct s_args_strdup {
	const char *src;
} t_args_strdup;

/* ex01: ft_range */
typedef struct s_args_range {
	int min;
	int max;
	const int *expected; /* NULL if min>=max */
	int expected_len;    /* max-min (or 0) */
} t_args_range;

/* ex02: ft_ultimate_range */
typedef struct s_args_urange {
	int min;
	int max;
	const int *expected; /* NULL if min>=max */
	int expected_len;    /* function should return this */
} t_args_urange;

/* ex03: ft_strjoin */
typedef struct s_args_strjoin {
	int size;
	char **strs;
	char *sep;
} t_args_strjoin;

/* ex04: ft_convert_base */
typedef struct s_args_convert {
	char *nbr;
	char *base_from;
	char *base_to;
} t_args_convert;

/* ex05: ft_split */
typedef struct s_args_split {
	char *str;
	char *charset;
	const char **expected; /* NULL-terminated list of expected tokens */
} t_args_split;



/* ---------------- Prototypes from C07 subject ---------------- */
/* ex00 */ char	*ft_strdup(char *src);
/* ex01 */ int	*ft_range(int min, int max);
/* ex02 */ int	ft_ultimate_range(int **range, int min, int max);
/* ex03 */ char	*ft_strjoin(int size, char **strs, char *sep);
/* ex04 */ char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
/* ex05 */ char	**ft_split(char *str, char *charset);

/* Allow missing functions without link errors (GCC/Clang) */
#if defined(__GNUC__) || defined(__clang__)
char	*ft_strdup(char *src) __attribute__((weak));
int		*ft_range(int min, int max) __attribute__((weak));
int		ft_ultimate_range(int **range, int min, int max) __attribute__((weak));
char	*ft_strjoin(int, char **, char *) __attribute__((weak));
char	*ft_convert_base(char *, char *, char *) __attribute__((weak));
char	**ft_split(char *, char *) __attribute__((weak));
#endif


/* ---------------- Test runner entry ---------------- */
int		run_test(t_test test);
void	install_segv_handler(void);
void	set_current_test(const char *desc);

/* ---------------- Assert Function ---------------- */
void			assert_str(char *expected, char *actual, char *msg);
void			assert_int(int expected, int actual, char *msg);
void			assert_self(int expected, int actual, char *msg);


#endif /* LIB_C07_H */