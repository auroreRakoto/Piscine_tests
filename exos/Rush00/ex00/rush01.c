/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhenriqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 11:18:04 by jhenriqu          #+#    #+#             */
/*   Updated: 2025/08/09 14:52:44 by jhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_check_char(int r, int l, int max_size_row, int max_size_line)
{
	if (r == 0 && l == 0)
		ft_putchar('/');
	else if (r == max_size_row - 1 && l == 0)
		ft_putchar('\\');
	else if (l == 0)
		ft_putchar('*');
	else if (r == 0 && l == max_size_line - 1)
		ft_putchar('\\');
	else if (r == max_size_row - 1 && l == max_size_line - 1)
		ft_putchar('/');
	else if (l == max_size_line - 1)
		ft_putchar('*');
	else if (r == 0 || r == max_size_row - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int		i;
	int		j;

	j = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			ft_check_char(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
