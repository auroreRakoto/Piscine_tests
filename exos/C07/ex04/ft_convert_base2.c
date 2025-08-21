/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 15:58:54 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/13 15:59:21 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_len1(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_verif_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
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

char	*ft_putnbr_base(int nbr, char *base, char *res, int index)
{
	int			len;
	long long	n;

	len = ft_str_len1(base);
	n = (long long)nbr;
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n >= len)
	{
		res[index] = base[(n % len)];
		ft_putnbr_base(n / len, base, res, index - 1);
	}
	else
	{
		res[index] = base[n];
	}
	return (res);
}
