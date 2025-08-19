#include "../common/assert.h"
#include "../common/data.h"
#include "../common/list_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#ifndef DATA_PATH
# define DATA_PATH "C12/data.txt"
#endif

/* --------- Prototypes (guarded per ex) --------- */
#ifdef HAVE_EX00
t_list	*ft_create_elem(void *data);
#endif
#ifdef HAVE_EX01
void	ft_list_push_front(t_list **begin_list, void *data);
#endif
#ifdef HAVE_EX02
int		ft_list_size(t_list *begin_list);
#endif
#ifdef HAVE_EX03
t_list	*ft_list_last(t_list *begin_list);
#endif
#ifdef HAVE_EX04
void	ft_list_push_back(t_list **begin_list, void *data);
#endif
#ifdef HAVE_EX05
t_list	*ft_list_push_strs(int size, char **strs);
#endif
#ifdef HAVE_EX06
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
#endif
#ifdef HAVE_EX07
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
#endif
#ifdef HAVE_EX08
void	ft_list_reverse(t_list **begin_list);
#endif
#ifdef HAVE_EX09
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
#endif
#ifdef HAVE_EX10
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());
#endif
#ifdef HAVE_EX11
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
#endif
#ifdef HAVE_EX12
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
#endif
#ifdef HAVE_EX13
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
#endif
#ifdef HAVE_EX14
void	ft_list_sort(t_list **begin_list, int (*cmp)());
#endif
#ifdef HAVE_EX15
void	ft_list_reverse_fun(t_list *begin_list);
#endif
#ifdef HAVE_EX16
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
#endif
#ifdef HAVE_EX17
void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
#endif


/* ------------ tiny helpers (tests only) ------------ */
static int cmp_str_void(void *a, void *b)
{
	return strcmp((char *)a, (char *)b);
}

/*
static char *xstrdup(const char *s)
{
	size_t n = strlen(s);
	char *p = (char *)malloc(n + 1);
	if (p)
		memcpy(p, s, n + 1);
	return p;
}

static t_list *make_list(const char **arr, int n, int dup)
{
	t_list *h = NULL, *t = NULL, *node;
	for (int i = 0; i < n; ++i)
	{
		node = (t_list *)malloc(sizeof(*node));
		if (!node)
			return NULL;
		node->data = dup ? xstrdup(arr[i]) : (void *)arr[i];
		node->next = NULL;
		if (!h) h = node; else t->next = node;
		t = node;
	}
	return h;
}

static void free_list_and_data(t_list *lst)
{
	t_list *nx;
	while (lst)
	{
		nx = lst->next;
		free(lst->data);
		free(lst);
		lst = nx;
	}
}

static int list_eq(t_list *lst, const char **arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (!lst || strcmp((char *)lst->data, arr[i]) != 0)
			return 0;
		lst = lst->next;
	}
	return (lst == NULL);
}
*/
static void upcase_inplace(void *p)
{
    char *s = (char *)p;
    while (s && *s)
    {
        *s = (char)toupper((unsigned char)*s);
        ++s;
    }
}

/* ================= ex00 ================= */
#ifdef HAVE_EX00
static void test_ex00(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex00_create_elem", '|', &t) != 0)
	{
		printf("⚠️  no data for [ex00_create_elem]\n");
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *in = t.rows[i].cols[0];
		char msg0[128];
		char msg1[128];
		char msg2[128];
		t_list *n;
		
		if (strcmp(in, "(empty)") == 0)
			in = "";

		n = ft_create_elem((void *)in);
		snprintf(msg0, sizeof msg0, "ex00[%d] node created \"%s\"", i, *in ? in : "(empty)");
		snprintf(msg1, sizeof msg1, "data ptr==input");// \"%s\"", i, *in ? in : "(empty)");
		snprintf(msg2, sizeof msg2, "next==NULL");// \"%s\"",         i, *in ? in : "(empty)");
		assert_true(n != NULL, msg0);
		if (n)
		{
			assert_true(n->data == (void *)in, msg1);
			assert_true(n->next == NULL, msg2);
			free(n);
		}
	}
	data_free(&t);
}
#endif


