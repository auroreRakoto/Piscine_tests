#include "lib_C07.h"

int main(void)
{
	t_args_math math_args7 = { .index = 10, .msg = "Test 7 - Positive : 10" };
	/*t_args_math math_args8 = { .index = -2, .msg = "Test 1 - Basic" };
	t_args_math math_args9 = { .index = -1, .msg = "Test 1 - Basic" };
	t_args_math math_args10 = { .index = 0, .msg = "Test 1 - Basic" };
	t_args_math math_args11 = { .index = 1, .msg = "Test 1 - Basic" };
	t_args_math math_args12 = { .index = 2, .msg = "Test 1 - Basic" };
	t_args_math math_args13 = { .index = 3, .msg = "Test 1 - Basic" };
	t_args_math math_args14 = { .index = 9, .msg = "Test 1 - Basic" };*/


	t_test tests[] = {
		// find next prime 
		{ TEST_STRDUP, "Next_Prime", &math_args1, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args2, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args3, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args4, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args5, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args6, .expected_int = 2 },
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args7, .expected_int = 11 },
		
		// iterative factorial 
		//{ TEST_TEN_QUEENS, "Ten_Queens_Puzzle)", 0, .expected_int = 724 }
	};

	int total = sizeof(tests) / sizeof(t_test);
	int passed = 0;
	int	i;

	i = 0;
	while (i < total)
	{
		if (i % 7 == 0)
			printf("\n");
		passed += run_test(tests[i]);
		i++;
	}

	printf("\n=== %d/%d tests passed ===\n", passed, total);
	return 0;
}

