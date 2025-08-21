/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:30:50 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 09:30:51 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*end;
	t_list	*cur;
	void	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	end = NULL;
	while ((*begin_list)->next != end)
	{
		cur = *begin_list;
		while (cur->next != end)
		{
			if ((*cmp)(cur->data, cur->next->data) > 0)
			{
				tmp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = tmp;
			}
			cur = cur->next;
		}
		end = cur;
	}
}
