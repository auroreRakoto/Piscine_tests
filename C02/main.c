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
	run_test_ft_strcpy();
	printf("\n");
	run_test_ft_strncpy();
	printf("\n");
	run_test_ft_str_is_alpha();
	printf("\n");
	run_test_ft_str_is_numeric();
	printf("\n");
	run_test_ft_str_is_lowercase();
	printf("\n");
	run_test_ft_str_is_uppercase();
	printf("\n");
	run_test_ft_str_is_printable();
	printf("\n");
	run_test_ft_strupcase();
	printf("\n");
	run_test_ft_strlowcase();
	printf("\n");
	run_test_ft_strcapitalize();
	printf("\n");
	run_test_ft_strlcpy();
	printf("\n");
	run_test_ft_putstr_non_printable();
	printf("\n");
	run_test_ft_print_memory();
	printf("\n");
	fclose(log_file);
	return (0);
}