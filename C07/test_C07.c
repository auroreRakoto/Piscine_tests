#include "lib_C07.h"

/* track which test is currently running */
static const char *g_current_test = NULL;

/* make it LINK-visible so main.c can call it too */
void set_current_test(const char *desc) {
    g_current_test = desc;
}

/* print which test crashed if we segfault */
static void on_segv(int sig){
	(void)sig;
	fprintf(stderr, "\n💥 Segmentation fault during: %s\n",
	        g_current_test ? g_current_test : "(unknown)");
	fflush(stderr);
	_Exit(139);
}

/* call this once from main() */
void install_segv_handler(void){
	signal(SIGSEGV, on_segv);
}


/* TEMP: avoid freeing student-owned memory to prevent crashes */
#define SAFE_FREE(p) do { (void)(p); } while (0)


/* ---------- helpers (used by multiple cases) ---------- */
static int arr_eq(const int *a, const int *b, int n) {
	if (!a || !b) return 0;
	for (int i = 0; i < n; ++i) if (a[i] != b[i]) return 0;
	return 1;
}

static int strtab_len(char **t) {
	int n = 0; if (!t) return 0;
	while (t[n]) n++;
	return n;
}

static int strtab_eq(char **got, const char **exp) {
	int i = 0;
	while (exp && exp[i]) {
		if (!got || !got[i] || strcmp(got[i], exp[i]) != 0) return 0;
		i++;
	}
	return got && got[i] == NULL;
}

static void strtab_free(char **t) {
	/* Avoid freeing student-owned inner strings while debugging segfaults */
	(void)t;
	/* If you’re sure tokens are malloc’ed by the student, switch to:
	   if (!t) return;
	   for (int i=0; t[i]; ++i) free(t[i]);
	   free(t);
	*/
}
/*
static void strtab_free(char **t) {
	if (!t) return;
	for (int i = 0; t[i]; ++i) free(t[i]);
	free(t);
}*/

/* ---------- C07 run_test in the C05 printing style ---------- */
int run_test(t_test test)
{
	set_current_test(test.desc);
	//printf("• %s ... ", test.desc);
	fflush(stdout);

	switch (test.type)
	{
		case TEST_STRDUP: {
			t_args_strdup *a = (t_args_strdup*)test.args;
			char *dup = ft_strdup((char*)a->src);
			if ((test.expected_str == NULL && dup == NULL) ||
			    (test.expected_str && dup && strcmp(test.expected_str, dup) == 0)) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\nexpected \"%s\", got \"%s\"\n",
				       test.desc,
				       test.expected_str ? test.expected_str : "(null)",
				       dup ? dup : "(null)");
			}
			SAFE_FREE(dup);
			break;
		}

		case TEST_RANGE: {
			t_args_range *ar = (t_args_range*)test.args;
			int *tab = ft_range(ar->min, ar->max);
			if (ar->expected_len == 0) {
				if (tab == NULL) {
					printf("✅ OK ");
				} else {
					printf("\n  ❌ FAIL: %s\nexpected NULL, got non-NULL\n", test.desc);
				}
				SAFE_FREE(tab);
				break;
			}
			if (!tab) {
				printf("\n  ❌ FAIL: %s\nexpected array len=%d, got NULL\n", test.desc, ar->expected_len);
				break;
			}
			if (arr_eq(tab, ar->expected, ar->expected_len)) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\ncontent mismatch (len=%d)\n", test.desc, ar->expected_len);
			}
			SAFE_FREE(tab);
			break;
		}

		case TEST_ULTIMATE_RANGE: {
			t_args_urange *ur = (t_args_urange*)test.args;
			int *tab = NULL;
			int ret = ft_ultimate_range(&tab, ur->min, ur->max);

			if (ur->expected_len == 0) {
				if (ret == 0 && tab == NULL) {
					printf("✅ OK ");
				} else {
					printf("\n  ❌ FAIL: %s\nexpected ret=0 & range=NULL, got ret=%d & range=%s\n",
					       test.desc, ret, tab ? "non-NULL" : "NULL");
				}
				SAFE_FREE(tab);
				break;
			}
			if (ret != ur->expected_len || !tab) {
				printf("\n  ❌ FAIL: %s\nexpected len=%d, got ret=%d & range=%s\n",
				       test.desc, ur->expected_len, ret, tab ? "non-NULL" : "NULL");
				SAFE_FREE(tab);
				break;
			}
			if (arr_eq(tab, ur->expected, ur->expected_len)) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\ncontent mismatch (len=%d)\n", test.desc, ur->expected_len);
			}
			SAFE_FREE(tab);
			break;
		}

		case TEST_STRJOIN: {
			t_args_strjoin *sj = (t_args_strjoin*)test.args;
			char *s = ft_strjoin(sj->size, sj->strs, sj->sep);
			if ((test.expected_str == NULL && s == NULL) ||
			    (test.expected_str && s && strcmp(test.expected_str, s) == 0)) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\nexpected \"%s\", got \"%s\"\n",
				       test.desc,
				       test.expected_str ? test.expected_str : "(null)",
				       s ? s : "(null)");
			}
			SAFE_FREE(s);
			break;
		}

		case TEST_CONVERT_BASE: {
			t_args_convert *cb = (t_args_convert*)test.args;
			char *out = ft_convert_base(cb->nbr, cb->base_from, cb->base_to);
			if (!test.expected_str) {
				/* expecting NULL for invalid base/input */
				if (out == NULL) {
					printf("✅ OK ");
				} else {
					printf("\n  ❌ FAIL: %s\nexpected NULL, got \"%s\"\n", test.desc, out);
				}
				SAFE_FREE(out);
				break;
			}
			if (out && strcmp(out, test.expected_str) == 0) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\nexpected \"%s\", got \"%s\"\n",
				       test.desc, test.expected_str, out ? out : "(null)");
			}
			SAFE_FREE(out);
			break;
		}

		case TEST_SPLIT: {
			t_args_split *sp = (t_args_split*)test.args;
			char **tab = ft_split(sp->str, sp->charset);
			int same = strtab_eq(tab, sp->expected);
			if (same) {
				printf("✅ OK ");
			} else {
				printf("\n  ❌ FAIL: %s\nexpected tokens differ (got %d)\n",
				       test.desc, strtab_len(tab));
			}
			strtab_free(tab);
			break;
		}

		default:
			printf("  ❌ Unknown test type\n");
			return 0;
	}
	return 1;
}
