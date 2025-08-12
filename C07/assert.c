#include "lib_C07.h"

void	assert_str(char *expected, char *actual, char *msg)
{
	if ((expected == NULL && actual == NULL) || strcmp(expected, actual) == 0)
	{
		printf(GREEN "[PASS] %s\n" RESET, msg);
	}
	else
	{
		printf(RED "[FAIL] %s\nExpected Output: %s\nFunction Output: %s\n\n" RESET, msg, expected, actual);
	}
}

void	assert_int(int expected, int actual, char *msg)
{
	if (expected == actual)
		printf(GREEN "[PASS] %s\n" RESET, msg);
	else
		printf(RED "[FAIL] %s\nExpected Output: %d\nFunction Output: %d\n\n" RESET, msg, expected, actual);
}
