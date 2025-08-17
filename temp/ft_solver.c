/* ft_solver.c */
#define N 4

extern char g_row_table[N][N][6][N];
extern char g_row_count[N][N];
extern char g_sol[N][N];
extern char g_left[N];
extern char g_right[N];
int         check_columns(int rn);

static void fill_row(char *row, int rn)
{
	int i;

	i = 0;
	while (i < N)
	{
		g_sol[rn][i] = row[i];
		i++;
	}
}

int     solve(int rn, int size, char **temp)
{
	int     j;
	int     lc;
	int     rc;
	char    *row;

	if (rn == size)
		return (1);
	lc = g_left[rn] - 1;
	rc = g_right[rn] - 1;
	if (lc < 0 || lc >= N || rc < 0 || rc >= N)
		return (0);
	j = 0;
	while (j < g_row_count[lc][rc])
	{
		row = g_row_table[lc][rc][j];
		fill_row(row, rn);
		if (check_columns(rn) && solve(rn + 1))
			return (1);
		j++;
	}
	return (0);
}
