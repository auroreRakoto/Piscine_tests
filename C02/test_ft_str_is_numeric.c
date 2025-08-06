#include "test_framework.h"

int str_is_numeric(const char *s)
{
	if (!s || !*s)
		return 1;  // empty string is considered valid

	while (*s) {
		if (!isdigit((unsigned char)*s))
			return 0;
		s++;
	}
	return 1;
}

void run_test_ft_str_is_numeric(void)
{
	printf("========= ex03 =========\n");

	char src1[] = "123456";
	assert_int(str_is_numeric(src1), ft_str_is_numeric(src1), "Test 1 - digits only");

	char src2[] = "42abc";
	assert_int(str_is_numeric(src2), ft_str_is_numeric(src2), "Test 2 - digits + letters");

	char src3[] = "";
	assert_int(str_is_numeric(src3), ft_str_is_numeric(src3), "Test 3 - empty string");

	char src4[] = " ";
	assert_int(str_is_numeric(src4), ft_str_is_numeric(src4), "Test 4 - space");

	char src5[] = "007";
	assert_int(str_is_numeric(src5), ft_str_is_numeric(src5), "Test 5 - leading zeros");

	char src6[] = "abc";
	assert_int(str_is_numeric(src6), ft_str_is_numeric(src6), "Test 6 - letters only");

	char src7[] = "0";
	assert_int(str_is_numeric(src7), ft_str_is_numeric(src7), "Test 7 - single digit");
}
