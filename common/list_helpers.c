#include "list_helpers.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

#ifndef TEST_VERBOSE
# define TEST_VERBOSE 0
#endif

/* ---------- small utils ---------- */
char *lh_strdup(const char *s)
{
	size_t n;
	char  *p;

	if (!s)
		return NULL;
	n = strlen(s);
	p = (char *)malloc(n + 1);
	if (p)
		memcpy(p, s, n + 1);
	return p;
}

static char *ltrim(char *s)
{
	while (*s && isspace((unsigned char)*s))
		s++;
	return s;
}

static void rtrim_inplace(char *s)
{
	size_t n = strlen(s);
	while (n > 0 && isspace((unsigned char)s[n - 1]))
		s[--n] = '\0';
}

/* ---------- CSV split with trimming ---------- */
char **lh_split_csv_trim(const char *s, int *out_n)
{
	char  **arr;
	int     cap, n;
	char   *buf, *p, *start;

	if (out_n)
		*out_n = 0;
	if (!s || !*s || strcmp(s, "(empty)") == 0)
		return NULL;

	buf = lh_strdup(s); /* mutable working buffer */
	if (!buf)
		return NULL;

	cap = 8;
	n = 0;
	arr = (char **)malloc(sizeof(*arr) * cap);
	if (!arr)
	{
		free(buf);
		return NULL;
	}

	p = buf;
	for (;;)
	{
		start = ltrim(p);
		p = strchr(start, ',');
		if (p)
			*p = '\0';
		rtrim_inplace(start);

		if (*start) /* skip empty tokens */
		{
			if (n == cap)
			{
				cap *= 2;
				char **tmp = (char **)realloc(arr, sizeof(*arr) * cap);
				if (!tmp) { free(buf); for (int i = 0; i < n; ++i) free(arr[i]); free(arr); return NULL; }
				arr = tmp;
			}
			arr[n++] = lh_strdup(start);
		}
		if (!p)
			break;
		p += 1; /* next token */
	}

	free(buf);
	if (out_n)
		*out_n = n;
	return arr;
}

void lh_free_tokens(char **tokens, int n)
{
	if (!tokens)
		return;
	for (int i = 0; i < n; ++i)
		free(tokens[i]);
	free(tokens);
}

/* ---------- list helpers ---------- */
t_list *lh_make_list(char **tokens, int n, int take_ownership)
{
	t_list *head = NULL, *tail = NULL, *node;

	for (int i = 0; i < n; ++i)
	{
		node = (t_list *)malloc(sizeof(*node));
		if (!node)
			return head; /* best effort; caller can free partial list */
		node->data = take_ownership ? (void *)tokens[i] : (void *)lh_strdup(tokens[i]);
		node->next = NULL;
		if (!head) head = node; else tail->next = node;
		tail = node;
	}
	return head;
}

void lh_list_free(t_list *lst, int free_data)
{
	t_list *nx;

	while (lst)
	{
		nx = lst->next;
		if (free_data)
			free(lst->data);
		free(lst);
		lst = nx;
	}
}

int lh_list_eq_cstr(t_list *lst, const char **arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (!lst || strcmp((char *)lst->data, arr[i]) != 0)
			return 0;
		lst = lst->next;
	}
	return (lst == NULL);
}

/* ---------- printers ---------- */
void lh_list_print(const char *label, t_list *lst)
{
	int   i = 0;

	if (label)
		printf("%s: ", label);
	printf("[");
	while (lst)
	{
		char *s = (char *)lst->data;
		printf("%s\"%s\"", (i ? " -> " : ""), s ? s : "(null)");
		lst = lst->next;
		i++;
	}
	printf("] (len=%d)\n", i);
}

void lh_list_print_with(const char *label, t_list *lst, void (*print_data)(void *))
{
	int i = 0;

	if (label)
		printf("%s: ", label);
	printf("[");
	while (lst)
	{
		if (print_data)
			print_data(lst->data);
		else
			printf("(?)");
		lst = lst->next;
		if (lst)
			printf(" -> ");
		i++;
	}
	printf("] (len=%d)\n", i);
}
