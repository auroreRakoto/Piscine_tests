/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 08:33:27 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/13 16:01:37 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_verif_base(char *base);
char	*ft_putnbr_base(int nbr, char *base, char *res, int index);
int		ft_is_in_base(char c, char *base);
int		ft_str_len1(char *base);

int	ft_is_space1(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}

int	ft_convert(char c, char *base)
{
	int	len;
	int	res;
	int	index;

	len = 0;
	while (base[len])
		len++;
	index = ft_is_in_base(c, base);
	res = index;
	while (index > 0)
	{
		res += index * len;
		index--;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	res;
	int	len_base;

	i = 0;
	n = 1;
	res = 0;
	len_base = 0;
	while (base[len_base])
		len_base++;
	while (str[i] && ft_is_space1(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	--i;
	while (str[++i] && ft_is_in_base(str[i], base) != -1)
		res = (res * len_base) + ft_is_in_base(str[i], base);
	return (res * n);
}

int	ft_find_len(int nbr, char *base)
{
	int			len;
	int			index;

	len = ft_str_len1(base);
	index = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		index++;
	}
	while (nbr >= len)
	{
		nbr = nbr / len;
		index++;
	}
	return (index);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		temp_int;
	char	*res;
	int		len;

	if (!nbr || !base_from || !base_to || \
			!ft_verif_base(base_to) || !ft_verif_base(base_from))
		return (0);
	temp_int = ft_atoi_base(nbr, base_from);
	res = malloc(sizeof(char) * 12);
	if (!res)
		return (0);
	len = ft_find_len(temp_int, base_to);
	res = ft_putnbr_base(temp_int, base_to, res, len);
	if (!res)
		return (0);
	return (res);
}

/*
#include <stdio.h>
int main()
{
	//{ .nbr = "42",.base_from = "0123456789",.base_to = "01" };
	printf("%s\n", ft_convert_base("--04302", "9876543210", "456789"));
}
*/