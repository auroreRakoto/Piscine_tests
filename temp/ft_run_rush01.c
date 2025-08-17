/* ft_run_rush01.c */
#define N 4

extern char g_sol[N][N];

int         parse_clues(char **in);
int         solve(int rn);
void        print_solution(void);

void    ft_run_rush01(char **input, char **grid, int size)
{
    int i;
    int j;

    i = 0;
    while (input[i])
        i++;
    if (i != 4 * N)
        return ;
    j = 0;
    while (j < N)
    {
        i = 0;
        while (i < N)
        {
            g_sol[j][i] = 0;
            i++;
        }
        j++;
    }
    if (!parse_clues(input))
        return ;
    if (solve(0))
        print_solution();
}
