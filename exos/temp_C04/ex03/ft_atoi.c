/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurrakot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 09:28:03 by aurrakot          #+#    #+#             */
/*   Updated: 2025/08/08 09:28:05 by aurrakot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_preffix(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || \
		str[i] == '\n' || str[i] == '\r' || \
		str[i] == '\v' || str[i] == '\f'))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	long int	i;
	long int	n;
	long int	res;

	n = 1;
	res = 0;
	i = check_preffix(str);
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	res = n * res;
	return (res);
}
