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

#endif
