/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:01:49 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 12:02:15 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_merge(t_list **begin_list1, \
		t_list *begin_list2, int (*cmp)())
{
	t_list	**pp;
	t_list	*tmp;

	if (!begin_list1)
		return ;
	pp = begin_list1;
	while (*pp && begin_list2)
	{
		if ((*cmp)((*pp)->data, begin_list2->data) <= 0)
			pp = &(*pp)->next;
		else
		{
			tmp = begin_list2->next;
			begin_list2->next = *pp;
			*pp = begin_list2;
			begin_list2 = tmp;
			pp = &(*pp)->next;
		}
	}
	if (!*pp)
		*pp = begin_list2;
}
