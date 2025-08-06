#include "test_framework.h"

int str_is_uppercase(const char *s)
{
	if (!s || !*s)
		return 1;

	while (*s) {
		if (!isupper((unsigned char)*s))
			return 0;
		s++;
	}
	return 1;
}


void run_test_ft_str_is_uppercase(void)
{
	printf("========= ex05 =========\n");

	char src1[] = "ABCXYZ";
	assert_int(str_is_uppercase(src1), ft_str_is_uppercase(src1), "Test 1 - uppercase only");

	char src2[] = "abc";
	assert_int(str_is_uppercase(src2), ft_str_is_uppercase(src2), "Test 2 - lowercase only");

	char src3[] = "ABC123";
	assert_int(str_is_uppercase(src3), ft_str_is_uppercase(src3), "Test 3 - upper + digits");

	char src4[] = "";
	assert_int(str_is_uppercase(src4), ft_str_is_uppercase(src4), "Test 4 - empty string");

	char src5[] = "AbC";
	assert_int(str_is_uppercase(src5), ft_str_is_uppercase(src5), "Test 5 - mixed case");

	char src6[] = "A";
	assert_int(str_is_uppercase(src6), ft_str_is_uppercase(src6), "Test 6 - single uppercase letter");

	char src7[] = "@";
	assert_int(str_is_uppercase(src7), ft_str_is_uppercase(src7), "Test 7 - character before 'A'");
}
