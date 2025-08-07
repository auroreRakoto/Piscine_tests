#include "test_framework.h"

int str_is_alpha(const char *s)
{
	int i = 0;
	while (s[i]) {
		if (!isalpha((unsigned char)s[i]))
			return 0;
		i++;
	}
	return 1;
}

void run_test_ft_str_is_alpha()
{
	printf("========= ex02 =========\n");

	char src1[] = "hello";
	assert_int(str_is_alpha(src1), ft_str_is_alpha(src1), "Test 1 - basic string");

	char src2[] = "@";
	assert_int(str_is_alpha(src2), ft_str_is_alpha(src2), "Test 2 - under min");

	char src3[] = "A";
	assert_int(str_is_alpha(src3), ft_str_is_alpha(src3), "Test 3 - min");

	char src4[] = "[";
	assert_int(str_is_alpha(src4), ft_str_is_alpha(src4), "Test 4 - middle");

	char src5[] = "{";
	assert_int(str_is_alpha(src5), ft_str_is_alpha(src5), "Test 5 - over max");

	char src6[] = "z";
	assert_int(str_is_alpha(src6), ft_str_is_alpha(src6), "Test 6 - max");

	char src7[] = "LoremIpsumDolorSitAmet";
	assert_int(str_is_alpha(src7), ft_str_is_alpha(src7), "Test 7 - long all-alpha");

	char src8[] = "Lorem Ipsum 42!";
	assert_int(str_is_alpha(src8), ft_str_is_alpha(src8), "Test 8 - long with spaces and symbols");
}
