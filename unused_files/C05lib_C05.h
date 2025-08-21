#ifndef LIB_C05_H
# define LIB_C05_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RESET "\033[0;0m"

typedef enum e_test_type {
	TEST_IT_FACTO,
	TEST_REC_FACTO,
	TEST_IT_POWER,
	TEST_REC_POWER,
	TEST_FIBONACCI,
	TEST_SQRT,
	TEST_FIND_PRIME,
	TEST_NEXT_PRIME,
	TEST_TEN_QUEENS,
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



// TEST
void			assert_str(char *expected, char *actual, char *msg);
void			assert_int(int expected, int actual, char *msg);
void			assert_self(int expected, int actual, char *msg);

int run_test(t_test test);
// EX00
int ft_iterative_factorial(int nb);
// EX01
int ft_recursive_factorial(int nb);
// EX02
int ft_iterative_power(int nb, int power);
// EX03
int ft_recursive_power(int nb, int power);
// EX04
int				ft_fibonacci(int index);
// EX05
int ft_sqrt(int nb);
// EX06
//void			run_test_ft_is_prime();
int				ft_is_prime(int nb);

// EX07
//void			run_test_ft_is_next_prime();
int				ft_find_next_prime(int nbr);

// EX08
//void			run_test_ft_ten_queens_puzzle();
int				ft_ten_queens_puzzle();
#endif