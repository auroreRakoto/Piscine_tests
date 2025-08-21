/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 15:08:03 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 15:08:04 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_is_in(char c, char *sep);
int	ft_len_word(char *strs, char *sep);

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}

char	**ft_malloc_split(char *str, int nb_words)
{
	int		i;
	int		j;
	int		len;
	char	**res;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!res || nb_words == -1)
		return (0);
	while (i < nb_words)
	{
		while (ft_is_in(str[j], " "))
			j++;
		len = ft_len_word(&str[j], " ");
		j += len;
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!res[i])
		{
			ft_free_split(res);
			return (NULL);
		}
		i++;
	}
	return (res);
}

void	ft_free_grid(int **g, int n)
{
	int	i;

	i = 0;
	if (!g)
		return ;
	while (i < n)
		free(g[i++]);
	free(g);
}

void	ft_free_pos(int **pos)
{
	int	i;

	if (!pos)
		return ;
	i = 0;
	while (i < 4)
	{
		free(pos[i]);
		i++;
	}
	free(pos);
}

void	ft_free_all(char **inputs, int **grid, int size, int **pos)
{
	if (inputs)
	{
		write(1, "Error\n", 6);
		ft_free_split(inputs);
	}
	if (grid)
		ft_free_grid(grid, size);
	if (pos)
		ft_free_pos(pos);
}
