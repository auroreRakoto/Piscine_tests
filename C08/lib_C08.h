#ifndef LIB_C08_H
# define LIB_C08_H

# include <stdio.h>
# include <signal.h>

typedef struct s_stock_str{
 int	size;
 char	*str;
 char	*copy;
}	t_stock_str;

/* Pretty colors for terminals*/
# define RED    "\033[0;31m"
# define GREEN  "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RESET  "\033[0;0m"


/* ---------------- Test ---------------- */
typedef enum e_test_type {
	TEST_FT_H,				/* ex00 */
	TEST_BOOLEAN_H,			/* ex01 */
	TEST_ABS_H,				/* ex02 */
	TEST_POINT_H,			/* ex03 */
	TEST_STRS_TO_TAB,		/* ex04 */
	TEST_SHOW_TAB			/* ex05 */
} t_test_type;


typedef struct s_test {
	t_test_type type;
	const char		*desc;      /* short description */
	void			*args;
	union {
		int			expected_int;
		const char	*expected_str;
	};
} t_test;

/* ---------------- Args per exercise ---------------- */
/* ex00: ft_h */
typedef struct s_args_strdup {
	char	*src1;
	char	*src2;
	char	c;
	int		*a;
	int		*b;
} t_args_ft_h;

/* ex01: boolean_h */
typedef struct s_args_strdup {
	char	*src1;
	char	*src2;
	char	c;
	int		*a;
	int		*b;
} t_args_boolean_h;

/* ex02: ft_h */
typedef struct s_args_strdup {
	char	*src1;
	char	*src2;
	char	c;
	int		*a;
	int		*b;
} t_args_strdup;

/* ex03: ft_h */
typedef struct s_args_strdup {
	char	*src1;
	char	*src2;
	char	c;
	int		*a;
	int		*b;
} t_args_strdup;

/* ex04: ft_h */
typedef struct s_args_strdup {
	char	*src1;
	char	*src2;
	char	c;
	int		*a;
	int		*b;
} t_args_strdup;

/* Allow missing functions */
#if defined(__GNUC__) || defined(__clang__)
char	*ft_strdup(char *src) __attribute__((weak));
int		*ft_range(int min, int max) __attribute__((weak));
int		ft_ultimate_range(int **range, int min, int max) __attribute__((weak));
char	*ft_strjoin(int, char **, char *) __attribute__((weak));
char	*ft_convert_base(char *, char *, char *) __attribute__((weak));
char	**ft_split(char *, char *) __attribute__((weak));
#endif

#endif