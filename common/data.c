#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
