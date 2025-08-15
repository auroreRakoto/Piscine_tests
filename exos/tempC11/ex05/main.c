int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	if (!ft_is_op(av[2]))
		return (write(1, "0\n", 2));

	return (0);
}
