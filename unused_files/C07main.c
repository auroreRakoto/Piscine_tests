#include "lib_C07.h"
#include <stddef.h>

/* Weak declarations: if the function isn't linked, pointer will be NULL */
#if defined(__GNUC__) || defined(__clang__)
char *ft_strjoin(int size, char **strs, char *sep) __attribute__((weak));
char *ft_convert_base(char *nbr, char *base_from, char *base_to) __attribute__((weak));
char **ft_split(char *str, char *charset) __attribute__((weak));
#endif

/* Provided by your test_C07.c */
void install_segv_handler(void);
void set_current_test(const char *desc);

/* Pretty runner: show which test runs, set crash context */
static int run_and_report(t_test t) {
	set_current_test(t.desc);
	printf("• %s ... ", t.desc);
	fflush(stdout);
	int ok = run_test(t);
	if (ok) printf("✅ OK\n");
	return ok;
}

char *mk_repeat(char c, size_t n)
{
	char *s = malloc(n+1);
	for(size_t i=0;i<n;i++)
		s[i]=c;
	s[n]='\0';
	return s;
}

char *mk_ascii_punct(void){
	/* ASCII punctuation set */
	static const char *p="!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	char *s = malloc(strlen(p)+1);
	strcpy(s,p);
	return s;
}
char *mk_mixed_utf8(void){
	/* UTF-8 accents + non-Latin */
	const char *u = "héllö 世界 — Мир 😀";
	char *s = malloc(strlen(u)+1);
	strcpy(s,u);
	return s;
}

