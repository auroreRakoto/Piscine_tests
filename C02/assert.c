#include "test_framework.h"

FILE	*log_file = NULL;

// ========= ASSERTIONS =========
void	assert_str(char *expected, char *actual, char *message)
{
	if (strcmp(expected, actual)==0)
	{
		printf(GREEN "[PASS] %s\n" RESET, message);
		//tests_passed++;
	}
	else
	{
		printf(RED "[FAIL] %s\nExpected Output : %s\nFonction Output : %s\n\n" RESET, message, expected, actual);
		//tests_fail++;
	}
	fprintf(log_file, "[%s]\n", message);
	fprintf(log_file, "Expected: ->%s<-\n", expected);
	fprintf(log_file, "Function: ->%s<-\n\n", actual);
}

void	assert_int(int expected, int actual, char *message)
{
	if (expected == actual)
	{
		printf(GREEN "[PASS] %s\n" RESET, message);
		//tests_passed++;
	}
	else
	{
		printf(RED "[FAIL] %s\nExpected Output : %d\nFonction Output : %d\n\n" RESET, message, expected, actual);
		//tests_fail++;
	}
	fprintf(log_file, "[%s]\n", message);
	fprintf(log_file, "Expected: ->%d<-\n", expected);
	fprintf(log_file, "Function: ->%d<-\n\n", actual);
}

void	assert_uint(unsigned int expected, unsigned int actual, char *message)
{
	if (expected == actual)
	{
		printf(GREEN "[PASS] %s\n" RESET, message);
		//tests_passed++;
	}
	else
	{
		printf(RED "[FAIL] %s\nExpected Output : %d\nFonction Output : %d\n\n" RESET, message, expected, actual);
		//tests_fail++;
	}
	fprintf(log_file, "[%s]\n", message);
	fprintf(log_file, "Expected: ->%d<-\n", expected);
	fprintf(log_file, "Function: ->%d<-\n\n", actual);
}