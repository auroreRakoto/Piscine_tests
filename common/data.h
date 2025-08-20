#ifndef DATA_H
# define DATA_H

# include <stddef.h>

typedef struct s_data_row
{
	char	**cols;
	int		ncols;
}	t_data_row;

typedef struct s_data_table
{
	t_data_row	*rows;
	int			count;
}	t_data_table;

/* Load all lines under [section] from file at path, split by sep (e.g. '|') */
int  data_load_section(const char *path, const char *section, char sep, t_data_table *out);
void data_free(t_data_table *t);

int		ft_is_space(char c);
char	*ft_trim(char *s);
int		safe_atoi(const char *s, int *out);
char	*find_arrow(char *s);
int		parse_pair(char *line, int *a, int *b);
int		parse_triplet(char *line, int *x, int *p, int *b);

#endif
