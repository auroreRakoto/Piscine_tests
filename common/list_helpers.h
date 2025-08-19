#ifndef LIST_HELPERS_H
# define LIST_HELPERS_H

# include <stddef.h>

/* Minimal list type for tests (compatible layout with C12) */
typedef struct s_list
{
	struct s_list *next;
	void          *data;
}	t_list;

/* CSV → tokens (each token is strdup'ed).
   Returns array of char* and sets *out_n. Use lh_free_tokens to free. */
char  **lh_split_csv_trim(const char *s, int *out_n);
void    lh_free_tokens(char **tokens, int n);

/* Build a list from tokens.
   take_ownership=0 -> node->data = strdup(token)
   take_ownership=1 -> node->data = token (list will free it) */
t_list *lh_make_list(char **tokens, int n, int take_ownership);

/* Free list; if free_data=1, also free node->data strings */
void    lh_list_free(t_list *lst, int free_data);

/* Compare list content to an array of const char* (size n) */
int     lh_list_eq_cstr(t_list *lst, const char **arr, int n);

/* Simple strdup for tests */
char   *lh_strdup(const char *s);

/* Pretty-print list (strings) */
void    lh_list_print(const char *label, t_list *lst);

/* Pretty-print with custom data printer (no newline per item) */
void    lh_list_print_with(const char *label, t_list *lst, void (*print_data)(void *));

#endif
