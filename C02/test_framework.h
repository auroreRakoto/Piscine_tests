#ifndef TEST_FRAMEWORK_H
# define TEST_FRAMEWORK_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define ORANGE	"\033[0;33m"
# define RESET	"\033[0;0m"

extern FILE	*log_file;

void			assert_str(char *expected, char *actual, char *message);
void			assert_int(int expected, int actual, char *message);
void			assert_uint(unsigned int expected, unsigned int actual, char *message);

// EX00
char			*ft_strcpy(char *dest, char *src);
void			run_test_ft_strcpy();
// EX01
char			*ft_strncpy(char *dest, char *src, unsigned int n);
void			run_test_ft_strncpy();
// EX02
int				ft_str_is_alpha(char *str);
void			run_test_ft_str_is_alpha();
// EX03
int				ft_str_is_numeric(char *str);
void			run_test_ft_str_is_numeric();
// EX04
int				ft_str_is_lowercase(char *str);
void			run_test_ft_str_is_lowercase();
// EX05
int				ft_str_is_uppercase(char *str);
void			run_test_ft_str_is_uppercase();
// EX06
int				ft_str_is_printable(char *str);
void			run_test_ft_str_is_printable();
// EX07
char			*ft_strupcase(char *str);
void			run_test_ft_strupcase();
// EX08
char			*ft_strlowcase(char *str);
void			run_test_ft_strlowcase();
// EX09
char			*ft_strcapitalize(char *str);
void			run_test_ft_strcapitalize();
// EX10
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void			run_test_ft_strlcpy();
// EX11
void			ft_putstr_non_printable(char *str);
void			run_test_ft_putstr_non_printable();
// EX12
void			*ft_print_memory(void *addr, unsigned int size);
void			run_test_ft_print_memory();
	
#endif