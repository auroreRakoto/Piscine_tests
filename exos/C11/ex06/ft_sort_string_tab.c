/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 11:34:29 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/18 11:43:57 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	ft_verif_sorted(char **tab)
{
	int	i;

	i = 1;
	while (tab[i])
	{
		if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*temp;
	int		sorted;

	if (!tab || !tab[0] || !tab[1])
		return ;
	sorted = 0;
	while (!sorted)
	{
		i = 1;
		while (tab[i])
		{
			if (ft_strcmp(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		if (ft_verif_sorted(tab))
			sorted = 1;
	}
}

/*
#include <stdio.h>

int	main(void)
{
	char *tab[] = {
		"banana",
		"apple",
		"pear",
		"orange",
		"grape",
		0
	};
	int i;

	ft_sort_string_tab(tab);
	i = 0;
	while (tab[i])
	{
		printf("str : %s", tab[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
*/