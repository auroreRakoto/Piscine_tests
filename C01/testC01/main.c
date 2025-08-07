#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>


void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);


void	print_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int	n;
	int	*p1;
	int **p2;
	int ***p3;
	int ****p4;
	int *****p5;
	int ******p6;
	int *******p7;
	int ********p8;
	int *********p9;
	int	a = 0;
	int	b = 0;
	int	div = 0;
	int	mod = 0;

    if (ac < 2 || strcmp(av[1], "0") == 0)
	{
		printf("------------------------------\n");
		printf("\nex00\n");
		if (ac == 3)
		{
			n = atoi(av[2]);
			printf("- Test 1 :\n   n value before ft_ft : n = %d\n", n);
			ft_ft(&n);
			printf("   n value after ft_ft : n = %d\n\n", n);
		}
		else
		{
			n = 50;
			printf("- Test 1 :\n   n value before ft_ft : n = %d\n", n);
			ft_ft(&n);
			printf("   n value after ft_ft : n = %d\n\n", n);
			n = -5;
			printf("- Test 2 :\n   n value before ft_ft : n = %d\n", n);
			ft_ft(&n);
			printf("   n value after ft_ft : n = %d\n\n", n);
			n = 0;
			printf("- Test 3 :\n   n value before ft_ft : n = %d\n", n);
			ft_ft(&n);
			printf("   n value after ft_ft : n = %d\n\n", n);
			n = 246156;
			printf("- Test 4 :\n   n value before ft_ft : n = %d\n", n);
			ft_ft(&n);
			printf("   n value after ft_ft : n = %d\n\n", n);
		}
		printf("------------------------------\n");
	}

	if (ac < 2 || strcmp(av[1], "1") == 0)
	{
		printf("------------------------------\n");
		printf("\nex01\n");
		if (ac == 3)
		{
			n = atoi(av[2]);
			p1 = &n;
			p2 = &p1;
			p3 = &p2;
			p4 = &p3;
			p5 = &p4;
			p6 = &p5;
			p7 = &p6;
			p8 = &p7;
			p9 = &p8;
			printf("- Test 1 :\n   n value before ft_ultimate_ft : n = %d\n", n);
			ft_ultimate_ft(p9);
			printf("   n value after ft_ultimate_ft : n = %d\n\n", n);
		}
		else
		{
			n = 50;
			p1 = &n;
			p2 = &p1;
			p3 = &p2;
			p4 = &p3;
			p5 = &p4;
			p6 = &p5;
			p7 = &p6;
			p8 = &p7;
			p9 = &p8;
			printf("- Test 1 :\n   n value before ft_ultimate_ft : n = %d\n", n);
			ft_ultimate_ft(p9);
			printf("   n value after ft_ultimate_ft : n = %d\n\n", n);
			n = -5;
			p1 = &n;
			p2 = &p1;
			p3 = &p2;
			p4 = &p3;
			p5 = &p4;
			p6 = &p5;
			p7 = &p6;
			p8 = &p7;
			p9 = &p8;
			printf("- Test 2 :\n   n value before ft_ultimate_ft : n = %d\n", n);
			ft_ultimate_ft(p9);
			printf("   n value after ft_ultimate_ft : n = %d\n\n", n);
			n = 0;
			p1 = &n;
			p2 = &p1;
			p3 = &p2;
			p4 = &p3;
			p5 = &p4;
			p6 = &p5;
			p7 = &p6;
			p8 = &p7;
			p9 = &p8;
			printf("- Test 3 :\n   n value before ft_ultimate_ft : n = %d\n", n);
			ft_ultimate_ft(p9);
			printf("   n value after ft_ultimate_ft : n = %d\n\n", n);
			n = 246156;
			p1 = &n;
			p2 = &p1;
			p3 = &p2;
			p4 = &p3;
			p5 = &p4;
			p6 = &p5;
			p7 = &p6;
			p8 = &p7;
			p9 = &p8;
			printf("- Test 4 :\n   n value before ft_ultimate_ft : n = %d\n", n);
			ft_ultimate_ft(p9);
			printf("   n value after ft_ultimate_ft : n = %d\n\n", n);
		}
		printf("------------------------------\n");
	}

	if (ac < 2 || strcmp(av[1], "2") == 0)
	{
		printf("------------------------------\n");
		printf("\nex02\n");
		if (ac == 4)
		{
			a = atoi(av[2]);
			b = atoi(av[3]);
			printf("- Test 1 :\n   a and b value before ft_swap : a = %d, b = %d\n", a, b);
			ft_swap(&a, &b);
			printf("   a and b value after ft_swap : a = %d, b = %d\n\n", a, b);
		}
		else
		{
			a = 50;
			b = 47;
			printf("- Test 1 :\n   a and b value before ft_swap : a = %d, b = %d\n", a, b);
			ft_swap(&a, &b);
			printf("   a and b value after ft_swap : a = %d, b = %d\n\n", a, b);
			a = -10;
			b = -7;
			printf("- Test 2 :\n   a and b value before ft_swap : a = %d, b = %d\n", a, b);
			ft_swap(&a, &b);
			printf("   a and b value after ft_swap : a = %d, b = %d\n\n", a, b);
			a = 12;
			b = -3;
			printf("- Test 3 :\n   a and b value before ft_swap : a = %d, b = %d\n", a, b);
			ft_swap(&a, &b);
			printf("   a and b value after ft_swap : a = %d, b = %d\n\n", a, b);
			a = 5024242;
			b = -42447;
			printf("- Test 4 :\n   a and b value before ft_swap : a = %d, b = %d\n", a, b);
			ft_swap(&a, &b);
			printf("   a and b value after ft_swap : a = %d, b = %d\n\n", a, b);
		}
		printf("------------------------------\n");
	}

	if (ac < 2 || strcmp(av[1], "3") == 0)
	{
		printf("------------------------------\n");
		printf("\nex03\n");
		if (ac >= 4)
		{
			a = atoi(av[2]);
			b = atoi(av[3]);
			if (ac == 6)
			{
				div = atoi(av[4]);;
				mod = atoi(av[5]);
			}
			printf("- Test 1 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
		}
		else
		{
			a = 50;
			b = 47;
			div = 0;
			mod = 0;
			printf("- Test 1 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = -10;
			b = -7;
			div = 0;
			mod = 0;
			printf("- Test 2 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = 12;
			b = -3;
			div = 0;
			mod = 0;
			printf("- Test 3 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = 5024242;
			b = -42447;
			div = 0;
			mod = 0;
			printf("- Test 4 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = -3;
			b = 0;
			div = 0;
			mod = 0;
			printf("- Test 4 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = 0;
			b = -3;
			div = 0;
			mod = 0;
			printf("- Test 5 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
			a = 0;
			b = 0;
			div = 0;
			mod = 0;
			printf("- Test 6 :\n   a, b, div and mod value before void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, b, &div, &mod);
			printf("   a, b, div and mod value after void	ft_div_mod : a = %d, b = %d, div = %d, mod = %d\n\n", a, b, div, mod);
		}
		printf("------------------------------\n");	
	}

	if (ac < 2 || strcmp(av[1], "4") == 0)
	{
		printf("------------------------------\n");
		printf("\nex04\n");
		if (ac == 4)
		{
			a = atoi(av[2]);
			b = atoi(av[3]);
			printf("- Test 1 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
		}
		else
		{
			a = 50;
			b = 47;
			printf("- Test 1 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = -10;
			b = -7;
			printf("- Test 2 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = 12;
			b = -3;
			printf("- Test 3 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = 5024242;
			b = -42447;
			printf("- Test 4 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = -3;
			b = 0;
			printf("- Test 5 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = 0;
			b = -3;
			printf("- Test 6 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
			a = 0;
			b = 0;
			printf("- Test 7 :\n   a and b value before ft_ultimate_div_mod : a = %d, b = %d\n", a, b);
			ft_ultimate_div_mod(&a, &b);
			printf("   a and b value after ft_ultimate_div_mod : a = %d, b = %d\n\n", a, b);
		}
		printf("------------------------------\n");	
	}

	if (ac < 2 || strcmp(av[1], "5") == 0)
	{
		printf("------------------------------\n");
		printf("\nex05\n");
		if (ac == 3)
		{
			printf("- Test 1 :\n   string to print : s = ->%s<-\nstring printed : s = ->", av[2]);
			fflush(stdout);
			ft_putstr(av[2]);
			printf("<-\n\n");
		}
		else
		{
			char str1[5] = "hello";
			printf("- Test 1 :\n   string to print : s = ->%s<-\nstring printed : s = ->", str1);
			fflush(stdout);
			ft_putstr(str1);
			printf("<-\n\n");
			char str2[] = "" ;
			printf("- Test 2 :\n   string to print : s = ->%s<-\nstring printed : s = ->", str2);
			fflush(stdout);
			ft_putstr(str2);
			printf("<-\n\n");
			char str3[5] = " " ;
			printf("- Test 3 :\n   string to print : s = ->%s<-\nstring printed : s = ->", str3);
			fflush(stdout);
			ft_putstr(str3);
			printf("<-\n\n");
			char *str4 = NULL;
			printf("- Test 4 :\n   string to print : s = ->%s<-\nstring printed : s = ->", str4);
			fflush(stdout);
			ft_putstr(NULL);
			printf("<-\n\n");
			char str5[1] = "\0";
			printf("- Test 5 :\n   string to print : s = ->%s<-\nstring printed : s = ->", str5);
			fflush(stdout);
			ft_putstr(str5);
			printf("<-\n\n");
			printf("- Test 5 :\n   string to print : s = ->%s<-\nstring printed : s = ->", "\0");
			fflush(stdout);
			ft_putstr("\0");
			printf("<-\n\n");
		}
		printf("------------------------------\n");
	}

	if (ac < 2 || strcmp(av[1], "6") == 0)
	{
		printf("------------------------------\n");
		printf("\nex06\n");
		if (ac == 3)
		{
			printf("- Test 1 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",av[2] ,strlen(av[2]));
			fflush(stdout);
			printf("%d\n\n", ft_strlen(av[2]));
		}
		else
		{
			char strl1[5] = "hello";
			printf("- Test 1 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",strl1 ,strlen(strl1));
			fflush(stdout);
			printf("%d\n\n", ft_strlen(strl1));
			char strl2[] = "" ;
			printf("- Test 2 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",strl2 ,strlen(strl2));
			fflush(stdout);
			printf("%d\n\n", ft_strlen(strl2));
			char strl3[5] = " " ;
			printf("- Test 3 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",strl3 ,strlen(strl3));
			fflush(stdout);
			printf("%d\n\n", ft_strlen(strl3));
			/*
			char *strl4 = NULL;
			printf("- Test 4 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",NULL ,strlen(NULL));
			fflush(stdout);
			ft_strlen(NULL);
			printf("%d\n\n", ft_strlen(strl4));
			*/
			char strl5[1] = "\0";
			printf("- Test 5 :\n   string : s = ->%s<-\n   len = %lu\n   res = ",strl5 ,strlen(strl5));
			fflush(stdout);
			printf("%d\n\n", ft_strlen(strl5));
			printf("- Test 5 :\n   string : s = ->%s<-\n   len = %lu\n   res = ","\0" ,strlen("\0"));
			fflush(stdout);
			ft_strlen("\0");
			printf("%d\n\n", ft_strlen("\0"));
			char *strl4 = NULL;
			printf("- Test 4 :\n   string : s = ->%s<-\n   res = ",strl4);
			fflush(stdout);
			ft_strlen(NULL);
			printf("%d\n\n", ft_strlen(strl4));
		}
		printf("------------------------------\n");
	}

	if (ac < 2 || strcmp(av[1], "7") == 0)
	{
		int test1[] = {3, 2, 8, 1, 6, 7, 9, 5, 4}; // random order
		int test2[] = {1, 2, 3, 4, 5};             // already sorted
		int test3[] = {5, 4, 3, 2, 1};             // reverse order
		int test4[] = {1, 2, 2, 3, 3, 1};          // with duplicates
		int test5[] = {-3, -1, -7, 2, 0, 4};       // with negative numbers
		int test6[] = {42};                       // single element
		int test7[] = {};                         // empty array

		int sizes[] = {9, 5, 5, 6, 6, 1, 0};

		int *tests[] = {test1, test2, test3, test4, test5, test6, test7};
		const char *labels[] = {
			"Random Order", "Sorted", "Reversed", "Duplicates", "Negatives", "Single", "Empty"
		};


		for (int i = 0; i < 7; i++)
		{
			printf("Test %d: %s\nBefore: \n", i + 1, labels[i]);
			print_tab(tests[i], sizes[i]);

			ft_rev_int_tab(tests[i], sizes[i]);

			printf("After:  \n");
			print_tab(tests[i], sizes[i]);
			printf("--------------------------\n");
		}
	}

	if (ac < 2 || strcmp(av[1], "8") == 0)
	{
		int test1[] = {3, 2, 8, 1, 6, 7, 9, 5, 4}; // random order
		int test2[] = {1, 2, 3, 4, 5};             // already sorted
		int test3[] = {5, 4, 3, 2, 1};             // reverse order
		int test4[] = {1, 2, 2, 3, 3, 1};          // with duplicates
		int test5[] = {-3, -1, -7, 2, 0, 4};       // with negative numbers
		int test6[] = {42};                       // single element
		int test7[] = {};                         // empty array

		int sizes[] = {9, 5, 5, 6, 6, 1, 0};

		int *tests[] = {test1, test2, test3, test4, test5, test6, test7};
		const char *labels[] = {
			"Random Order", "Sorted", "Reversed", "Duplicates", "Negatives", "Single", "Empty"
		};


		for (int i = 0; i < 7; i++)
		{
			printf("Test %d: %s\nBefore: \n", i + 1, labels[i]);
			print_tab(tests[i], sizes[i]);

			ft_sort_int_tab(tests[i], sizes[i]);

			printf("After:  \n");
			print_tab(tests[i], sizes[i]);
			printf("--------------------------\n");
		}
	}

    return (1);
}