#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_atoi_safe(const char *s);
void	print_grid(int **g, int n);
int		check_col_vis(int **g, int n, int c, int **pos);
int		check_row_vis(int **g, int n, int r, int **pos);
int		ok_uniq(int **g, int n, int *coord, int val);

static void	compute_next(int n, int *coord, int *next)
{
	next[0] = coord[0] + (coord[1] + 1) / n;
	next[1] = (coord[1] + 1) % n;
}

static int	valid_after_place(int **g, int n, int *coord, int **pos)
{
	if (coord[0] == n - 1)
		if (!check_col_vis(g, n, coord[1], pos))
			return (0);
	if (coord[1] == n - 1)
		if (!check_row_vis(g, n, coord[0], pos))
			return (0);
	return (1);
}

static int	backtrack(int **g, int n, int *coord, int **pos)
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

static void	free_grid(int **g, int n)
{
	int	i;

	i = 0;
	if (!g)
		return ;
	while (i < n)
		free(g[i++]);
	free(g);
}

static int	parse_clues(char **in, int n, int **pos)
{
	int	i;
	int	v;

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

static int	**make_grid(int size)
{
	int		**g;
	int		r;
	int		c;

	g = (int **)malloc(sizeof(int *) * size);
	if (!g)
	{
		write(1, "Error 1\n", 8);
		return (NULL);
	}
	r = 0;
	while (r < size)
	{
		g[r] = (int *)malloc(sizeof(int) * size);
		if (!g[r])
		{
			write(1, "Error 2\n", 8);
			free_grid(g, r);
			return (NULL);
		}
		c = 0;
		while (c < size)
		{
			g[r][c] = 0;
			c++;
		}
		r++;
	}
	return (g);
}

static int	**make_pos(int size)
{
	int		**pos;
	int		i;
	int		j;

	pos = (int **)malloc(sizeof(int *) * 4);
	if (!pos)
	{
		write(1, "Error 3\n", 8);
		return (NULL);
	}
	i = 0;
	while (i < 4)
	{
		pos[i] = (int *)malloc(sizeof(int) * size);
		if (!pos[i])
		{
			write(1, "Error 4\n", 8);
			j = 0;
			while (j < i)
			{
				free(pos[j]);
				j++;
			}
			free(pos);
			return (NULL);
		}
		i++;
	}
	return (pos);
}

static void	free_pos(int **pos)
{
	int	i;

	if (!pos)
		return ;
	i = 0;
	while (i < 4)
	{
		free(pos[i]);
		i++;
	}
	free(pos);
}

void	ft_solve(char **inputs, int size)
{
	int		**g;
	int		**pos;
	int		coord[2];

	g = make_grid(size);
	if (!g)
		return ;
	pos = make_pos(size);
	if (!pos)
	{
		free_grid(g, size);
		return ;
	}
	if (!parse_clues(inputs, size, pos))
	{
		write(1, "Error 5\n", 8);
		free_pos(pos);
		free_grid(g, size);
		return ;
	}
	coord[0] = 0;
	coord[1] = 0;
	if (backtrack(g, size, coord, pos))
		print_grid(g, size);
	else
		write(1, "No Solution\n", 12);
	free_pos(pos);
	free_grid(g, size);
}
