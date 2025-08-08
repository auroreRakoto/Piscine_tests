/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:28:19 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/08 09:28:21 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_verif_base2(void)
{
	return (1);
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

int	ft_is_space(char c)
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

	i = 0;
	n = 1;
	res = 0;
	if (!ft_verif_base2())
		return (0);
	while (str[i] && ft_is_space(str[i]))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			n = -n;
		i++;
	}
	while (str[i] && ft_is_in_base(str[i], base) != -1)
	{
		res = (res * 10) + ft_is_in_base(str[i], base);
		i++;
	}
	return (res * n);
}
