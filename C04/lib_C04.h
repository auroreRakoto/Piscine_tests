#ifndef LIB_C04_H
# define LIB_C04_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define ORANGE "\033[0;33m"
# define RESET "\033[0;0m"

// TEST
int			assert_str(char *expected, char *actual, char *msg);
int			assert_int(int expected, int actual, char *msg);
int			assert_self(int expected, int actual, char *msg);

// EX03
void			run_test_ft_atoi();
int				ft_atoi(char *str);

// EX04
void			run_test_ft_putnbr_base();
void			ft_putnbr_base(int nbr, char *base);

// EX05
void			run_test_ft_atoi_base();
int				ft_atoi_base(char *str, char *base);
#endif