/* ================= ex01 ================= */
#ifdef HAVE_EX01
static void test_ex01(void)
{
    t_data_table t;

    if (data_load_section(DATA_PATH, "ex01_push_front", '|', &t) != 0)
    {
        printf("WARNING: no data for [ex01_push_front] in %s\n", DATA_PATH);
        return;
    }
    for (int i = 0; i < t.count; ++i)
    {
        const char *init_str = t.rows[i].cols[0];   /* "(empty)" or CSV */
        const char *push_str = t.rows[i].cols[1];
        char      **tokens;
        int         n;
        t_list     *lst;

        tokens = lh_split_csv_trim(init_str, &n);       /* strdup tokens */
        lst = lh_make_list(tokens, n, /*take_ownership=*/1);
        free(tokens);                                   /* array only */

#if TEST_VERBOSE
        char label[160];
        snprintf(label, sizeof label, "	ex01 BEFORE push \"%s\"", *push_str ? push_str : "(empty)");
        lh_list_print(label, lst);
#endif

        ft_list_push_front(&lst, lh_strdup(push_str));  /* own data */

#if TEST_VERBOSE
        snprintf(label, sizeof label, "	ex01 AFTER  push \"%s\"", *push_str ? push_str : "(empty)");
        lh_list_print(label, lst);
#endif

        /* check final order: push_str + initial items */
        {
            char **tok2; int n2;
            tok2 = lh_split_csv_trim(init_str, &n2);
            const char **exp = (const char **)malloc(sizeof(*exp) * (n2 + 1));
            exp[0] = push_str;
            for (int k = 0; k < n2; ++k)
                exp[k + 1] = tok2[k];
            char msg[160];
            snprintf(msg, sizeof msg, "ex01[%d] push_front \"%s\" onto [%s]", i,
                     *push_str ? push_str : "(empty)",
                     *init_str ? init_str : "(empty)");
            assert_true(lh_list_eq_cstr(lst, exp, n2 + 1), msg);
            lh_free_tokens(tok2, n2);
            free(exp);
        }

        lh_list_free(lst, /*free_data=*/1);
    }
    data_free(&t);
}
#endif

/* ================= ex02: ft_list_size ================= */
#ifdef HAVE_EX02
static void test_ex02(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex02_size", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex02_size] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;
		char        msg[160];

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1); /* take ownership of token strings */
		free(tokens);

		snprintf(msg, sizeof msg, "ex02[%d] size of [%s]", i, *init_str ? init_str : "(empty)");
		assert_int_eq(ft_list_size(lst), n, msg);

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex03: ft_list_last ================= */
#ifdef HAVE_EX03
static void test_ex03(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex03_last", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex03_last] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst, *last;
		char        msg[160];

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

		last = ft_list_last(lst);
		snprintf(msg, sizeof msg, "ex03[%d] last of [%s]", i, *init_str ? init_str : "(empty)");

		if (n == 0)
		{
			assert_true(last == NULL, msg);
		}
		else
		{
			int   n2;
			char **tok2 = lh_split_csv_trim(init_str, &n2);
			assert_true(last != NULL, "ex03 last non-NULL");
			assert_str_eq((char *)last->data, tok2[n2 - 1], msg);
			lh_free_tokens(tok2, n2);
		}

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif


/* ================= ex04: ft_list_push_back ================= */
#ifdef HAVE_EX04
static void test_ex04(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex04_push_back", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex04_push_back] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *push_str = t.rows[i].cols[1];
		char      **tokens; int n;
		t_list     *lst;
		char        msg[160];

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		char label[160];
		snprintf(label, sizeof label, "	ex04 BEFORE push_back \"%s\"", *push_str ? push_str : "(empty)");
		lh_list_print(label, lst);
#endif

		ft_list_push_back(&lst, lh_strdup(push_str));

#if TEST_VERBOSE
		snprintf(label, sizeof label, "	ex04 AFTER  push_back \"%s\"", *push_str ? push_str : "(empty)");
		lh_list_print(label, lst);
#endif

		/* expected: init..., push_str */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			const char **exp = (const char **)malloc(sizeof(*exp) * (n2 + 1));
			for (int k = 0; k < n2; ++k) exp[k] = tok2[k];
			exp[n2] = push_str;

			snprintf(msg, sizeof msg, "ex04[%d] push_back \"%s\" onto [%s]",
			         i, *push_str ? push_str : "(empty)", *init_str ? init_str : "(empty)");
			assert_true(lh_list_eq_cstr(lst, exp, n2 + 1), msg);

			lh_free_tokens(tok2, n2);
			free(exp);
		}

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex05: ft_list_push_strs ================= */
#ifdef HAVE_EX05
static void test_ex05(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex05_push_strs", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex05_push_strs] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *csv = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;
		char        msg[160];

		tokens = lh_split_csv_trim(csv, &n); /* tokens are strdup'ed */

#if TEST_VERBOSE
		/* print SOURCE order (just for visibility) */
		{
			t_list *src = lh_make_list(tokens, n, /*take_ownership=*/0); /* dup */
			char label[160];
			snprintf(label, sizeof label, "	ex05 SOURCE from [%s]", *csv ? csv : "(empty)");
			lh_list_print(label, src);
			lh_list_free(src, /*free_data=*/1);
		}
#endif

		/* build list from array (student function) */
		lst = ft_list_push_strs(n, tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex05 AFTER  push_strs");
			lh_list_print(label, lst);
		}
#endif

		/* expected = REVERSED(tokens) */
		{
			const char **exp = (const char **)malloc(sizeof(*exp) * n);
			for (int k = 0; k < n; ++k)
				exp[k] = tokens[n - 1 - k];
			snprintf(msg, sizeof msg, "ex05[%d] push_strs builds reversed list of [%s]",
			         i, *csv ? csv : "(empty)");
			assert_true(lh_list_eq_cstr(lst, exp, n), msg);
			free(exp);
		}

		/* free: list nodes first (keep data), then free tokens (strings) */
		lh_list_free(lst, /*free_data=*/0);
		lh_free_tokens(tokens, n);
	}
	data_free(&t);
}
#endif


