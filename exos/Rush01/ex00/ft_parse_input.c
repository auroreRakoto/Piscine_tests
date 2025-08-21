/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 15:48:38 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/16 15:48:39 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

char	**ft_split(char *str, char *charset);
void	ft_free_split(char **str);
int		ft_get_size(char **input);

int	is_input_valid(char **str)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (str[size])
		size++;
	if (size % 4)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] < '1' || str[i][j] > (size / 4) + 48)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_test_input(char *str)
{
	char	**res;
	int		size_split;
	int		size_str;

	res = ft_split(str, " ");
	if (!res)
		return (0);
	if (!is_input_valid(res))
	{
		write(1, "Error\n", 6);
		ft_free_split(res);
		return (0);
	}
	size_split = ft_get_size(res);
	size_str = 0;
	while (str[size_str])
		size_str++;
	if ((size_split * 4 * 2) - 1 != size_str)
	{
		write(1, "Error\n", 6);
		ft_free_split(res);
		return (0);
	}
	ft_free_split(res);
	return (1);
}
