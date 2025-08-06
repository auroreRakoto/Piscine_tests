#include "C03_lib.h"

void	assert_str(char *expected, char *actual, char *msg)
{
	if (strcmp(expected, actual) == 0)
	{
		printf("[PASS] %s\n", msg);
	}
	else
	{
		printf("[FAIL] %s\nExpected Output: %s\nFunction Output: %s\n", msg, expected, actual);
	}
}