/* ================= ex06: ft_list_clear ================= */
#ifdef HAVE_EX06
static void test_ex06(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex06_clear", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex06_clear] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		char label[160];
		snprintf(label, sizeof label, "	ex06 BEFORE clear");
		lh_list_print(label, lst);
#endif

		ft_list_clear(lst, free); /* implementation should free nodes */

		/* can't deref lst now; just assert "no crash" */
		assert_true(1, "ex06 clear no-crash");
	}
	data_free(&t);
}
#endif

/* ================= ex07: ft_list_at ================= */
#ifdef HAVE_EX07
static void test_ex07(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex07_at", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex07_at] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *idx_str  = t.rows[i].cols[1];
		unsigned    idx      = (unsigned)strtoul(idx_str, NULL, 10);
		char      **tokens; int n;
		t_list     *lst, *node;
		char        msg[160];

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

		node = ft_list_at(lst, idx);

		snprintf(msg, sizeof msg, "ex07[%d] at %u in [%s]", i, idx, *init_str ? init_str : "(empty)");
		if (idx >= (unsigned)n)
			assert_true(node == NULL, msg);
		else
			assert_str_eq((char *)node->data, lh_split_csv_trim(init_str, &n)[idx], msg); /* we’ll rebuild below properly */

		/* Proper expected without leaking: re-split to get expected token */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			if (idx < (unsigned)n2)
				assert_str_eq((char *)(node ? node->data : NULL), tok2[idx], msg);
			lh_free_tokens(tok2, n2);
		}

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex08: ft_list_reverse ================= */
#ifdef HAVE_EX08
static void test_ex08(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex08_reverse", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex08_reverse] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;
		char        msg[160];

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		char label[160];
		snprintf(label, sizeof label, "	ex08 BEFORE reverse");
		lh_list_print(label, lst);
#endif

		ft_list_reverse(&lst);

#if TEST_VERBOSE
		snprintf(label, sizeof label, "	ex08 AFTER  reverse");
		lh_list_print(label, lst);
#endif

		/* expected: reversed tokens */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			const char **exp = (const char **)malloc(sizeof(*exp) * n2);
			for (int k = 0; k < n2; ++k)
				exp[k] = tok2[n2 - 1 - k];

			snprintf(msg, sizeof msg, "ex08[%d] reverse [%s]", i, *init_str ? init_str : "(empty)");
			assert_true(lh_list_eq_cstr(lst, exp, n2), msg);

			lh_free_tokens(tok2, n2);
			free(exp);
		}

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex09: ft_list_foreach ================= */
#ifdef HAVE_EX09
static void test_ex09(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex09_foreach", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex09_foreach] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex09[%d] BEFORE foreach", i);
			lh_list_print(label, lst);
		}
