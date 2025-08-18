/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:49:58 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/11 14:56:33 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int	len;
	char	*res;

	if (!src)
		return (0);
	len = 0;
	while (src[len])
		len++;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	return (res);
}
