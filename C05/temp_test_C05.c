#include "lib_C05.h"

int run_test(t_test test)
{
    printf("Test: %s\n", test.desc);
    switch (test.type)
    {
        case TEST_FIBONACCI: {
            t_args_fibonacci *args = (t_args_fibonacci *)test.args;
            int result = ft_fibonacci(args->index);
            printf("  Args: index=%d\n", args->index);
            if (result == test.expected_int)
                printf("  ✅ OK: expected %d, got %d\n", test.expected_int, result);
            else
                printf("  ❌ FAIL: expected %d, got %d\n", test.expected_int, result);
            break;
        }
        case TEST_STRDUP: {
            t_args_strdup *args = (t_args_strdup *)test.args;
            char *result = ft_strdup(args->src);
            printf("  Args: src=\"%s\"\n", args->src);
            if (result && strcmp(result, test.expected_str) == 0)
                printf("  ✅ OK: expected \"%s\", got \"%s\"\n", test.expected_str, result);
            else
                printf("  ❌ FAIL: expected \"%s\", got \"%s\"\n", test.expected_str, result ? result : "NULL");
            // ⚠️ Ne pas oublier de free
            free(result);
            break;
        }
        // Ajouter ici d'autres cas comme atoi_base, etc.
        default:
            printf("  ❌ Unknown test type\n");
            return 0;
    }
    return 1;
}
