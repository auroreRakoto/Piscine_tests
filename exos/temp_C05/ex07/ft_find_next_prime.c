#include <limits.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 3;
	if (nb < 2)
		return (0);
	if (i == 2)
		return (1);
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (nb % 2);
}

int	ft_find_next_print(int nb)
{
	int	i;

	i = nb;
	if (nb <= 2)
		return (2);
	if (i % 2 == 0)
		i++;
	while (i <= INT_MAX)
	{
		if (ft_is_prime(i))
			return (i);
		i += 2;
	}

}
