/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:48:50 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/16 15:48:51 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_test_row(int size);
char	**ft_test_input(char *str);
char	**ft_split(char *str, char *charset);
void	ft_run_rush01(char **input);
void	ft_free_split(char **str);
int		ft_get_size(char **input);

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
			grid = malloc(sizeof(char *) * (size + 1));
			ft_run_rush01(inputs, grid, size);
			ft_free_split(inputs);
		}
	}
	printf("end of main\n");
	return (1);
}
