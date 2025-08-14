#include "C03_lib.h"

int	main(int ac, char **av)
{
	if (ac < 2 || strcmp(av[1], "0") == 0)
	{
		run_test_ft_strcmp();
		printf("\n\n");
	}
	if (ac < 2 || strcmp(av[1], "1") == 0)
	{
		run_test_ft_strncmp();
		printf("\n\n");
	}
	if (ac < 2 || strcmp(av[1], "2") == 0)
	{
		run_test_ft_strcat();
		printf("\n\n");
	}
	if (ac < 2 || strcmp(av[1], "3") == 0)
	{
		run_test_ft_strncat();
		printf("\n\n");
	}
	if (ac < 2 || strcmp(av[1], "4") == 0)
	{
		run_test_ft_strstr();
		printf("\n\n");
	}/*
	if (ac < 2 || strcmp(av[1], "5") == 0)
	{
		run_test_ft_strlcat();
		printf("\n\n");
	}*/
	return (0);
}