int main(void)
{
	install_segv_handler();

	int passed = 0;
	int total  = 0;

	/* ---------- ex00: ft_strdup (expanded) ---------- */	
	char *bigA   = mk_repeat('A', 4096);
	char *bigger = mk_repeat('Z', 16384);
	char *punct  = mk_ascii_punct();
	char *utf8   = mk_mixed_utf8();
	char *spaces = "     ";               /* 5 spaces */
	char *tabsnl = "\t\tline1\nline2\r\n";/* tabs + newlines + CRLF */
	char *quotes = "quote: 'single' and \"double\" and backslash \\"; /* escapes */

	/* Define args + tests */
	t_args_strdup d1  = (t_args_strdup){ .src = "" };
	t_args_strdup d2  = (t_args_strdup){ .src = "hello" };
	t_args_strdup d3  = (t_args_strdup){ .src = "long_string_abcdefghijklmnopqrstuvwxyz" };
	t_args_strdup d4  = (t_args_strdup){ .src = spaces };
	t_args_strdup d5  = (t_args_strdup){ .src = tabsnl };
	t_args_strdup d6  = (t_args_strdup){ .src = "0" };                /* single char */
	t_args_strdup d7  = (t_args_strdup){ .src = "end\0ignored" };     /* note: literal stops at first NUL */
	t_args_strdup d8  = (t_args_strdup){ .src = punct };
	t_args_strdup d9  = (t_args_strdup){ .src = quotes };
	t_args_strdup d10 = (t_args_strdup){ .src = utf8 };
	t_args_strdup d11 = (t_args_strdup){ .src = bigA };
	t_args_strdup d12 = (t_args_strdup){ .src = bigger };

	t_test t_strdup[] = {
		{ TEST_STRDUP, "ft_strdup(\"\")",                                 &d1,  .expected_str = "" },
		{ TEST_STRDUP, "ft_strdup(\"hello\")",                            &d2,  .expected_str = "hello" },
		{ TEST_STRDUP, "ft_strdup(long ascii a..z)",                      &d3,  .expected_str = "long_string_abcdefghijklmnopqrstuvwxyz" },
		{ TEST_STRDUP, "ft_strdup(spaces)",                               &d4,  .expected_str = "     " },
		{ TEST_STRDUP, "ft_strdup(tabs/newlines/CRLF)",                   &d5,  .expected_str = "\t\tline1\nline2\r\n" },
		{ TEST_STRDUP, "ft_strdup(single char '0')",                      &d6,  .expected_str = "0" },
		{ TEST_STRDUP, "ft_strdup(\"end\\0ignored\") (embedded NUL stops)",&d7,  .expected_str = "end" },
		{ TEST_STRDUP, "ft_strdup(punctuation)",                          &d8,  .expected_str = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~" },
		{ TEST_STRDUP, "ft_strdup(quotes & backslash)",                   &d9,  .expected_str = "quote: 'single' and \"double\" and backslash \\" },
		{ TEST_STRDUP, "ft_strdup(utf8 accents & CJK & emoji)",           &d10, .expected_str = "héllö 世界 — Мир 😀" },
		{ TEST_STRDUP, "ft_strdup(4096x 'A')",                            &d11, .expected_str = bigA },
		{ TEST_STRDUP, "ft_strdup(16384x 'Z')",                           &d12, .expected_str = bigger },
	};

	/* ---------- ex01: ft_range (expanded) ---------- */
	static const int r_exp1[]  = { -2, -1, 0, 1 };                      /* cross zero */
	static const int r_exp2[]  = {  1,  2, 3, 4 };                      /* basic */
	//static const int r_exp3[]  = { /* NULL expected */ };               /* min==max */
	//static const int r_exp4[]  = { /* NULL expected */ };               /* min>max  */
	static const int r_exp5[]  = {  0 };                                /* single element */
	static const int r_exp6[]  = { -1 };                                /* single element negative */
	static const int r_exp7[]  = { -3, -2 };                            /* negative only */
	static const int r_exp8[]  = { INT_MIN, INT_MIN+1, INT_MIN+2 };     /* near INT_MIN */
	static const int r_exp9[]  = { INT_MAX-3, INT_MAX-2, INT_MAX-1 };   /* near INT_MAX */
	static const int r_exp10[] = { -100, -99, -98, -97, -96 };          /* small window */

	t_args_range r1  = { .min = -2,         .max =  2,         .expected = r_exp1,  .expected_len = 4 };
	t_args_range r2  = { .min =  1,         .max =  5,         .expected = r_exp2,  .expected_len = 4 };
	t_args_range r3  = { .min =  5,         .max =  5,         .expected = NULL,    .expected_len = 0 }; /* NULL */
	t_args_range r4  = { .min = 10,         .max =  7,         .expected = NULL,    .expected_len = 0 }; /* NULL */
	t_args_range r5  = { .min =  0,         .max =  1,         .expected = r_exp5,  .expected_len = 1 };
	t_args_range r6  = { .min = -1,         .max =  0,         .expected = r_exp6,  .expected_len = 1 };
	t_args_range r7  = { .min = -3,         .max = -1,         .expected = r_exp7,  .expected_len = 2 };
	t_args_range r8  = { .min = INT_MIN,    .max = INT_MIN+3,  .expected = r_exp8,  .expected_len = 3 };
	t_args_range r9  = { .min = INT_MAX-3,  .max = INT_MAX,    .expected = r_exp9,  .expected_len = 3 };
	t_args_range r10 = { .min = -100,       .max = -95,        .expected = r_exp10, .expected_len = 5 };

	t_test t_range[] = {
		{ TEST_RANGE, "ft_range(-2,2) -> [-2,-1,0,1]",                &r1,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(1,5)  -> [1,2,3,4]",                  &r2,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(5,5)  -> NULL",                       &r3,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(10,7) -> NULL (min>max)",             &r4,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(0,1)  -> [0]",                        &r5,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(-1,0) -> [-1]",                       &r6,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(-3,-1)-> [-3,-2]",                    &r7,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(INT_MIN,INT_MIN+3) -> [min,min+1,min+2]", &r8,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(INT_MAX-3,INT_MAX) -> [..,max-1]",    &r9,  .expected_int = 1 },
		{ TEST_RANGE, "ft_range(-100,-95) -> [-100..-96]",            &r10, .expected_int = 1 },
	};


	/* ---------- ex02: ft_ultimate_range (expanded) ---------- */
	static const int ur_exp1[]  = { 3, 4, 5, 6 };                       /* basic */
	//static const int ur_exp2[]  = { /* NULL expected */ };              /* min==max -> 0 & NULL */
	//static const int ur_exp3[]  = { /* NULL expected */ };              /* min>max  -> 0 & NULL */
	static const int ur_exp4[]  = { -3, -2, -1 };                       /* negatives only */
	static const int ur_exp5[]  = { -1, 0, 1 };                         /* cross zero */
	static const int ur_exp6[]  = { 0 };                                /* single element */
	static const int ur_exp7[]  = { INT_MIN, INT_MIN+1 };               /* near INT_MIN */
	static const int ur_exp8[]  = { INT_MAX-2, INT_MAX-1 };             /* near INT_MAX */
	static const int ur_exp9[]  = { -10, -9, -8, -7, -6 };              /* small window */

	t_args_urange u1  = { .min = 3,        .max = 7,         .expected = ur_exp1, .expected_len = 4 };
	t_args_urange u2  = { .min = 2,        .max = 2,         .expected = NULL,    .expected_len = 0 };
	t_args_urange u3  = { .min = 5,        .max = 3,         .expected = NULL,    .expected_len = 0 }; /* min>max */
	t_args_urange u4  = { .min = -3,       .max = 0,         .expected = ur_exp4, .expected_len = 3 };
	t_args_urange u5  = { .min = -1,       .max = 2,         .expected = ur_exp5, .expected_len = 3 };
	t_args_urange u6  = { .min = 0,        .max = 1,         .expected = ur_exp6, .expected_len = 1 };
	t_args_urange u7  = { .min = INT_MIN,  .max = INT_MIN+2, .expected = ur_exp7, .expected_len = 2 };
	t_args_urange u8  = { .min = INT_MAX-2,.max = INT_MAX,   .expected = ur_exp8, .expected_len = 2 };
	t_args_urange u9  = { .min = -10,      .max = -5,        .expected = ur_exp9, .expected_len = 5 };

	t_test t_urange[] = {
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,3,7) -> len=4",          &u1, .expected_int = 4 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,2,2) -> 0 & NULL",       &u2, .expected_int = 0 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,5,3) -> 0 & NULL",       &u3, .expected_int = 0 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,-3,0) -> [-3,-2,-1]",    &u4, .expected_int = 3 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,-1,2) -> [-1,0,1]",      &u5, .expected_int = 3 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,0,1) -> [0]",            &u6, .expected_int = 1 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,INT_MIN,INT_MIN+2)",     &u7, .expected_int = 2 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,INT_MAX-2,INT_MAX)",     &u8, .expected_int = 2 },
		{ TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,-10,-5) -> [-10..-6]",   &u9, .expected_int = 5 },
	};


	/* ---------- ex03: ft_strjoin (expanded) ---------- */
	char *sj_a1[]  = { "hello", "world" };
	t_args_strjoin sj1 = { .size = 2, .strs = sj_a1, .sep = " " };

	char *sj_a2[]  = { "a", "b", "c" };
	t_args_strjoin sj2 = { .size = 3, .strs = sj_a2, .sep = "," };

	char *sj_a3[]  = { NULL }; /* any pointer ok when size=0 */
	t_args_strjoin sj3 = { .size = 0, .strs = sj_a3, .sep = "," };

	char *sj_a4[]  = { "x", "y" };
	t_args_strjoin sj4 = { .size = 2, .strs = sj_a4, .sep = "" };

	/* new cases */
	char *sj_a5[]  = { "solo" };                         /* size=1 */
	t_args_strjoin sj5 = { .size = 1, .strs = sj_a5, .sep = "," };

	char *sj_a6[]  = { "", "" };                         /* both empty */
	t_args_strjoin sj6 = { .size = 2, .strs = sj_a6, .sep = "-" };

	char *sj_a7[]  = { "", "mid", "" };                  /* empties around */
	t_args_strjoin sj7 = { .size = 3, .strs = sj_a7, .sep = "-" };

	char *sj_a8[]  = { "ab", "cd", "" };                 /* last empty, sep="" */
	t_args_strjoin sj8 = { .size = 3, .strs = sj_a8, .sep = "" };

	char *sj_a9[]  = { "ab", "", "cd" };                 /* middle empty */
	t_args_strjoin sj9 = { .size = 3, .strs = sj_a9, .sep = ":" };

	char *sj_a10[] = { "lo", "ng", "er" };               /* multi-char sep */
	t_args_strjoin sj10 = { .size = 3, .strs = sj_a10, .sep = "::" };

	char *sj_a11[] = { "x","x","x","x","x","x","x","x","x","x" }; /* 10 elems */
	t_args_strjoin sj11 = { .size = 10, .strs = sj_a11, .sep = "-" };

	char *sj_a12[] = { "a","b","c" };                    /* sep with spaces */
	t_args_strjoin sj12 = { .size = 3, .strs = sj_a12, .sep = " - " };

	char *sj_extra[] = { "a","b","c","SHOULD_NOT_READ" };
	t_args_strjoin sj13 = { .size = 3, .strs = sj_extra, .sep = "," };

	char *sj_all_empty[] = { "","","" };
	t_args_strjoin sj14 = { .size = 3, .strs = sj_all_empty, .sep = "," };

	char *sj_e1[] = { "", "" };
	t_args_strjoin sje1 = { .size = 2, .strs = sj_e1, .sep = "" };

	char *sj_e2[] = { "single" };
	t_args_strjoin sje2 = { .size = 1, .strs = sj_e2, .sep = "" };




	t_test t_strjoin[] = {
		{ TEST_STRJOIN, "ft_strjoin([\"hello\",\"world\"], \" \")", &sj1,  .expected_str = "hello world" },
		{ TEST_STRJOIN, "ft_strjoin([\"a\",\"b\",\"c\"], \",\")",   &sj2,  .expected_str = "a,b,c" },
		{ TEST_STRJOIN, "ft_strjoin(size=0) -> \"\"",               &sj3,  .expected_str = "" },
		{ TEST_STRJOIN, "ft_strjoin(sep=\"\")",                     &sj4,  .expected_str = "xy" },
		{ TEST_STRJOIN, "ft_strjoin(size=1)",                       &sj5,  .expected_str = "solo" },
		{ TEST_STRJOIN, "ft_strjoin([\"\",\"\"], \"-\")",           &sj6,  .expected_str = "-" },
		{ TEST_STRJOIN, "ft_strjoin([\"\",\"mid\",\"\"], \"-\")",   &sj7,  .expected_str = "-mid-" },
		{ TEST_STRJOIN, "ft_strjoin([\"ab\",\"cd\",\"\"], sep=\"\")",&sj8, .expected_str = "abcd" },
		{ TEST_STRJOIN, "ft_strjoin([\"ab\",\"\",\"cd\"], \":\")",  &sj9,  .expected_str = "ab::cd" },
		{ TEST_STRJOIN, "ft_strjoin([\"lo\",\"ng\",\"er\"], \"::\")",&sj10, .expected_str = "lo::ng::er" },
		{ TEST_STRJOIN, "ft_strjoin(10x\"x\", \"-\")",              &sj11, .expected_str = "x-x-x-x-x-x-x-x-x-x" },
		{ TEST_STRJOIN, "ft_strjoin([\"a\",\"b\",\"c\"], \" - \")", &sj12, .expected_str = "a - b - c" },
		{ TEST_STRJOIN, "ft_strjoin(ignore beyond size)", &sj13, .expected_str = "a,b,c" },
		{ TEST_STRJOIN, "ft_strjoin([\"\",\"\",\"\"], \",\")", &sj14, .expected_str = ",," },
		{ TEST_STRJOIN, "ft_strjoin([\"\"], \"\")", &sje1, .expected_str = "" },
		{ TEST_STRJOIN, "ft_strjoin([\"single\"], \"\")", &sje2, .expected_str = "single" },

	};


	/* ---------- ex04: ft_convert_base ---------- */
	t_args_convert cb1 = { .nbr = "42",       .base_from = "0123456789",       .base_to = "01" };
	t_args_convert cb2 = { .nbr = "-2a",      .base_from = "0123456789abcdef", .base_to = "0123456789" };
	t_args_convert cb3 = { .nbr = "  \t -2a", .base_from = "0123456789abcdef", .base_to = "01" };
	t_args_convert cb4 = { .nbr = "10",       .base_from = "0",                .base_to = "01" }; /* invalid */
	t_args_convert cb5 = { .nbr = "10",       .base_from = "01",               .base_to = "0"  }; /* invalid */
	t_args_convert cb6 = { .nbr = "19",       .base_from = "012345678",        .base_to = "01" }; /* invalid (dup) */

	t_test t_convert[] = {
		{ TEST_CONVERT_BASE, "convert 42 (dec->bin)",        &cb1, .expected_str = "101010" },
		{ TEST_CONVERT_BASE, "convert -2a (hex->dec)",       &cb2, .expected_str = "-42" },
		{ TEST_CONVERT_BASE, "convert with spaces hex->bin", &cb3, .expected_str = "-101010" },
		{ TEST_CONVERT_BASE, "invalid base_from len<2",      &cb4, .expected_str = NULL },
		{ TEST_CONVERT_BASE, "invalid base_to len<2",        &cb5, .expected_str = NULL },
		{ TEST_CONVERT_BASE, "invalid base (duplicate)",     &cb6, .expected_str = NULL },
	};

	/* ---------- ex05: ft_split ---------- */
	const char *sp1_exp[] = { "a","b","c", NULL };
	t_args_split sp1 = { .str = "a,b,c",         .charset = ",",   .expected = sp1_exp };

	const char *sp2_exp[] = { "a","b", NULL };
	t_args_split sp2 = { .str = ",,a,,,b,",      .charset = ",",   .expected = sp2_exp };

	const char *sp3_exp[] = { NULL };
	t_args_split sp3 = { .str = "",              .charset = ",",   .expected = sp3_exp };

	const char *sp4_exp[] = { "abc","def","ghi", NULL };
	t_args_split sp4 = { .str = "abc--def++ghi", .charset = "+-",  .expected = sp4_exp };

	t_test t_split[] = {
		{ TEST_SPLIT, "ft_split(\"a,b,c\", \",\")",               &sp1, .expected_int = 3 },
		{ TEST_SPLIT, "ft_split(\",,a,,,b,\", \",\")",            &sp2, .expected_int = 2 },
		{ TEST_SPLIT, "ft_split(\"\", \",\")",                    &sp3, .expected_int = 0 },
		{ TEST_SPLIT, "ft_split(\"abc--def++ghi\", \"+-\")",      &sp4, .expected_int = 3 },
	};

	/* ---------- run all ---------- */

	/* strdup */
	for (size_t i = 0; i < sizeof(t_strdup)/sizeof(t_test); ++i) {
		passed += run_and_report(t_strdup[i]); total++;
	}

	/* range */
	for (size_t i = 0; i < sizeof(t_range)/sizeof(t_test); ++i) {
		passed += run_and_report(t_range[i]); total++;
	}

	/* ultimate_range */
	for (size_t i = 0; i < sizeof(t_urange)/sizeof(t_test); ++i) {
		passed += run_and_report(t_urange[i]); total++;
	}

	/* strjoin — skip if not linked */
	if (ft_strjoin) {
		for (size_t i = 0; i < sizeof(t_strjoin)/sizeof(t_test); ++i) {
			passed += run_and_report(t_strjoin[i]); total++;
		}
	} else {
		printf("⏭️  Skip ex03 (ft_strjoin missing)\n");
	}

	/* convert_base — skip if not linked */
	if (ft_convert_base) {
		for (size_t i = 0; i < sizeof(t_convert)/sizeof(t_test); ++i) {
			passed += run_and_report(t_convert[i]); total++;
		}
	} else {
		printf("⏭️  Skip ex04 (ft_convert_base missing)\n");
	}

	/* split — skip if not linked */
	if (ft_split) {
		for (size_t i = 0; i < sizeof(t_split)/sizeof(t_test); ++i) {
			passed += run_and_report(t_split[i]); total++;
		}
	} else {
		printf("⏭️  Skip ex05 (ft_split missing)\n");
	}

	free(bigA);
	free(bigger);
	free(punct);
	free(utf8);


	printf("\n=== %d/%d tests passed ===\n", passed, total);
	return (passed == total) ? 0 : 1;
}
