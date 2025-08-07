#include "test_framework.h"

void run_test_ft_putstr_non_printable()
{
	printf("========= ex11 =========\n");

	char str1[] = "Hello\nWorld";
    printf(ORANGE "Test 1 - one special char\nExpected Output : %s\nFunction Output : " RESET, "Hello\\0aWorld");
    fflush(stdout);
	ft_putstr_non_printable(str1);
    printf("\n\n");
	// Expected: Hello\0aWorld
    
	char str2[] = "\tTabbed";
    printf(ORANGE "Test 1 - one special char at the start\nExpected Output : %s\nFunction Output : " RESET, "\\09Tabbed");
    fflush(stdout);
	ft_putstr_non_printable(str2);
    printf("\n\n");
	// Expected: \09Tabbed

	char str3[] = "NormalString";
    printf(ORANGE "Test 1 - normal string\nExpected Output : %s\nFunction Output : " RESET, "NormalString");
    fflush(stdout);
	ft_putstr_non_printable(str3);
    printf("\n\n");
	// Expected: NormalString

	char str4[] = "";
    printf(ORANGE "Test 1 - empty string\nExpected Output : %s\nFunction Output : " RESET, "");
    fflush(stdout);
	ft_putstr_non_printable(str4);
    printf("\n\n");
	// Expected: (nothing)
}