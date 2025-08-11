#include "lib_C04.h"

void	assert_str(char *expected, char *actual, char *msg)
{
	if ((expected == NULL && actual == NULL) || strcmp(expected, actual) == 0)
	{
		printf(GREEN "[PASS] %s\nExpected Output: %s\nFunction Output: %s\n" RESET, msg, expected, actual);
	}
	else
	{
		printf(RED "[FAIL] %s\nExpected Output: %s\nFunction Output: %s\n\n" RESET, msg, expected, actual);
	}
}

void	assert_int(int expected, int actual, char *msg)
{
	if (expected == actual)
		printf(GREEN "[PASS] %s\nExpected Output: %d\nFunction Output: %d\n" RESET, msg, expected, actual);
	else
		printf(RED "[FAIL] %s\nExpected Output: %d\nFunction Output: %d\n\n" RESET, msg, expected, actual);
}

void assert_self(int expected, int actual, char *msg)
{
	printf(ORANGE "[CHECK] %s\nExpected Output: %d\nFunction Output: %d\n\n" RESET, msg, expected, actual);
}
