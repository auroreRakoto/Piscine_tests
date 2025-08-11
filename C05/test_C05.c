#include "lib_C05.h"

int run_test(t_test test)
{
	//printf("Test: %s\n", test.desc);
	switch (test.type)
	{
		case TEST_IT_FACTO: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_iterative_factorial(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_REC_FACTO: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_recursive_factorial(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_IT_POWER: {
			t_args_power *args = (t_args_power *)test.args;
			int result = ft_iterative_power(args->index, args->power);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_REC_POWER: {
			t_args_power *args = (t_args_power *)test.args;
			int result = ft_recursive_power(args->index, args->power);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_FIBONACCI: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_fibonacci(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_SQRT: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_sqrt(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_FIND_PRIME: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_is_prime(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_NEXT_PRIME: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_find_next_prime(args->index);
			//printf("  Args: index=%d\n", args->index);
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}
		case TEST_TEN_QUEENS: {
			t_args_math *args = (t_args_math *)test.args;
			int result = ft_ten_queens_puzzle();
			if (result == test.expected_int)
				printf("✅ OK ");
				//printf("  ✅ OK: %s\nexpected %d, got %d\n", args->msg, test.expected_int, result);
			else
				printf("\n  ❌ FAIL: %s %s\nexpected %d, got %d\n", args->msg, test.desc, test.expected_int, result);
			break;
		}

		
		// Ajouter ici d'autres cas comme atoi_base, etc.
		default:
			printf("  ❌ Unknown test type\n");
			return 0;
	}
	return 1;
}
