#include "lib_C07.h"

int run_test(t_test test)
{
	printf("Test: %s\n", test.desc);
	switch (test.type)
	{
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
		case TEST_RANGE: {
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
		case TEST_SPLIT: {
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
		default:
			printf("  ❌ Unknown test type\n");
			return 0;
	}
	return 1;
}
