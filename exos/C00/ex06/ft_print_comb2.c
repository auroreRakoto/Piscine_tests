/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 09:21:26 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/05 09:21:29 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr_comb2(int n)
{
	char	c;

	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if ((n / 10) > 0)
	{
		ft_putnbr_comb2(n / 10);
		n = n % 10;
		c = n + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			if (i < 10)
				write(1, "0", 1);
			ft_putnbr_comb2(i);
			write(1, " ", 1);
			if (j < 10)
				write(1, "0", 1);
			ft_putnbr_comb2(j);
			if (i != 98 || j != 99)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
