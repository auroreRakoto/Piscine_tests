#include "lib_C04.h"

void	run_test_ft_atoi_base()
{
	printf("res : %d\n", ft_atoi_base("hello", "oehl"));
	printf("res : %d\n", ft_atoi_base("54614321", "0123456789"));
	printf("res : %d\n", ft_atoi_base("5", "0123456789"));
}