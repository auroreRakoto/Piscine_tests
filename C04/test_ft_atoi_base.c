#include "lib_C04.h"

void	run_test_ft_atoi_base()
{
	char	*msg;
	char	*base;
	char	*nbr;
	int		expected;

	printf("======= ex05 - ft_atoi_base =======\n");

	msg = "Test 1 - char base";
	nbr = "hello";
	base = "oehl";
	expected = 636;
	assert_int(expected, ft_atoi_base(nbr, base), msg);

	msg = "Test 2 - decimal base 1";
	nbr = "454564654";
	base = "0123456789";
	expected = 454564654;
	assert_int(expected, ft_atoi_base(nbr, base), msg);


	msg = "Test 3 - decimal base 2";
	nbr = "565482135";
	base = "0123456789";
	expected = 565482135;
	assert_int(expected, ft_atoi_base(nbr, base), msg);
	
	msg = "Test 4 - decimal base 3";
	nbr = "454564654";
	base = "0123456789";
	expected = 454564654;
	assert_int(expected, ft_atoi_base(nbr, base), msg);
		
	msg = "Test 5 - Convert a binary number to decimal";
	nbr = "101101";
	base = "01";
	expected = 45;
	assert_int(expected, ft_atoi_base(nbr, base), msg);

	msg = "Test 6 - Convert a hexadecimal number to decimal";
	nbr = "ff";
	base = "0123456789abcdef";
	expected = 255;
	assert_int(expected, ft_atoi_base(nbr, base), msg);

	msg = "Test 7 - Convert a number with leading whitespace and sign to decimal";
	nbr = "    +-14353";
	base = "0123456789";
	expected = -14353;
	assert_int(expected, ft_atoi_base(nbr, base), msg);

	msg = "Test 8 - Convert a binary number with leading whitespace and sign to decimal";
	nbr = "         ---10101001";
	base = "01";
	expected = -169;
	assert_int(expected, ft_atoi_base(nbr, base), msg);

	msg = "Test 9 - Convert a hexadecimal number with leading whitespace and sign to decimal";
	nbr = "     +---59";
	base = "0123456789abcdef";
	expected = -89;
	assert_int(expected, ft_atoi_base(nbr, base), msg);
}


/*
  .desc = "Convert a number with leading whitespace and sign to decimal",
            .str = "    +-14353",
            .base = "0123456789",
            .expected_output = -14353,
        },
        {
            .desc = "Convert a binary number with leading whitespace and sign to decimal",
            .str = "         ---10101001",
            .base = "01",
            .expected_output = -169,
        },
        {
            .desc = "Convert a hexadecimal number with leading whitespace and sign to decimal",
            .str = "     +---59",
            .base = "0123456789abcdef",
            .expected_output = -89,
        },

*/