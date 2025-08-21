#include "lib_C05.h"

int main(void)
{
    t_args_fibonacci fib_args1 = { .index = 9 };
    t_args_strdup strdup_args1 = { .src = "hello" };

    t_test tests[] = {
        { TEST_FIBONACCI, "Fibonacci(9)", &fib_args1, .expected_int = 34 },
        { TEST_STRDUP, "Strdup 'hello'", &strdup_args1, .expected_str = "hello" },
    };

    int total = sizeof(tests) / sizeof(t_test);
    int passed = 0;

    for (int i = 0; i < total; i++)
        passed += run_test(tests[i]);

    printf("=== %d/%d tests passed ===\n", passed, total);
    return 0;
}

