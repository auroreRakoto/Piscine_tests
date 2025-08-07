#ifndef C03_LIB_H
# define C03_LIB_H

# include <stdio.h>
# include <string.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define RESET "\033[0;0m"

// TEST
void		assert_str(char *expected, char *actual, char *msg);


// EX00
int	            ft_strcmp(char *s1, char *s2);
void        	run_test_ft_strcmp();
// EX01
int             ft_strncmp(char *s1, char *s2, unsigned int n);
void	        run_test_ft_strncmp();
// EX02
char	        *ft_strcat(char *dest, char *src);
void	        run_test_ft_strcat();
// EX03
char        	*ft_strncat(char *dest, char *src, unsigned int nb);
void        	run_test_ft_strncat();
// EX04
char	        *ft_strstr(char *str, char *to_find);
void	        run_test_ft_strstr();
// EX05
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
void        	run_test_ft_strlcat();

#endif
