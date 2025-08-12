#include "lib_C07.h"

int main(void)
{
	install_segv_handler();
	
    int passed = 0;

    /* ---------- ex00: ft_strdup ---------- */
    t_args_strdup d1 = { .src = "" };
    t_args_strdup d2 = { .src = "hello" };
    t_args_strdup d3 = { .src = "long_string_abcdefghijklmnopqrstuvwxyz" };

    t_test t_strdup[] = {
        { TEST_STRDUP, "ft_strdup(\"\")", &d1, .expected_str = "" },
        { TEST_STRDUP, "ft_strdup(\"hello\")", &d2, .expected_str = "hello" },
        { TEST_STRDUP, "ft_strdup(long)", &d3, .expected_str = "long_string_abcdefghijklmnopqrstuvwxyz" },
    };

    /* ---------- ex01: ft_range ---------- */
    static const int r_exp1[] = { -2, -1, 0, 1 };
    static const int r_exp2[] = { 1, 2, 3, 4 };
    t_args_range r1 = { .min = -2, .max = 2, .expected = r_exp1, .expected_len = 4 };
    t_args_range r2 = { .min = 1,  .max = 5, .expected = r_exp2, .expected_len = 4 };
    t_args_range r3 = { .min = 5,  .max = 5, .expected = NULL,  .expected_len = 0 };
    t_test t_range[] = {
        { TEST_RANGE, "ft_range(-2,2) -> [-2,-1,0,1]", &r1, .expected_int = 1 },
        { TEST_RANGE, "ft_range(1,5)  -> [1,2,3,4]",   &r2, .expected_int = 1 },
        { TEST_RANGE, "ft_range(5,5)  -> NULL",        &r3, .expected_int = 1 },
    };

    /* ---------- ex02: ft_ultimate_range ---------- */
    static const int ur_exp1[] = { 3, 4, 5, 6 };
    t_args_urange u1 = { .min = 3, .max = 7, .expected = ur_exp1, .expected_len = 4 };
    t_args_urange u2 = { .min = 2, .max = 2, .expected = NULL,    .expected_len = 0 };
    t_test t_urange[] = {
        { TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,3,7) -> len=4", &u1, .expected_int = 4 },
        { TEST_ULTIMATE_RANGE, "ft_ultimate_range(&tab,2,2) -> 0 & NULL", &u2, .expected_int = 0 },
    };

    /* ---------- ex03: ft_strjoin ---------- */
    char *sj_a1[] = { "hello", "world" };
    t_args_strjoin sj1 = { .size = 2, .strs = sj_a1, .sep = " " };
    char *sj_a2[] = { "a", "b", "c" };
    t_args_strjoin sj2 = { .size = 3, .strs = sj_a2, .sep = "," };
    char *sj_a3_dummy[] = { NULL }; /* any pointer ok when size=0 */
    t_args_strjoin sj3 = { .size = 0, .strs = sj_a3_dummy, .sep = "," };
    char *sj_a4[] = { "x", "y" };
    t_args_strjoin sj4 = { .size = 2, .strs = sj_a4, .sep = "" };
    t_test t_strjoin[] = {
        { TEST_STRJOIN, "ft_strjoin([\"hello\",\"world\"], \" \")", &sj1, .expected_str = "hello world" },
        { TEST_STRJOIN, "ft_strjoin([\"a\",\"b\",\"c\"], \",\")",   &sj2, .expected_str = "a,b,c" },
        { TEST_STRJOIN, "ft_strjoin(size=0) -> \"\"",               &sj3, .expected_str = "" },
        { TEST_STRJOIN, "ft_strjoin(sep=\"\")",                     &sj4, .expected_str = "xy" },
    };

    /* ---------- ex04: ft_convert_base ---------- */
    t_args_convert cb1 = { .nbr = "42",       .base_from = "0123456789",      .base_to = "01" };
    t_args_convert cb2 = { .nbr = "-2a",      .base_from = "0123456789abcdef", .base_to = "0123456789" };
    t_args_convert cb3 = { .nbr = "  \t -2a", .base_from = "0123456789abcdef", .base_to = "01" };
    t_args_convert cb4 = { .nbr = "10",       .base_from = "0",               .base_to = "01" }; /* invalid */
    t_args_convert cb5 = { .nbr = "10",       .base_from = "01",              .base_to = "0"  }; /* invalid */
    t_args_convert cb6 = { .nbr = "19",       .base_from = "012345678",       .base_to = "01" }; /* invalid (dup) */
    t_test t_convert[] = {
        { TEST_CONVERT_BASE, "convert 42 (dec->bin)",      &cb1, .expected_str = "101010" },
        { TEST_CONVERT_BASE, "convert -2a (hex->dec)",     &cb2, .expected_str = "-42" },
        { TEST_CONVERT_BASE, "convert with spaces hex->bin",&cb3, .expected_str = "-101010" },
        { TEST_CONVERT_BASE, "invalid base_from len<2",    &cb4, .expected_str = NULL },
        { TEST_CONVERT_BASE, "invalid base_to len<2",      &cb5, .expected_str = NULL },
        { TEST_CONVERT_BASE, "invalid base (duplicate)",   &cb6, .expected_str = NULL },
    };

    /* ---------- ex05: ft_split ---------- */
    const char *sp1_exp[] = { "a","b","c", NULL };
    t_args_split sp1 = { .str = "a,b,c",        .charset = ",",   .expected = sp1_exp };
    const char *sp2_exp[] = { "a","b", NULL };
    t_args_split sp2 = { .str = ",,a,,,b,",     .charset = ",",   .expected = sp2_exp };
    const char *sp3_exp[] = { NULL };
    t_args_split sp3 = { .str = "",             .charset = ",",   .expected = sp3_exp };
    const char *sp4_exp[] = { "abc","def","ghi", NULL };
    t_args_split sp4 = { .str = "abc--def++ghi",.charset = "+-",  .expected = sp4_exp };
    t_test t_split[] = {
        { TEST_SPLIT, "ft_split(\"a,b,c\", \",\")", &sp1, .expected_int = 3 },
        { TEST_SPLIT, "ft_split(\",,a,,,b,\", \",\")", &sp2, .expected_int = 2 },
        { TEST_SPLIT, "ft_split(\"\", \",\")", &sp3, .expected_int = 0 },
        { TEST_SPLIT, "ft_split(\"abc--def++ghi\", \"+-\")", &sp4, .expected_int = 3 },
    };

    /* ---------- run all ---------- */
    int total = 0;

    /* strdup */
    for (size_t i = 0; i < sizeof(t_strdup)/sizeof(t_test); ++i) { passed += run_test(t_strdup[i]); total++; }
    /* range */
    for (size_t i = 0; i < sizeof(t_range)/sizeof(t_test); ++i)  { passed += run_test(t_range[i]); total++; }
    /* ultimate_range */
    for (size_t i = 0; i < sizeof(t_urange)/sizeof(t_test); ++i) { passed += run_test(t_urange[i]); total++; }
    /* strjoin */
    for (size_t i = 0; i < sizeof(t_strjoin)/sizeof(t_test); ++i){ passed += run_test(t_strjoin[i]); total++; }
    /* convert_base */
    for (size_t i = 0; i < sizeof(t_convert)/sizeof(t_test); ++i){ passed += run_test(t_convert[i]); total++; }
    /* split */
    for (size_t i = 0; i < sizeof(t_split)/sizeof(t_test); ++i)  { passed += run_test(t_split[i]); total++; }

    printf("\n=== %d/%d tests passed ===\n", passed, total);
    return (passed == total) ? 0 : 1;
}