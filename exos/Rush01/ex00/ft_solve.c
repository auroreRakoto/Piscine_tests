/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:08:15 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 15:08:16 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putnbr(int n);
int		ft_atoi_safe(const char *s);
void	print_grid(int **g, int n);
int		backtrack(int **g, int n, int *coord, int **pos);
void	ft_free_grid(int **g, int n);
void	ft_free_pos(int **pos);
void	ft_free_all(char **inputs, int **grid, int size, int **pos);

int	parse_clues(char **input, int size, int **pos)
{
	int	i;
	int	clue;

	i = 0;
	while (i < size)
	{
		clue = ft_atoi_safe(input[i]);
		if (clue < 1 || clue > size)
			return (0);
		pos[0][i] = clue;
		clue = ft_atoi_safe(input[size + i]);
		if (clue < 1 || clue > size)
			return (0);
		pos[1][i] = clue;
		clue = ft_atoi_safe(input[2 * size + i]);
		if (clue < 1 || clue > size)
			return (0);
		pos[2][i] = clue;
		clue = ft_atoi_safe(input[3 * size + i]);
		if (clue < 1 || clue > size)
			return (0);
		pos[3][i] = clue;
		i++;
	}
	return (1);
}

int	**make_grid(int size, char **inputs)
{
	int		**grid;
	int		r;
	int		c;

	grid = (int **)malloc(sizeof(int *) * size);
	if (!grid)
	{
		ft_free_all(inputs, NULL, 0, NULL);
		return (NULL);
	}
	r = -1;
	while (++r < size)
	{
		grid[r] = (int *)malloc(sizeof(int) * size);
		if (!grid[r])
		{
			ft_free_all(inputs, grid, r, NULL);
			return (NULL);
		}
		c = -1;
		while (++c < size)
			grid[r][c] = 0;
	}
	return (grid);
}

int	**make_pos(int size)
{
	int		**pos;
	int		i;
	int		j;

	pos = (int **)malloc(sizeof(int *) * 4);
	if (!pos)
		return (NULL);
	i = -1;
	while (++i < 4)
	{
		pos[i] = (int *)malloc(sizeof(int) * size);
		if (!pos[i])
		{
			j = -1;
			while (++j < i)
				free(pos[j]);
			free(pos);
			return (NULL);
		}
	}
	return (pos);
}

void	ft_run(int **grid, int size, int coord[2], int **pos)
{
	if (backtrack(grid, size, coord, pos))
		print_grid(grid, size);
	else
		write(1, "Error\n", 6);
}

void	ft_solve(char **inputs, int size)
{
	int		**grid;
	int		**pos;
	int		coord[2];

	grid = make_grid(size, inputs);
	if (!grid)
		return ;
	pos = make_pos(size);
	if (!pos)
	{
		ft_free_all(inputs, grid, size, NULL);
		return ;
	}
	if (!parse_clues(inputs, size, pos))
	{
		ft_free_all(inputs, grid, size, pos);
		return ;
	}
	coord[0] = 0;
	coord[1] = 0;
	ft_run(grid, size, coord, pos);
	ft_free_all(NULL, grid, size, pos);
}
