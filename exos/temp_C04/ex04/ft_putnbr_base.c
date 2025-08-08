/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:28:10 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/08 09:28:11 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_len1(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_str_len1(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			len;
	long long	n;

	if (!base)
		return ;
	len = ft_str_len1(base);
	if (!ft_verif_base(base))
		return ;
	n = (long long)nbr;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= len)
	{
		ft_putnbr_base(n / len, base);
		write(1, &base[(n % len)], 1);
	}
	else
	{
		write(1, &base[n], 1);
	}
}
