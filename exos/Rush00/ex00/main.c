/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdouny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 12:37:46 by cdouny            #+#    #+#             */
/*   Updated: 2025/08/10 18:43:01 by cdouny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);

int	ft_ultimate_check_char(int i, int j, int x, int y)
{
	int	res;

	if (i == 0 && j == 0)
		res = 0;
	else if (i == 0 && j == y - 1)
		res = 1;
	else if (i == x - 1 && j == 0)
		res = 2;
	else if (i == x - 1 && j == y - 1)
		res = 3;
	else if (i == 0 || i == x - 1)
		res = 4;
	else if (j == 0 || j == y - 1)
		res = 5;
	else
		res = 6;
	return (res);
}

void	ft_ultimate_rush(int x, int y, int crush)
{
	int			i;
	int			j;
	char		*base;

	j = 0;
	if (x <= 0 || y <= 0 || crush <= 0 || crush > 5)
		return ;
	if (crush == 1)
		base = "oooo|- ";
	else if (crush == 2)
		base = "/\\\\/** ";
	else if (crush == 3)
		base = "ACACBB ";
	else if (crush == 4)
		base = "AACCBB ";
	else if (crush == 5)
		base = "ACCABB ";
	while (j < y)
	{
		i = -1;
		while (++i < x)
			ft_putchar(base[ft_ultimate_check_char(i, j, x, y)]);
		ft_putchar('\n');
		j++;
	}
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

int	ft_atoi(char *str)
{
	long int	i;
	long int	n;
	long int	res;

	n = 1;
	res = 0;
	i = 0;
	while (str[i] && str[i] != '0')
		i++;
	if (i == 11)
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (0);
	}
	else if (i > 11)
		return (0);
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	res = n * res;
	return (res);
}

int	main(int ac, char **av)
{
	if (ac < 4)
		rush(4, 5);
	if (ac == 4)
		ft_ultimate_rush(ft_atoi(av[1]), ft_atoi(av[2]), ft_atoi(av[3]));
	return (0);
}
