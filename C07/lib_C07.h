#ifndef LIB_C07_H
# define LIB_C07_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RESET "\033[0;0m"

typedef enum e_test_type {
	TEST_STRDUP,
	TEST_RANGE,
	TEST_ULTIMATE_RANGE,
	TEST_STRJOIN,
	TEST_CONVERT_BASE,
	TEST_SPLIT
} t_test_type;

typedef struct s_test {
	t_test_type	type;
	char		*desc;
	void		*args;
	union {
		int		expected_int;
		char	*expected_str;
	};
} t_test;

typedef struct s_args_math {
	int		index;
	int		expec;
	char	*msg;
} t_args_math;

typedef struct s_args_power {
	int		index;
	int		power;
	int		expec;
	char	*msg;
} t_args_power;

typedef struct s_args_strdup {
	char	*src;
} t_args_strdup;



int run_test(t_test test);

// EX00
// EX01
// EX02
// EX03
// EX04
// EX05
char **ft_split(char *str, char *charset);


#endif