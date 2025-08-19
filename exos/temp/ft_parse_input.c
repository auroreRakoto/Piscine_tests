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

char	**ft_test_input(char *str)
{
	char	**res;

	res = ft_split(str, " ");
	if (!res)
		return (NULL);
	if (!is_input_valid(res))
	{
		write(1, "incorrect input\n", 16);
		ft_free_split(res);
		return (0);
	}
	return (res);
}
