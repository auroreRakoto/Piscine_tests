#include <stdio.h>
#include <stdlib.h>

void	ft_test_row(int size);
char	**ft_test_input(char *str);
char	**ft_split(char *str, char *charset);
void	ft_run_rush01(char **input);
void	ft_free_split(char **str);
int		ft_get_size(char **input);
void    ft_solve(char **inputs, int size);

int	main(int ac, char **av)
{
	char	**inputs;
	char	**grid;
	int		size;

	if (ac == 2)
	{
		if (ft_test_input(av[1]))
		{
			inputs = ft_split(av[1], " ");
			if (!inputs)
				return (1);
			size = ft_get_size(inputs);
			ft_solve(inputs, size);
			ft_free_split(inputs);
		}
	}
	printf("end of main\n");
	return (0);
}
