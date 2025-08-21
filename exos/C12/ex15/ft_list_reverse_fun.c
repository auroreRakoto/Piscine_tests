/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:30:32 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 09:30:32 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*left;
	t_list	*right;
	t_list	*end;
	void	*tmp;

	if (!begin_list || !begin_list->next)
		return ;
	left = begin_list;
	end = NULL;
	while (left && left->next && left != end)
	{
		right = begin_list;
		while (right->next != end)
			right = right->next;
		if (left == right || left->next == end)
			break ;
		tmp = left->data;
		left->data = right->data;
		right->data = tmp;
		left = left->next;
		end = right;
	}
}