#endif
		ft_list_foreach(lst, &upcase_inplace);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex09[%d] AFTER  foreach", i);
			lh_list_print(label, lst);
		}
#endif
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			for (int k = 0; k < n2; ++k) upcase_inplace(tok2[k]);
			assert_true(lh_list_eq_cstr(lst, (const char **)tok2, n2),
				"ex09 foreach uppercases all");
			lh_free_tokens(tok2, n2);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex10: ft_list_foreach_if ================= */
#ifdef HAVE_EX10

static void test_ex10(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex10_foreach_if", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex10_foreach_if] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *key      = t.rows[i].cols[1];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex10[%d] BEFORE foreach_if key=\"%s\"", i, key);
			lh_list_print(label, lst);
		}
#endif
		ft_list_foreach_if(lst, &upcase_inplace, (void *)key, &cmp_str_void);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex10[%d] AFTER  foreach_if key=\"%s\"", i, key);
			lh_list_print(label, lst);
		}
#endif
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			for (int k = 0; k < n2; ++k)
				if (strcmp(tok2[k], key) == 0) upcase_inplace(tok2[k]);
			assert_true(lh_list_eq_cstr(lst, (const char **)tok2, n2),
				"ex10 foreach_if applied to matches only");
			lh_free_tokens(tok2, n2);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex11: ft_list_find ================= */
#ifdef HAVE_EX11
static void test_ex11(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex11_find", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex11_find] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *key      = t.rows[i].cols[1];
		char      **tokens; int n;
		t_list     *lst, *node;
		int         present = 0;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

		/* expected presence */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			for (int k = 0; k < n2; ++k)
				if (strcmp(tok2[k], key) == 0) { present = 1; break; }
			lh_free_tokens(tok2, n2);
		}

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex11[%d] BEFORE find \"%s\"", i, key);
			lh_list_print(label, lst);
		}
#endif
		node = ft_list_find(lst, (void *)key, &cmp_str_void);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex11[%d] AFTER  find (unchanged)", i);
			lh_list_print(label, lst);
		}
#endif
		if (present)
		{
			assert_true(node != NULL, "ex11 found -> non-NULL");
			if (node) assert_str_eq((char *)node->data, key, "ex11 node->data == key");
		}
		else
			assert_true(node == NULL, "ex11 not found -> NULL");

		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex12: ft_list_remove_if ================= */
#ifdef HAVE_EX12
static void test_ex12(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex12_remove_if", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex12_remove_if] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *key      = t.rows[i].cols[1];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex12[%d] BEFORE remove_if \"%s\"", i, key);
			lh_list_print(label, lst);
		}
#endif
		ft_list_remove_if(&lst, (void *)key, &cmp_str_void, free);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex12[%d] AFTER  remove_if \"%s\"", i, key);
			lh_list_print(label, lst);
		}
#endif
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			int m = 0;
			for (int k = 0; k < n2; ++k)
				if (strcmp(tok2[k], key) != 0)
					tok2[m++] = tok2[k];
			assert_true(lh_list_eq_cstr(lst, (const char **)tok2, m),
				"ex12 remove_if removes all matches");
			/* free only the m kept strings */
			for (int k = 0; k < m; ++k) free(tok2[k]);
			free(tok2);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex13: ft_list_merge ================= */
#ifdef HAVE_EX13
static void test_ex13(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex13_merge", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex13_merge] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *s1 = t.rows[i].cols[0];
		const char *s2 = t.rows[i].cols[1];
		char      **t1; int n1;
		char      **t2; int n2;
		t_list     *l1, *l2;

		t1 = lh_split_csv_trim(s1, &n1);
		t2 = lh_split_csv_trim(s2, &n2);
		l1 = lh_make_list(t1, n1, 1);
		l2 = lh_make_list(t2, n2, 1);
		free(t1); free(t2);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex13[%d] BEFORE merge L1", i);
			lh_list_print(label, l1);
			snprintf(label, sizeof label, "ex13[%d] BEFORE merge L2", i);
			lh_list_print(label, l2);
		}
