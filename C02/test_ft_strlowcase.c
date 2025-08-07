#include "test_framework.h"

void run_test_ft_strlowcase()
{
	printf("========= ex08 =========\n");

	char str1[] = "HELLO";
	assert_str("hello", ft_strlowcase(str1), "Test 1 - uppercase");

	char str2[] = "hello";
	assert_str("hello", ft_strlowcase(str2), "Test 2 - already lowercase");

	char str3[] = "Hello42World!";
	assert_str("hello42world!", ft_strlowcase(str3), "Test 3 - mixed with symbols");

	char str4[] = "";
	assert_str("", ft_strlowcase(str4), "Test 4 - empty string");

	char str5[] = "1234";
	assert_str("1234", ft_strlowcase(str5), "Test 5 - numeric only");
}
