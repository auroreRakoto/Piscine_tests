#include "lib_C04.h"

void	run_test_ft_atoi()
{
	printf("======= ex03 - ft_atoi =======\n");
	char	*msg;
	char	*s;

	// Test 1 - Basic number
	s = "456";
	msg = "Test 1 - Basic number";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 2 - Leading whitespaces
	s = "   \t\n\v\f\r123";
	msg = "Test 2 - Leading whitespaces";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 3 - Positive sign
	s = "+789";
	msg = "Test 3 - Positive sign";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 4 - Negative sign
	s = "-42";
	msg = "Test 4 - Negative sign";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 5 - Multiple signs (invalid)
	s = "--123";
	msg = "Test 5 - Multiple negative signs (invalid)";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 6 - Alphanumeric input
	s = "123abc";
	msg = "Test 6 - Alphanumeric input";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 7 - Only non-digit characters
	s = "abc123";
	msg = "Test 7 - Starts with non-digit characters";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 8 - Empty string
	s = "";
	msg = "Test 8 - Empty string";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 9 - Zero
	s = "0";
	msg = "Test 9 - Zero";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 10 - Positive zero with sign
	s = "+0";
	msg = "Test 10 - Positive zero with + sign";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 11 - Negative zero
	s = "-0";
	msg = "Test 11 - Negative zero";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 12 - Max int
	s = "2147483647";
	msg = "Test 12 - INT_MAX";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 13 - Min int
	s = "-2147483648";
	msg = "Test 13 - INT_MIN";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 14 - Overflow
	s = "2147483648";
	msg = "Test 14 - Overflow above INT_MAX";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 15 - Underflow
	s = "-2147483649";
	msg = "Test 15 - Underflow below INT_MIN";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 16 - Long number (stop at first invalid)
	s = "12345678901234567890";
	msg = "Test 16 - Very long number";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 17 - Spaces after number
	s = "321   ";
	msg = "Test 17 - Spaces after number";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 18 - Only sign
	s = "+";
	msg = "Test 18 - Only sign +";
	assert_int(atoi(s), ft_atoi(s), msg);

	s = "-";
	msg = "Test 18b - Only sign -";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 19 - Sign then space
	s = "+ 42";
	msg = "Test 19 - Sign followed by space";
	assert_int(atoi(s), ft_atoi(s), msg);

	// Test 20 - Multiple leading zeros
	s = "0000123";
	msg = "Test 20 - Leading zeros";
	assert_int(atoi(s), ft_atoi(s), msg);
}
