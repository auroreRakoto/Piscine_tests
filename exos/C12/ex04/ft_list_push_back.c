/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 08:25:29 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/20 08:25:30 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*cur;

	if (!begin_list)
		return ;
	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	cur = *begin_list;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}
