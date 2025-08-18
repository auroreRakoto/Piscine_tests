/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 07:19:39 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/05 07:19:45 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>

void	ft_putnbr_combn(int n)
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
		ft_putnbr_combn(n / 10);
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

int	pow_n(int p)
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

int	check_number(int i, int n)
{
	int	counter;
	int	n_up;
	int	n_down;
	int	writable;
	int	powed_number;

	counter = 0;
	writable = 1;
	while (counter < n)
	{
		powed_number = pow_n(counter);
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

void	ft_print_combn(int n)
{
	int	i;
	int	max;
	int	counter;
	int	check;

	i = -1;
	counter = n;
	max = pow_n(n);
	while ((++i < max) && (i < 123456790))
	{
		if (i >= (max / 100))
		{
			check = check_number(i, n);
			if (check == 1)
			{
				if (i <= (max / 10) && n != 1)
					write(1, "0", 1);
				ft_putnbr_combn(i);
				if (i / (max / 10) != 10 - n)
					write(1, ", ", 2);
			}
		}
		if (i == 23456789)
			i = 123456788;
	}
}
