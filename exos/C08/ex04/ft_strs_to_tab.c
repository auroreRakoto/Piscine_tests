/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:00:24 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/14 10:01:12 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	if (!src)
		return (0);
	while (src[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*res;

	if (!src)
		return (0);
	len = 0;
	while (src[len])
		len++;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_free_and_exit(t_stock_str *res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i].str)
		{
			if (res[i].copy)
				free(res[i].copy);
			i++;
		}
		free(res);
	}
	return (0);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	i = 0;
	res = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!res)
		return (0);
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (!res[i].copy)
		{
			ft_free_and_exit(res);
			return (NULL);
		}
		i++;
	}
	res[i].str = 0;
	return (res);
}
