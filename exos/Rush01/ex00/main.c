/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:01:05 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 15:01:13 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_test_row(int size);
char	**ft_test_input(char *str);
char	**ft_split(char *str, char *charset);
void	ft_run_rush01(char **input);
void	ft_free_split(char **str);
int		ft_get_size(char **input);
void	ft_solve(char **inputs, int size);

int	main(int ac, char **av)
{
	char	**inputs;
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
	else
		write(1, "Error\n", 6);
	return (0);
}
