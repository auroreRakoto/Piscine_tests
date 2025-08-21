/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 09:44:40 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/18 11:43:40 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	dir;
	int	cmp;

	if (length < 2)
		return (1);
	i = 1;
	while (i < length && (*f)(tab[i - 1], tab[i]) == 0)
		i++;
	if (i == length)
		return (1);
	dir = (*f)(tab[i - 1], tab[i]);
	while (i < length)
	{
		cmp = (*f)(tab[i - 1], tab[i]);
		if ((dir < 0 && cmp > 0) || (dir > 0 && cmp < 0))
			return (0);
		i++;
	}
	return (1);
}
