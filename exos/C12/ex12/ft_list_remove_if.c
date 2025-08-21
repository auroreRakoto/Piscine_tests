/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:31:34 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 09:31:35 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list,
	void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	if (!begin_list || !*begin_list)
		return ;
	cur = *begin_list;
	if ((*cmp)(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		if (free_fct)
			free_fct(cur->data);
		free(cur);
		ft_list_remove_if(begin_list, data_ref, (*cmp), free_fct);
	}
	else
	{
		tmp = cur->next;
		ft_list_remove_if(&tmp, data_ref, (*cmp), free_fct);
		cur->next = tmp;
	}
}
