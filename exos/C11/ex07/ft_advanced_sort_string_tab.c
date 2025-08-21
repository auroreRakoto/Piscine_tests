/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:23:15 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/18 14:23:17 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_verif_sorted(char **tab, int (*cmp)(char *, char *s))
{
	int	i;

	i = 1;
	while (tab[i])
	{
		if ((*cmp)(tab[i - 1], tab[i]) > 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((*cmp)(tab[i - 1], tab[i]) > 0)
			{
				temp = tab[i - 1];
				tab[i - 1] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		if (ft_verif_sorted(tab, (*cmp)))
			sorted = 1;
	}
}

/*
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


int	main(void)
{
	char *tab[] = {
		"banana",
		"apple",
		"pear",
		"orange",
		"grape",
		NULL
	};
	int i;

	printf("Avant tri :\n");
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}

	ft_advanced_sort_string_tab(tab, &ft_strcmp);

	printf("\nApres tri :\n");
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}
*/