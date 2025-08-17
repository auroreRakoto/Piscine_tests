/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <you@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 12:00:00 by you               #+#    #+#             */
/*   Updated: 2025/08/17 12:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void        ft_putchar(char c);
void        ft_putnbr(int n);

void    print_solution(char **grid)
{
    int r;
    int c;

    r = 0;
    while (r < N)
    {
        c = 0;
        while (c < N)
        {
            ft_putnbr(grid[r][c]);
            if (c < N - 1)
                write(1, " ", 1);
            c++;
        }
        write(1, "\n", 1);
        r++;
    }
}

