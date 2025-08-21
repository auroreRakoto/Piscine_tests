/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:04:40 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 15:04:41 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_col_vis(int **g, int n, int c, int **pos);
int		check_row_vis(int **g, int n, int r, int **pos);
int		ok_uniq(int **g, int n, int *coord, int val);

void	compute_next(int n, int *coord, int *next)
{
	next[0] = coord[0] + (coord[1] + 1) / n;
	next[1] = (coord[1] + 1) % n;
}

int	valid_after_place(int **g, int size, int *coord, int **pos)
{
	if (coord[0] == size - 1)
		if (!check_col_vis(g, size, coord[1], pos))
			return (0);
	if (coord[1] == size - 1)
		if (!check_row_vis(g, size, coord[0], pos))
			return (0);
	return (1);
}

int	backtrack(int **g, int n, int *coord, int **pos)
{
	int	val;
	int	next[2];

	if (coord[0] == n)
		return (1);
	compute_next(n, coord, next);
	val = 1;
	while (val <= n)
	{
		if (ok_uniq(g, n, coord, val))
		{
			g[coord[0]][coord[1]] = val;
			if (valid_after_place(g, n, coord, pos))
				if (backtrack(g, n, next, pos))
					return (1);
			g[coord[0]][coord[1]] = 0;
		}
		val++;
	}
	return (0);
}
