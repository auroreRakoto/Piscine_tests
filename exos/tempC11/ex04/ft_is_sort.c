int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	dir;

	i = 1;
	dir = 1;
	while (i < length && (*f)(i - 1, i) != 0)
		i++;
	dir = dir * (*f)(i - 1, i);
	while (i < length)
	{
		if (!(dir < 0 && (*f)(i - 1, i) <=0) && !(dir > 0 && (*f)(i - 1, i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
