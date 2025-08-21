/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:43:40 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 08:46:45 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ex05.h"

int	ft_atoi(char *str);
int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	divi(int a, int b);
int	modi(int a, int b);

int	op_index(char c)
{
	int		i;
	char	*ops;

	ops = "+-*/%";
	i = 0;
	while (ops[i])
	{
		if (ops[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_is_op(char *s)
{
	if (!s || !s[0] || s[1])
		return (0);
	return (op_index(s[0]) != -1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
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
		ft_putnbr(n / 10);
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

//int	(*ft_get_ops(int i))(int, int)
t_op	ft_get_ops(int i)
{
	int	(*f[5])(int, int);

	f[0] = add;
	f[1] = sub;
	f[2] = mul;
	f[3] = divi;
	f[4] = modi;
	if (i < 0 || i > 4)
		return (0);
	return (f[i]);
}

int	main(int ac, char **av)
{
	int	a;
	int	b;
	int	idx;

	if (ac != 4)
		return (0);
	if (!ft_is_op(av[2]))
		return (write(1, "0\n", 2), 0);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	idx = op_index(av[2][0]);
	if (idx == 3 && b == 0)
		return (write(1, "Stop : division by zero\n", 24), 0);
	if (idx == 4 && b == 0)
		return (write(1, "Stop : modulo by zero\n", 22), 0);
	ft_putnbr((*ft_get_ops(idx))(a, b));
	write(1, "\n", 1);
	return (0);
}
