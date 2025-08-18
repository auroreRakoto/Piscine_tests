/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 07:34:44 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/11 07:38:02 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	is_case_valid(int index, char *str)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (ft_abs(str[i] - str[index]) == ft_abs(i - index) \
				|| str[i] - str[index] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	checking(int index, char *str, int counter)
{
	int	i;

	i = 0;
	if (index == 10)
	{
		write(1, str, 10);
		write(1, "\n", 1);
		counter++;
		return (counter);
	}
	while (i < 10)
	{
		str[index] = i + '0';
		if (is_case_valid(index, str))
		{
			counter = checking(index + 1, str, counter);
		}
		i++;
	}
	return (counter);
}

int	ft_ten_queens_puzzle(void)
{
	char	str[11];
	int		res;

	str[10] = '\0';
	res = checking(0, str, 0);
	return (res);
}
