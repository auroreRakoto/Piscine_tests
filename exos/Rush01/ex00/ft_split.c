/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:06:49 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/13 16:31:19 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_malloc_split(char *str, int nb_words);

int	ft_is_in(char c, char *sep)
{
	int	j;

	j = 0;
	while (sep[j])
	{
		if (c == sep[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_len_word(char *strs, char *sep)
{
	int	len;

	len = 0;
	while (strs[len])
	{
		if (ft_is_in(strs[len], sep))
			return (len);
		len++;
	}
	return (len);
}

int	ft_count_words(char *strs, char *sep)
{
	int	i;
	int	words;

	i = 0;
	words = 1;
	if (!strs || !sep)
		return (-1);
	while (strs[i] && ft_is_in(strs[i], sep))
		i++;
	if (!strs[i])
		return (0);
	while (strs[i])
	{
		if (ft_is_in(strs[i], sep))
		{
			while (strs[i] && ft_is_in(strs[i], sep))
				i++;
			if (strs[i])
				words++;
		}
		i++;
	}
	return (words);
}

char	**ft_splitter(char **res, char *strs, char *sep, int nb_words)
{
	int	i;
	int	j;
	int	k;
	int	len_word;

	i = 0;
	j = 0;
	while (strs[i] && ft_is_in(strs[i], sep))
		i++;
	while (j < nb_words)
	{
		while (strs[i] && ft_is_in(strs[i], sep))
			i++;
		k = -1;
		len_word = ft_len_word(&strs[i], sep);
		while (++k < len_word)
		{
			res[j][k] = strs[i];
			i++;
		}
		res[j][k] = '\0';
		j++;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		nb_words;

	nb_words = ft_count_words(str, charset);
	if (nb_words == -1)
		return (0);
	res = ft_malloc_split(str, nb_words);
	if (!res)
		return (0);
	res = ft_splitter(res, str, charset, nb_words);
	return (res);
}
