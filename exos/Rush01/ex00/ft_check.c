/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:00:41 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 15:00:42 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	visible_lr(const int *line, int size)
{
	int	i;
	int	max;
	int	seen;

	max = 0;
	seen = 0;
	i = 0;
	while (i < size)
	{
		if (line[i] > max)
		{
			max = line[i];
			seen++;
		}
		i++;
	}
	return (seen);
}

int	visible_rl(const int *line, int size)
{
	int	i;
	int	max;
	int	seen;

	max = 0;
	seen = 0;
	i = size - 1;
	while (i >= 0)
	{
		if (line[i] > max)
		{
			max = line[i];
			seen++;
		}
		i--;
	}
	return (seen);
}

int	check_row_vis(int **g, int size, int r, int **pos)
{
	if (visible_lr(g[r], size) != pos[2][r])
		return (0);
	if (visible_rl(g[r], size) != pos[3][r])
		return (0);
	return (1);
}

int	check_col_vis(int **g, int size, int c, int **pos)
{
	int	*col;
	int	i;
	int	ok;

	col = (int *)malloc(sizeof(int) * size);
	if (!col)
		return (0);
	i = 0;
	while (i < size)
	{
		col[i] = g[i][c];
		i++;
	}
	if ((visible_lr(col, size) == pos[0][c])
		&& (visible_rl(col, size) == pos[1][c]))
		ok = 1;
	else
		ok = 0;
	free(col);
	return (ok);
}

int	ok_uniq(int **g, int n, int *coord, int val)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (g[coord[0]][i] == val || g[i][coord[1]] == val)
			return (0);
		i++;
	}
	return (1);
}
