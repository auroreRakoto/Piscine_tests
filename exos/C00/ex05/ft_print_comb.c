/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 07:19:02 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/05 07:19:05 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr_comb(int n)
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
		ft_putnbr_comb(n / 10);
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

int	ft_pow(int p)
{
	int	res;
	int	pow;

	res = 1;
	pow = p;
	while (pow > 0)
	{
		res = res * 10;
		pow--;
	}
	return (res);
}

int	check_current_number(int i)
{
	int	counter;
	int	n_up;
	int	n_down;
	int	writable;
	int	powed_number;

	counter = 0;
	writable = 1;
	while (counter < 3)
	{
		powed_number = ft_pow(counter);
		n_up = (i / powed_number) % 10;
		n_down = (i / (powed_number * 10)) % 10;
		if (n_up <= n_down && n_down != 0)
		{
			writable = 0;
		}
		counter++;
	}
	return (writable);
}

void	ft_print_comb(void)
{
	int	i;
	int	check;

	i = 12;
	while (i < 790)
	{
		if (i >= (1000 / 100))
		{
			check = check_current_number(i);
			if (check == 1)
			{
				if (i <= (1000 / 10))
					write(1, "0", 1);
				ft_putnbr_comb(i);
				if (i / (1000 / 10) != 10 - 3)
				{
					write(1, ", ", 2);
				}
			}
		}
		i += 1;
	}
}
