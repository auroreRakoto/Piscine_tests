/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:30:23 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 09:30:23 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*cur;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!*begin_list || (*cmp)(data, (*begin_list)->data) <= 0)
	{
		new->next = *begin_list;
		*begin_list = new;
		return ;
	}
	cur = *begin_list;
	while (cur->next && (*cmp)(data, cur->next->data) > 0)
		cur = cur->next;
	new->next = cur->next;
	cur->next = new;
}
