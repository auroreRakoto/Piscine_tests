#include "test_framework.h"


int		tests_passed = 0;
int		tests_fail = 0;

// ========= TESTS =========
int main(void)
{
	log_file = fopen("output.txt", "w");
	if (!log_file)
	{
		printf(RED "Could not open file!" RESET);
		return (1);
	}
	assert_str("hello", "hello", "Test 1 - testing the tests");
	assert_str("helddlo", "hello", "Test 2 - testing wrong expected");
	assert_str("hello", "hellddo", "Test 3 - testing wrong output");
	assert_int(42, 42, "Test 4 - testing correct int");
	assert_int(42, 40, "Test 5 - testing wrong int");
	run_test_ft_strcpy();
	printf("\n");
	run_test_ft_strncpy();
	printf("\n");
	fclose(log_file);
	return (0);
}