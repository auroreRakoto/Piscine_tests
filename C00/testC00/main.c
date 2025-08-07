#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);

int main(int argc, char **argv)
{
	int		n;
	char	c;

	/// ex00
	if (argc < 2 || strcmp(argv[1], "0") == 0)
	{
		printf("------------------------------\n");
		printf("ex00\n");
		if (argc == 3)
		{
			c = argv[2][0];
			printf("------ Test 1 :\nchar = \"%c\"\nres = \"", c);
			fflush(stdout);
			ft_putchar(c);
			printf("\"\n");
			printf("\n");
		}
		else
		{
			c='a';
			printf("------ Test 1 :\nchar = \"%c\"\nres = \"", c);
			fflush(stdout);
			ft_putchar(c);
			printf("\"\n");
			printf("\n");
			c=' ';
			printf("------ Test 2 :\nchar = \"%c\"\nres = \"", c);
			fflush(stdout);
			ft_putchar(c);
			printf("\"\n");
			printf("\n");
			c='#';
			printf("------ Test 3 :\nchar = \"%c\"\nres = \"", c);
			fflush(stdout);
			ft_putchar(c);
			printf("\"\n");
			printf("\n");
			c=';';
			printf("------ Test 4 :\nchar = \"%c\"\nres = \"", c);
			fflush(stdout);
			ft_putchar(c);
			printf("\"\n");
			printf("\n");
		}
		printf("------------------------------\n");
	}

	/// ex01
	if (argc < 2 || strcmp(argv[1], "1") == 0)
	{
		printf("------------------------------\n");
		printf("ex01\n");
		printf("------ Test 1 :\nalphabet = \"%s\"\nres = \"", "abcdefghijklmnopqrstuvwxyz");
		fflush(stdout);
		ft_print_alphabet();
		printf("\"\n");
		printf("\n");
		printf("------------------------------\n");
	}

	/// ex02
	if (argc < 2 || strcmp(argv[1], "2") == 0)
	{
		printf("------------------------------\n");
		printf("ex02\n");
		printf("------ Test 1 :\nreverse alphabet = \"%s\"\nres = \"", "zyxwvutsrqponmlqjihgfedcba");
		fflush(stdout);
		ft_print_reverse_alphabet();
		printf("\"\n");
		printf("\n");
		printf("------------------------------\n");
	}

	/// ex03
	if (argc < 2 || strcmp(argv[1], "3") == 0)
	{
		printf("------------------------------\n");
		printf("ex03\n");
		printf("------ Test 1 :\nnumbers = \"%s\"\nres = \"", "0123456789");
		fflush(stdout);
		ft_print_numbers();
		printf("\"\n");
		printf("\n");
		printf("------------------------------\n");
	}

	/// ex04
	if (argc < 2 || strcmp(argv[1], "4") == 0)
	{
		
		printf("------------------------------\n");
		printf("ex04\n");
		if (argc == 3)
		{
			n = atoi(argv[2]);
			printf("------ Test 1 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
		}
		else
		{
			n=0;
			printf("------ Test 1 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=-1;
			printf("------ Test 2 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=INT_MIN;
			printf("------ Test 3 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=2147483647;
			printf("------ Test 4 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=INT_MAX;
			printf("------ Test 5 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=5462135;
			printf("------ Test 6 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
			n=-546128;
			printf("------ Test 7 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_is_negative(n);
			printf("\"\n");
			printf("\n");
		}
		printf("------------------------------\n");
	}


	/// ex05
	if (argc < 2 || strcmp(argv[1], "5") == 0)
	{
		printf("------------------------------\n");
		printf("\nex05\n");
		printf("------ Test 1 :\nExpected Output = \"%s\"\nres = \"\n", "012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789");
		fflush(stdout);
		ft_print_comb();
		printf("\"\n\n");
		printf("------------------------------\n");
	}

	// ex06
	if (argc < 2 || strcmp(argv[1], "6") == 0)
	{
		printf("------------------------------\n");
		printf("\nex06\n");
		printf("------ Test 1 :\nExpected Output = \"%s\"\nres = \"\n", "00 01, 00 02, 00 03, 00 04, 00 05, ..., 00 99, 01 02, ..., 97 99, 98 99");
		fflush(stdout);
		ft_print_comb2();
		printf("\"\n\n");
		printf("------------------------------\n");
	}

	/// ex07
	if (argc < 2 || strcmp(argv[1], "7") == 0)
	{
		printf("------------------------------\n");
		printf("ex07\n");
		if (argc == 3)
		{
			n = atoi(argv[2]);
			printf("------ Test 1 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
		}
		else
		{
			
			n=0;
			printf("------ Test 1 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=-1;
			printf("------ Test 2 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=INT_MIN;
			printf("------ Test 3 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=2147483647;
			printf("------ Test 4 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=INT_MAX;
			printf("------ Test 5 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=5462135;
			printf("------ Test 6 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");
			n=-546128;
			printf("------ Test 7 :\nn = \"%d\"\nres = \"", n);
			fflush(stdout);
			ft_putnbr(n);
			printf("\"\n");
			printf("\n");		
		}
		printf("------------------------------\n");
	}

	/// ex08
	if (argc < 2 || strcmp(argv[1], "8") == 0)
	{
		printf("------------------------------\n");
		printf("ex08\n");
		if (argc == 3)
		{
			n = atoi(argv[2]);
			printf("------ Test 1 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
		}
		else
		{
			n = 1;
			printf("------ Test 1 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
			n = 3;
			printf("------ Test 2 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "012, 013, 014, 015, 016, 017, 018, 019, 023, ..., 789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
			n = 5;
			printf("------ Test 3 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "01234, 01235, 01236, ..., 45789, 46789, 56789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
			n = 7;
			printf("------ Test 4 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "0123456, 0123457, 0123458, 0123459, ..., 2356789, 2456789, 3456789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
			n = 8;
			printf("------ Test 5 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "01234567, 01234568, 01234569, ..., 12456789, 13456789, 23456789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
			n = 9;
			printf("------ Test 6 :\nn = %d\nExpected Output = \"%s\"\n\nres = \"", n, "012345678, 012345679, 012345689, 012345789, 012346789, 012356789, 012456789, 013456789, 023456789, 123456789");
			fflush(stdout);
			ft_print_combn(n);
			printf("\"\n\n");
		}
		printf("------------------------------\n");
	}
	return (0);
}