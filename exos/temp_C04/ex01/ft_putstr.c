void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}