#endif
		ft_list_merge(&l1, l2);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "ex13[%d] AFTER  merge", i);
			lh_list_print(label, l1);
		}
#endif
		{
			int nA; char **A = lh_split_csv_trim(s1, &nA);
		 int nB; char **B = lh_split_csv_trim(s2, &nB);
			const char **exp = (const char **)malloc(sizeof(*exp) * (nA + nB));
			for (int k = 0; k < nA; ++k) exp[k]      = A[k];
			for (int k = 0; k < nB; ++k) exp[nA + k] = B[k];
			assert_true(lh_list_eq_cstr(l1, exp, nA + nB), "ex13 merge preserves order");
			lh_free_tokens(A, nA);
			lh_free_tokens(B, nB);
			free(exp);
		}
		lh_list_free(l1, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex14: ft_list_sort ================= */
#ifdef HAVE_EX14
static void test_ex14(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex14_sort", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex14_sort] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
		 char label[160];
		 snprintf(label, sizeof label, "	ex14 BEFORE sort");
		 lh_list_print(label, lst);
		}
#endif
		ft_list_sort(&lst, &cmp_str_void);
#if TEST_VERBOSE
		{
		 char label[160];
		 snprintf(label, sizeof label, "	ex14 AFTER  sort");
		 lh_list_print(label, lst);
		}
#endif
		/* expected: ascending sort */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			for (int a = 0; a + 1 < n2; ++a)
				for (int b = a + 1; b < n2; ++b)
					if (strcmp(tok2[a], tok2[b]) > 0)
					{ char *tmp = tok2[a]; tok2[a] = tok2[b]; tok2[b] = tmp; }
			assert_true(lh_list_eq_cstr(lst, (const char **)tok2, n2), "ex14 sort ascending");
			lh_free_tokens(tok2, n2);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif
/* ================= ex15: ft_list_reverse_fun ================= */
#ifdef HAVE_EX15
static void test_ex15(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex15_reverse_fun", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex15_reverse_fun] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex15 BEFORE reverse_fun");
			lh_list_print(label, lst);
		}
#endif
		ft_list_reverse_fun(lst);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex15 AFTER  reverse_fun");
			lh_list_print(label, lst);
		}
#endif
		/* expected: reversed order */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			const char **exp = (const char **)malloc(sizeof(*exp) * n2);
			for (int k = 0; k < n2; ++k) exp[k] = tok2[n2 - 1 - k];

			char msg[160];
			snprintf(msg, sizeof msg, "ex15[%d] reverse_fun reverses data", i);
			assert_true(lh_list_eq_cstr(lst, exp, n2), msg);

			lh_free_tokens(tok2, n2);
			free(exp);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex16: ft_sorted_list_insert ================= */
#ifdef HAVE_EX16
static void test_ex16(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex16_sorted_insert", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex16_sorted_insert] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *init_str = t.rows[i].cols[0];
		const char *ins      = t.rows[i].cols[1];
		char      **tokens; int n;
		t_list     *lst;

		tokens = lh_split_csv_trim(init_str, &n);
		lst = lh_make_list(tokens, n, 1);
		free(tokens);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex16 BEFORE insert \"%s\"", ins);
			lh_list_print(label, lst);
		}
#endif
		ft_sorted_list_insert(&lst, lh_strdup(ins), &cmp_str_void);
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex16 AFTER  insert \"%s\"", ins);
			lh_list_print(label, lst);
		}
#endif
		/* expected: (init + ins) sorted ascending */
		{
			int n2; char **tok2 = lh_split_csv_trim(init_str, &n2);
			char **arr = (char **)malloc(sizeof(*arr) * (n2 + 1));
			for (int k = 0; k < n2; ++k) arr[k] = tok2[k];
			arr[n2] = (char *)ins;

			/* simple in-place sort of arr */
			for (int a = 0; a < n2 + 1; ++a)
				for (int b = a + 1; b < n2 + 1; ++b)
					if (strcmp(arr[a], arr[b]) > 0)
					{ char *tmp = arr[a]; arr[a] = arr[b]; arr[b] = tmp; }

			char msg[160];
			snprintf(msg, sizeof msg, "ex16[%d] sorted insert \"%s\"", i, ins);
			assert_true(lh_list_eq_cstr(lst, (const char **)arr, n2 + 1), msg);

			/* arr points into tok2 + ins literal; free only holders */
			free(arr);
			lh_free_tokens(tok2, n2);
		}
		lh_list_free(lst, 1);
	}
	data_free(&t);
}
#endif

