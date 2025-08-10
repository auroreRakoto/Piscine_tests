#include <stdio.h>

char *checking(char *res)
{
	int	index;

	index = res[10] - 48;
	res[10] += 1;
	if (index == 3)
		res = checking(res);
	printf("sefe\n");
	printf("index : %d, res : %s\n", index, res);
	//while (index < 1)
	//{
		//printf("index : %d, res : %s\n", index, res);
	//	res = checking(res);
	//}
	return (res);
}


int	ft_ten_queens_puzzle(void)
{
	int		i;
	char	res[11];

    i = 0;
	res = "aaaaaaaaaa0"
	/*while (i < 10)
	{
		res[0] = i + 48;
		i++;
	}*/
	res[10] = '0';
	checking(res);
}

int	main()
{
	ft_ten_queens_puzzle();
}