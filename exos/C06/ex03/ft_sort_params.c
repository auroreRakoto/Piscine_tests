/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:59:01 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/10 15:05:06 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **av, int j)
{
	char	*temp;

	temp = av[j];
	av[j] = av[j + 1];
	av[j + 1] = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_put_av(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		write(1, av[i], j);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = 1;
		while (j < ac)
		{
			if (ft_strcmp(av[j], av[j + 1]) > 0)
			{
				ft_swap(av, j);
			}
			j++;
		}
		i++;
	}
	ft_put_av(ac, av);
	return (0);
}
