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

void run_test_ft_is_alpha()
{
	printf("========= ex02 =========\n");

	char src1[] = "hello";
	assert_int(str_is_alpha(src1), ft_is_alpha(src1), "Test 1 - basic string");

	char src2[] = "@";
	assert_int(str_is_alpha(src2), ft_is_alpha(src2), "Test 2 - under min");

	char src3[] = "A";
	assert_int(str_is_alpha(src3), ft_is_alpha(src3), "Test 3 - min");

	char src4[] = "[";
	assert_int(str_is_alpha(src4), ft_is_alpha(src4), "Test 4 - over max");

	char src5[] = "z";
	assert_int(str_is_alpha(src5), ft_is_alpha(src5), "Test 5 - max");

	char src6[] = "LoremIpsumDolorSitAmet";
	assert_int(str_is_alpha(src6), ft_is_alpha(src6), "Test 6 - long all-alpha");

	char src7[] = "Lorem Ipsum 42!";
	assert_int(str_is_alpha(src7), ft_is_alpha(src7), "Test 7 - long with spaces and symbols");
}
