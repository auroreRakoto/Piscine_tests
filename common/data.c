#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	if (c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

char	*ft_trim(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	while (*s && ft_is_space(*s))
		s++;
	i = 0;
	while (s[i])
		i++;
	while (i > 0 && ft_is_space(s[i - 1]))
	{
		s[i - 1] = '\0';
		i--;
	}
	return (s);
}

static int	has_digit(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	return (1);
}

int	safe_atoi(const char *s, int *out)
{
	long	res;
	long	sg;
	int		i;

	if (!has_digit(s) || !out)
		return (0);
	i = 0;
	sg = 1;
	res = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sg = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	*out = (int)(res * sg);
	return (1);
}

char	*find_arrow(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == '-' && s[i + 1] == '>')
			return (s + i);
		i++;
	}
	return (NULL);
}

int	parse_pair(char *line, int *a, int *b)
{
	char	*ar;
	char	*lhs;
	char	*rhs;

	if (!line)
		return (0);
	ar = find_arrow(line);
	if (!ar)
		return (0);
	*ar = '\0';
	ar += 2;
	lhs = ft_trim(line);
	rhs = ft_trim(ar);
	return (safe_atoi(lhs, a) && safe_atoi(rhs, b));
}

int	parse_triplet(char *line, int *x, int *p, int *b)
{
	char	*ar;
	char	*lhs;
	char	*rhs;
	char	*mid;

	if (!line)
		return (0);
	ar = find_arrow(line);
	if (!ar)
		return (0);
	*ar = '\0';
	ar += 2;
	lhs = ft_trim(line);
	rhs = ft_trim(ar);
	mid = lhs;
	while (*mid && !ft_is_space(*mid))
		mid++;
	if (*mid)
		*mid++ = '\0';
	mid = ft_trim(mid);
	return (safe_atoi(lhs, x) && safe_atoi(mid, p) && safe_atoi(rhs, b));
}


static char *xstrdup(const char *s)
{
    size_t n = strlen(s);
    char *p = (char *)malloc(n + 1);
    if (p) memcpy(p, s, n + 1);
    return p;
}

static void rtrim(char *s)
{
    int i = (int)strlen(s) - 1;
    while (i >= 0 && (s[i] == '\r' || s[i] == '\n' || isspace((unsigned char)s[i])))
        s[i--] = '\0';
}

static char *ltrim(char *s)
{
    while (*s && isspace((unsigned char)*s))
        s++;
    return s;
}

static char *strip_brackets(char *s)
{
    size_t n = strlen(s);
    if (n >= 2 && s[0] == '[' && s[n - 1] == ']')
    {
        s[n - 1] = '\0';
        return s + 1;
    }
    return NULL;
}

static char **split_cols(char *line, char sep, int *out_count)
{
    int cap = 4, cnt = 0;
    char **cols = (char **)malloc(sizeof(char *) * cap);
    char *p = line, *q;

    if (!cols) return NULL;
    while (1)
    {
        if (cnt == cap)
        {
            cap *= 2;
            char **tmp = (char **)realloc(cols, sizeof(char *) * cap);
            if (!tmp) { free(cols); return NULL; }
            cols = tmp;
        }
        q = strchr(p, sep);
        if (q)
            *q = '\0';
        p = ltrim(p);
        rtrim(p);
        cols[cnt++] = xstrdup(p);
        if (!q) break;
        p = q + 1;
    }
    *out_count = cnt;
    return cols;
}

int data_load_section(const char *path, const char *section, char sep, t_data_table *out)
{
    FILE *f = fopen(path, "rb");
    char buf[4096];
    int in = 0, cap = 8;

    if (!out) return -1;
    out->rows = NULL;
    out->count = 0;
    if (!f) return -1;

    out->rows = (t_data_row *)malloc(sizeof(t_data_row) * cap);
    if (!out->rows) { fclose(f); return -1; }

    while (fgets(buf, sizeof(buf), f))
    {
        char *line = buf;
        rtrim(line);
        line = ltrim(line);
        if (!*line || *line == '#')
            continue;
        if (*line == '[')
        {
            char *name = strip_brackets(line);
            in = (name && strcmp(name, section) == 0);
            continue;
        }
        if (!in)
            continue;

        int ncols = 0;
        char **cols = split_cols(line, sep, &ncols);
        if (!cols) { fclose(f); data_free(out); return -1; }

        if (out->count == cap)
        {
            cap *= 2;
            t_data_row *tmp = (t_data_row *)realloc(out->rows, sizeof(t_data_row) * cap);
            if (!tmp) { fclose(f); data_free(out); return -1; }
            out->rows = tmp;
        }
        out->rows[out->count].cols = cols;
        out->rows[out->count].ncols = ncols;
        out->count++;
    }
    fclose(f);
    return 0;
}

void data_free(t_data_table *t)
{
    int i, j;
    if (!t || !t->rows) return;
    for (i = 0; i < t->count; i++)
    {
        for (j = 0; j < t->rows[i].ncols; j++)
            free(t->rows[i].cols[j]);
        free(t->rows[i].cols);
    }
    free(t->rows);
    t->rows = NULL;
    t->count = 0;
}
