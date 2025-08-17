/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you                                            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/* utils provided in your project */
void    ft_putchar(char c);
void    ft_putnbr(int n);
int     ft_atoi_safe(const char *s);
void	print_grid(int **g, int n);
int		check_col_vis(int **g, int n, int c, int *pos);
int		check_row_vis(int **g, int n, int r, int *pos);
int		ok_uniq(int **g, int n, int *coord, int val);

static int	backtrack(int **g, int n, int *coord, int **pos)
{
	int val;
	int next[2];

	if (coord[0] == n)
		return (1);
	next[0] = coord[0] + (coord[1] + 1) / n;
	next[1] = (coord[1] + 1) % n;
	val = 1;
	while (val <= n)
	{
		if (ok_uniq(g, n, coord, val))
		{
			g[coord[0]][coord[1]] = val;

			if (coord[0] == n - 1)
				if (!check_col_vis(g, n, coord[1], pos))
				{
					g[coord[0]][coord[1]] = 0;
					val++;
					continue;
				}
			if (coord[1] == n - 1)
				if (!check_row_vis(g, n, coord[0], pos))
				{
					g[coord[0]][coord[1]] = 0;
					val++;
					continue;
				}
			if (backtrack(g, n, next, pos))
				return (1);
			g[coord[0]][coord[1]] = 0;
		}
		val++;
	}
	return (0);
}

static void free_grid(int **g, int n)
{
	int i = 0;
	if (!g) return;
	while (i < n)
		free(g[i++]);
	free(g);
}

static int parse_clues(char **in, int n, int **pos)
{
    int i;
    int v;

    i = 0;
    while (i < n)
    {
        v = ft_atoi_safe(in[i]);
        if (v < 1 || v > n)
            return (0);
        pos[0][i] = v;

        v = ft_atoi_safe(in[n + i]);
        if (v < 1 || v > n)
            return (0);
        pos[1][i] = v;

        v = ft_atoi_safe(in[2 * n + i]);
        if (v < 1 || v > n)
            return (0);
        pos[2][i] = v;

        v = ft_atoi_safe(in[3 * n + i]);
        if (v < 1 || v > n)
            return (0);
        pos[3][i] = v;

        i++;
    }
    return (1);
}

void    ft_solve(char **inputs, int size)
{
	int **g;
	int **pos;
	int r;
	int	*coord;

	g = (int **)malloc(sizeof(int *) * size);
	if (!g)
	{
		write(1, "Error 1\n", 8);
		return ;
	}
	r = 0;
	while (r < size)
	{
		g[r] = (int *)malloc(sizeof(int) * size);
		if (!g[r])
		{
			write(1, "Error 2\n", 8);
			free_grid(g, r);
			return;
		}
		int c = 0;
		while (c < size)
		{
			g[r][c] = 0;
			c++;
		}
		r++;
	}
	pos = (int **)malloc(sizeof(int *) * 4);
	if (!pos)
	{
		write(1, "Error 3\n", 8);
		free_grid(g, size);
		return;
	}
	r = 0;
	while (r < 4)
	{
		pos[r] = (int *)malloc(sizeof(int) * size);
		if (!pos[r])
		{
			write(1, "Error 4\n", 8);
			int j = 0;
			while (j < r)
			{
				free(pos[j]);
				j++;
			}
			free(pos);
			free_grid(g, size);
			return;
		}
		r++;
	}
	if (!parse_clues(inputs, size, pos))
	{
		write(1, "Error 5\n", 8);
		r = 0;
		while (r < 4)
		{
			free(pos[r]);
			r++;
		}
		free(pos);
		free_grid(g, size);
		return;
	}
	if (backtrack(g, size, coord, pos))
		print_grid(g, size);
	else
		write(1, "No Solution\n", 12);
	r = 0;
	while (r < 4)
	{
		free(pos[r]);
		r++;
	}
	free(pos);
	free_grid(g, size);
}
