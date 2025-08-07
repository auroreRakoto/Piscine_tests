#include "lib_C04.h"

void	run_test_ft_putnbr_base()
{
	printf("======= ex0 - ft_putnbr_base =======\n");
	char	*msg;
	int		nbr;
	char	*base;
	
	msg = "Test 1 - Basic number";
	nbr = 45;
	base = "0123456789";
	printf(ORANGE "[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 2 - Longer number";
	nbr = 41357645;
	base = "0123456789";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 3 - Negative number";
	nbr = -41357645;
	base = "0123456789";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 4 - INT_MIN";
	nbr = INT_MIN;
	base = "0123456789";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 5 - INT_MAX";
	nbr = INT_MAX;
	base = "0123456789";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 6 - Other Base";
	nbr = INT_MAX;
	base = "01234";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 7 - Other Base";
	nbr = 12345;
	base = "salut";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 8 - Duplicate in Base";
	nbr = 12345;
	base = "saluta";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 8 - + in Base";
	nbr = 12345;
	base = "salut +";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);

	msg = "Test 8 - Empty Base";
	nbr = 12345;
	base = "";
	printf(ORANGE "\n\n[CHECK] %s\nNumber: %d\nBase: %s\n\n" RESET, msg, nbr, base);
	ft_putnbr_base(nbr, base);
}