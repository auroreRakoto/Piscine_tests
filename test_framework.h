#ifndef TEST_FRAMEWORK_H
# define TEST_FRAMEWORK_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
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
// EX00
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);


#endif