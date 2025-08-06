#include "test_framework.h"

int str_is_lowercase(const char *s)
{
	if (!s || !*s)
		return 1;

	while (*s) {
		if (!islower((unsigned char)*s))
			return 0;
		s++;
	}
	return 1;
}

void run_test_ft_str_is_lowercase(void)
{
	printf("========= ex04 =========\n");

	char src1[] = "abcxyz";
	assert_int(str_is_lowercase(src1), ft_str_is_lowercase(src1), "Test 1 - lowercase only");

	char src2[] = "ABC";
	assert_int(str_is_lowercase(src2), ft_str_is_lowercase(src2), "Test 2 - uppercase only");

	char src3[] = "abc123";
	assert_int(str_is_lowercase(src3), ft_str_is_lowercase(src3), "Test 3 - lower + digits");

	char src4[] = "";
	assert_int(str_is_lowercase(src4), ft_str_is_lowercase(src4), "Test 4 - empty string");

	char src5[] = "aBc";
	assert_int(str_is_lowercase(src5), ft_str_is_lowercase(src5), "Test 5 - mixed case");

	char src6[] = "z";
	assert_int(str_is_lowercase(src6), ft_str_is_lowercase(src6), "Test 6 - single lowercase letter");

	char src7[] = "[";
	assert_int(str_is_lowercase(src7), ft_str_is_lowercase(src7), "Test 7 - character before 'a'");
}
