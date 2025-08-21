/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdouny <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 08:36:50 by cdouny            #+#    #+#             */
/*   Updated: 2025/08/10 08:43:46 by cdouny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int	ft_check_char(int i, int j, int line, int col)
{
	int	res;

	if (i == 0 && j == 0)
		res = 0;
	else if (i == 0 && j == col - 1)
		res = 1;
	else if (i == line - 1 && j == 0)
		res = 2;
	else if (i == line - 1 && j == col - 1)
		res = 3;
	else if (i == 0 || i == line - 1)
		res = 4;
	else if (j == 0 || j == col - 1)
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
	char	c;

	j = 0;
	base = "ACACBB ";
	if (x <= 0 || y <= 0)
		return ;
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
