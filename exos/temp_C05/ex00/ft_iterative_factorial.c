int	ft_iteractive_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = nb;
	while (i > 1)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}
