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

// TEST
void			assert_str(char *expected, char *actual, char *msg);
void			assert_int(int expected, int actual, char *msg);
void			assert_self(int expected, int actual, char *msg);

// EX06
void			run_test_ft_is_prime();
int				ft_is_prime(char *str);

// EX07
void			run_test_ft_is_next_prime();
void			ft_is_next_prime(int nbr, char *base);

// EX08
void			run_test_ft_ten_queens_puzzle();
int				ft_ten_queens_puzzle(char *str, char *base);
#endif