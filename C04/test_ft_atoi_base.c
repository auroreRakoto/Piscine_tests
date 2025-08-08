#include "lib_C04.h"

void	run_test_ft_atoi_base()
{
	char	*msg;
	char	*base;
	char	*nbr;

	printf("======= ex05 - ft_atoi_base =======\n");
	msg = "Test 1 - char base";
	base = "oehl";
	nbr = "hello";
	printf(ORANGE "[CHECK] %s\nbase : %s\nnbr : %s\nres : %d\n", msg, base, nbr, ft_atoi_base(nbr, base));
	msg = "Test 2 - decimal base 1";
	base = "0123456789";
	nbr = "454564654";
	printf(ORANGE "\n[CHECK] %s\nbase : %s\nnbr : %s\nres : %d\n", msg, base, nbr, ft_atoi_base(nbr, base));
	msg = "Test 3 - decimal base 2";
	base = "0123456789";
	nbr = "4";
	printf(ORANGE "\n[CHECK] %s\nbase : %s\nnbr : %s\nres : %d\n", msg, base, nbr, ft_atoi_base(nbr, base));
	msg = "Test 4 - decimal base 2";
	base = "qwertyuiop";
	nbr = "ty";
	printf(ORANGE "\n[CHECK] %s\nbase : %s\nnbr : %s\nres : %d\n", msg, base, nbr, ft_atoi_base(nbr, base));

}
