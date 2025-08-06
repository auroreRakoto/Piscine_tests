#include "test_framework.h"

int str_is_printable(const char *s)
{
	if (!s || !*s)
		return 1;

	while (*s) {
		if (!isprint((unsigned char)*s))
			return 0;
		s++;
	}
	return 1;
}


void run_test_ft_str_is_printable(void)
{
	printf("========= ex06 =========\n");

	char src1[] = "Hello, world!";
	assert_int(str_is_printable(src1), ft_str_is_printable(src1), "Test 1 - printable string");

	char src2[] = "\tTab";
	assert_int(str_is_printable(src2), ft_str_is_printable(src2), "Test 2 - tab character (non-printable)");

	char src3[] = "\nNewline";
	assert_int(str_is_printable(src3), ft_str_is_printable(src3), "Test 3 - newline (non-printable)");

	char src4[] = "";
	assert_int(str_is_printable(src4), ft_str_is_printable(src4), "Test 4 - empty string");

	char src5[] = "12345";
	assert_int(str_is_printable(src5), ft_str_is_printable(src5), "Test 5 - digits only");

	char src6[] = "~!@#$%^&*()";
	assert_int(str_is_printable(src6), ft_str_is_printable(src6), "Test 6 - symbols");

	char src7[] = "\x7F"; // DEL character (non-printable)
	assert_int(str_is_printable(src7), ft_str_is_printable(src7), "Test 7 - DEL char (ASCII 127)");
}
