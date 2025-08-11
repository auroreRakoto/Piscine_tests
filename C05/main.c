#include "lib_C05.h"

int main(void)
{
	// factorial + fibonacci + sqrt + prime + next_prime
	t_args_math math_args1 = { .index = -2147483648, .msg = "Test 1 - Negative : INT_MIN" };
	t_args_math math_args2 = { .index = -6536, .msg = "Test 2 - Negative : - 6536" };
	t_args_math math_args3 = { .index = -2, .msg = "Test 3 - Negative : -2" };
	t_args_math math_args4 = { .index = -1, .msg = "Test 4 - Negative : -1" };
	t_args_math math_args5 = { .index = 0, .msg = "Test 5 - Trivial : 0" };
	t_args_math math_args6 = { .index = 1, .msg = "Test 6 - Trivial : 1" };
	t_args_math math_args7 = { .index = 10, .msg = "Test 7 - Positive : 10" };
	/*t_args_math math_args8 = { .index = -2, .msg = "Test 1 - Basic" };
	t_args_math math_args9 = { .index = -1, .msg = "Test 1 - Basic" };
	t_args_math math_args10 = { .index = 0, .msg = "Test 1 - Basic" };
	t_args_math math_args11 = { .index = 1, .msg = "Test 1 - Basic" };
	t_args_math math_args12 = { .index = 2, .msg = "Test 1 - Basic" };
	t_args_math math_args13 = { .index = 3, .msg = "Test 1 - Basic" };
	t_args_math math_args14 = { .index = 9, .msg = "Test 1 - Basic" };*/
	// power
	
	t_args_power power_args1 = { .index = 5, .power = 0, .msg = "Test 1 - Basic" };
	t_args_power power_args2 = { .index = 0, .power = 5, .msg = "Test 2 - Basic" };
	t_args_power power_args3 = { .index = 0, .power = 0, .msg = "Test 3 - Basic" };
	t_args_power power_args4 = { .index = 2, .power = 10, .msg = "Test 4 - Basic" };
	t_args_power power_args5 = { .index = -3, .power = 4, .msg = "Test 5 - Basic" };
	t_args_power power_args6 = { .index = 3, .power = -4, .msg = "Test 6 - Basic" };
	t_args_power power_args7 = { .index = 12, .power = 9, .msg = "Test 7 - Basic" };


	t_test tests[] = {
		// iterative factorial 
		{ TEST_IT_FACTO, "It_Facto", &math_args1, .expected_int = 0 },
		{ TEST_IT_FACTO, "It_Facto", &math_args2, .expected_int = 0 },
		{ TEST_IT_FACTO, "It_Facto", &math_args3, .expected_int = 0 },
		{ TEST_IT_FACTO, "It_Facto", &math_args4, .expected_int = 0 },
		{ TEST_IT_FACTO, "It_Facto", &math_args5, .expected_int = 1 },
		{ TEST_IT_FACTO, "It_Facto", &math_args6, .expected_int = 1 },
		{ TEST_IT_FACTO, "It_Facto", &math_args7, .expected_int = 3628800 },

		// recursive factorial 
		{ TEST_REC_FACTO, "Rec_Facto", &math_args1, .expected_int = 0 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args2, .expected_int = 0 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args3, .expected_int = 0 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args4, .expected_int = 0 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args5, .expected_int = 1 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args6, .expected_int = 1 },
		{ TEST_REC_FACTO, "Rec_Facto", &math_args7, .expected_int = 3628800 },
		
		// iterative power 
		{ TEST_IT_POWER, "It_Power", &power_args1, .expected_int = 1 },
		{ TEST_IT_POWER, "It_Power", &power_args2, .expected_int = 0 },
		{ TEST_IT_POWER, "It_Power", &power_args3, .expected_int = 1 },
		{ TEST_IT_POWER, "It_Power", &power_args4, .expected_int = 1024 },
		{ TEST_IT_POWER, "It_Power", &power_args5, .expected_int = 81 },
		{ TEST_IT_POWER, "It_Power", &power_args6, .expected_int = 0 },
		{ TEST_IT_POWER, "It_Power", &power_args7, .expected_int = 864813056 },
		
		// recursive factorial 
		{ TEST_REC_POWER, "Rec_Power", &power_args1, .expected_int = 1 },
		{ TEST_REC_POWER, "Rec_Power", &power_args2, .expected_int = 0 },
		{ TEST_REC_POWER, "Rec_Power", &power_args3, .expected_int = 1 },
		{ TEST_REC_POWER, "Rec_Power", &power_args4, .expected_int = 1024 },
		{ TEST_REC_POWER, "Rec_Power", &power_args5, .expected_int = 81 },
		{ TEST_REC_POWER, "Rec_Power", &power_args6, .expected_int = 0 },
		{ TEST_REC_POWER, "Rec_Power", &power_args7, .expected_int = 864813056 },
		
		// fibonacci
		{ TEST_FIBONACCI, "Fibonacci", &math_args1, .expected_int = -1 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args2, .expected_int = -1 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args3, .expected_int = -1 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args4, .expected_int = -1 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args5, .expected_int = 0 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args6, .expected_int = 1 },
		{ TEST_FIBONACCI, "Fibonacci", &math_args7, .expected_int = 55 },
		
		// sqrt 
		{ TEST_SQRT, "Sqrt", &math_args1, .expected_int = 0 },
		{ TEST_SQRT, "Sqrt", &math_args2, .expected_int = 0 },
		{ TEST_SQRT, "Sqrt", &math_args3, .expected_int = 0 },
		{ TEST_SQRT, "Sqrt", &math_args4, .expected_int = 0 },
		{ TEST_SQRT, "Sqrt", &math_args5, .expected_int = 0 },
		{ TEST_SQRT, "Sqrt", &math_args6, .expected_int = 1 },
		{ TEST_SQRT, "Sqrt", &math_args7, .expected_int = 0 },
		
		// find prime 
		{ TEST_FIND_PRIME, "Prime", &math_args1, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args2, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args3, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args4, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args5, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args6, .expected_int = 0 },
		{ TEST_FIND_PRIME, "Prime", &math_args7, .expected_int = 0 },
		
		// find next prime 
		{ TEST_NEXT_PRIME, "Next_Prime", &math_args1, .expected_int = 2 },
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

