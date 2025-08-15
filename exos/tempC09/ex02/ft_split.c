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
	int		i;
	int		len;
	int		j;

	nb_words = ft_count_words(str, charset);
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!res || nb_words == -1)
		return (0);
	i = -1;
	j = 0;
	while (++i < nb_words)
	{
		while (ft_is_in(str[j], charset))
			j++;
		len = ft_len_word(&str[j], charset);
		j += len;
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!res[i])
			return (0);
	}
	res = ft_splitter(res, str, charset, nb_words);
	return (res);
}
/*
void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		printf("strs[%d] = %s\n", i, strs[i]);
		i++;
	}
}

int	main()
{
	char	**res;

	res = ft_split("a,b,c", ",");
	ft_print_strs(res);
	res = ft_split(",,a,,,b,", ",");
	ft_print_strs(res);
	ft_split("hello world", " ");
}*/
