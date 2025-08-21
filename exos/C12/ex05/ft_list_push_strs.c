/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 08:25:36 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 08:25:37 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*start;
	t_list	*new;
	int		i;

	if (!strs || size < 1)
		return (NULL);
	start = NULL;
	i = 0;
	while (i < size)
	{
		new = ft_create_elem(strs[i]);
		new->next = start;
		start = new;
		i++;
	}
	return (start);
}
