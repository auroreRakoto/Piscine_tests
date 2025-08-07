#include "test_framework.h"

void run_test_ft_strupcase()
{
	printf("========= ex07 =========\n");

	char str1[] = "hello";
	assert_str("HELLO", ft_strupcase(str1), "Test 1 - lowercase");

	char str2[] = "HELLO";
	assert_str("HELLO", ft_strupcase(str2), "Test 2 - already uppercase");

	char str3[] = "Hello42World!";
	assert_str("HELLO42WORLD!", ft_strupcase(str3), "Test 3 - mixed with symbols");

	char str4[] = "";
	assert_str("", ft_strupcase(str4), "Test 4 - empty string");

	char str5[] = "1234";
	assert_str("1234", ft_strupcase(str5), "Test 5 - numeric only");
}
