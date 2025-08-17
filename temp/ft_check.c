#include <stdlib.h>

int visible_lr(const int *line, int n)
{
	int i, max, seen;

	max = 0;
	seen = 0;
	i = 0;
	while (i < n)
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

int visible_rl(const int *line, int n)
{
	int i, max, seen;

	max = 0;
	seen = 0;
	i = n - 1;
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

int check_row_vis(int **g, int n, int r, int **pos)
{
	if (visible_lr(g[r], n) != pos[2][r])
		return (0);
	if (visible_rl(g[r], n) != pos[3][r])
		return (0);
	return (1);
}

int check_col_vis(int **g, int n, int c, const int *top, const int *bottom)
{
	int *col;
	int i, ok;

	col = (int *)malloc(sizeof(int) * n);
	if (!col)
		return (0);
	i = 0;
	while (i < n)
	{
		col[i] = g[i][c];
		i++;
	}
	ok = (visible_lr(col, n) == pos[0][c]) && (visible_rl(col, n) == pos[1][c]);
	free(col);
	return (ok);
}

int	ok_uniq(int **g, int n, int *coord, int val)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (g[coord[0]][i] == val || g[i][coord[1]] == val)
			return (0);
		i++;
	}
	return (1);
}
