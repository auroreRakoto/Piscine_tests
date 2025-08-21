/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 10:55:16 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/16 10:10:59 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_join(char *res, char **strs, char *sep, int size)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < size && strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			res[index] = strs[i][j];
			index++;
			j++;
		}
		if (i != size - 1 && sep)
		{
			j = -1;
			while (sep[++j])
				res[index++] = sep[j];
		}
		i++;
	}
	res[index] = 0;
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;

	if (size == 0)
	{
		res = malloc(1);
		if (res)
			res[0] = '\0';
		return (res);
	}
	i = -1;
	len = 0;
	while (strs[++i] && i < size)
		len += ft_strlen(strs[i]);
	if (i > 0)
		len += ft_strlen(sep) * (i - 1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	return (ft_join(res, strs, sep, size));
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("join : -->%s<--\n", ft_strjoin(0, &av[2], av[1]));
}*/
