int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			res++;
		i++;
	}
	return (res);
}
