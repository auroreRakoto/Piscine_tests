/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:33:53 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/08 09:33:55 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *src)
{
	int	size;

	size = 0;
	while (src[size])
		size++;
	return (size);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size < len_dest + 1)
		return (len_src + size);
	while (src[i] && (len_dest + i + 1) < size)
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = 0;
	return (len_dest + len_src);
}
