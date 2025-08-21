/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:14:00 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/10 17:16:17 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_check_char(int i, int j, int x, int y)
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

void	rush(int x, int y)
{
	int		i;
	int		j;
	char	*base;

	j = 0;
	base = "oooo|- ";
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_putchar(base[ft_check_char(i, j, x, y)]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
