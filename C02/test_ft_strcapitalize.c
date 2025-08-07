#include "test_framework.h"

void run_test_ft_strcapitalize()
{
	printf("========= ex09 =========\n");

	char str1[] = "hello world";
	assert_str("Hello World", ft_strcapitalize(str1), "Test 1 - basic words");

	char str2[] = "HELLO-WORLD";
	assert_str("Hello-World", ft_strcapitalize(str2), "Test 2 - all uppercase");

	char str3[] = "42is the answer";
	assert_str("42is The Answer", ft_strcapitalize(str3), "Test 3 - starts with number");

	char str4[] = "";
	assert_str("", ft_strcapitalize(str4), "Test 4 - empty string");

	char str5[] = "hi, how are you? 42words forty-two; fifty+and+one";
	assert_str("Hi, How Are You? 42words Forty-Two; Fifty+And+One", ft_strcapitalize(str5), "Test 5 - complex sentence");
}
