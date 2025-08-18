/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:14:51 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/10 10:44:09 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	max;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	i = 2;
	max = nb;
	while (i < max && max != 2)
	{
		nb = nb * i;
		i++;
	}
	return (nb);
}
