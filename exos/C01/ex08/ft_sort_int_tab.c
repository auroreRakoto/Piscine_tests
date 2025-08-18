/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:19:18 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/05 16:19:19 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_sort(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	pivot;
	int	green;
	int	orange;

	if (size <= 1)
		return ;
	pivot = tab[size - 1];
	orange = 0;
	green = 0;
	while (green < size)
	{
		if (tab[green] <= pivot)
		{
			if (orange < green)
			{
				ft_swap_sort(tab + orange, tab + green);
			}
			orange++;
		}
		green++;
	}
	ft_sort_int_tab(tab, orange - 1);
	ft_sort_int_tab(tab + orange, size - orange);
}
