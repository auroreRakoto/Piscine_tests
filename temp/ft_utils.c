/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:20:42 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/17 10:20:44 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

int	ft_get_size(char **input)
{
	int	size;

	size = 0;
	while (input[size])
		size++;
	return (size / 4);
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int n)
{
    char c;
    if (n > 9) ft_putnbr(n / 10);
    c = (char)('0' + (n % 10));
    ft_putchar(c);
}

int     ft_atoi_safe(const char *s)
{
    int n;

    n = 0;
    if (!s || !*s)
        return (-1);
    while (*s >= '0' && *s <= '9')
    {
        n = n * 10 + (*s - '0');
        s++;
    }
    if (*s != '\0')
        return (-1);
    return (n);
}

void	print_grid(int **g, int n)
{
	int r, c;

	r = 0;
	while (r < n)
	{
		c = 0;
		while (c < n)
		{
			ft_putnbr(g[r][c]);
			if (c < n - 1)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}
