/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:00:54 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/12 10:52:22 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_exit_error(int **range)
{
	if (range)
		*range = NULL;
	return (0);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (!range)
		return (-1);
	*range = malloc(sizeof(int) * (max - min));
	if (!*range || min >= max)
		return (ft_exit_error(range));
	i = min;
	while (i < max)
	{
		(*range)[i - min] = i;
		i++;
	}
	return (max - min);
}

/*
int	main()
{
	int	*range;

	//range = (int **)malloc(sizeof(int *));
	ft_ultimate_range(&range, 0, 5);
}*/