/* ================= ex17: ft_sorted_list_merge ================= */
#ifdef HAVE_EX17
static void test_ex17(void)
{
	t_data_table t;

	if (data_load_section(DATA_PATH, "ex17_sorted_merge", '|', &t) != 0)
	{
		printf("WARNING: no data for [ex17_sorted_merge] in %s\n", DATA_PATH);
		return;
	}
	for (int i = 0; i < t.count; ++i)
	{
		const char *s1 = t.rows[i].cols[0];
		const char *s2 = t.rows[i].cols[1];
		char      **t1; int n1;
		char      **t2; int n2;
		t_list     *l1, *l2;

		t1 = lh_split_csv_trim(s1, &n1);
		t2 = lh_split_csv_trim(s2, &n2);
		l1 = lh_make_list(t1, n1, 1);
		l2 = lh_make_list(t2, n2, 1);
		free(t1); free(t2);

#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex17 BEFORE merge L1");
			lh_list_print(label, l1);
			snprintf(label, sizeof label, "	ex17 BEFORE merge L2");
			lh_list_print(label, l2);
		}
#endif
		ft_sorted_list_merge(&l1, l2, &cmp_str_void); /* l2 consumed */
#if TEST_VERBOSE
		{
			char label[160];
			snprintf(label, sizeof label, "	ex17 AFTER  merge");
			lh_list_print(label, l1);
		}
#endif
		/* expected: (s1 + s2) sorted ascending */
		{
			int nA; char **A = lh_split_csv_trim(s1, &nA);
			int nB; char **B = lh_split_csv_trim(s2, &nB);
			char **arr = (char **)malloc(sizeof(*arr) * (nA + nB));
			for (int k = 0; k < nA; ++k) arr[k]      = A[k];
			for (int k = 0; k < nB; ++k) arr[nA + k] = B[k];

			for (int a = 0; a < nA + nB; ++a)
				for (int b = a + 1; b < nA + nB; ++b)
					if (strcmp(arr[a], arr[b]) > 0)
					{ char *tmp = arr[a]; arr[a] = arr[b]; arr[b] = tmp; }

			assert_true(lh_list_eq_cstr(l1, (const char **)arr, nA + nB),
				"ex17 sorted merge keeps order");

			free(arr);
			lh_free_tokens(A, nA);
			lh_free_tokens(B, nB);
		}
		lh_list_free(l1, 1);
	}
	data_free(&t);
}
#endif


/* ================= aggregator ================= */
void test_C12(void)
{
	t_set_suite("C12");
#ifdef HAVE_EX00
	test_ex00();
#endif
#ifdef HAVE_EX01
	test_ex01();
#endif
#ifdef HAVE_EX02
	test_ex02();
#endif
#ifdef HAVE_EX03
	test_ex03();
#endif
#ifdef HAVE_EX04
	test_ex04();
#endif
#ifdef HAVE_EX05
	test_ex05();
#endif
#ifdef HAVE_EX06
	test_ex06();
#endif
#ifdef HAVE_EX07
	test_ex07();
#endif
#ifdef HAVE_EX08
	test_ex08();
#endif
#ifdef HAVE_EX09
	test_ex09();
#endif
#ifdef HAVE_EX10
	test_ex10();
#endif
#ifdef HAVE_EX11
	test_ex11();
#endif
#ifdef HAVE_EX12
	test_ex12();
#endif
#ifdef HAVE_EX13
	test_ex13();
#endif
#ifdef HAVE_EX14
	test_ex14();
#endif
#ifdef HAVE_EX15
	test_ex15();
#endif
#ifdef HAVE_EX16
	test_ex16();
#endif
#ifdef HAVE_EX17
	test_ex17();
#endif
	t_summary();
}