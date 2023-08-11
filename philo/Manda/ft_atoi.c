/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 00:04:58 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 11:13:15 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	checksign(char *str, int *sign, int i)
{
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			(*sign) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	prv;
	long int		res;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	i = checksign((char *)str, &sign, i);
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		prv = res;
		res = res * 10 + str[i] - '0';
		if (prv != res / 10 && sign == 1)
			return (-1);
		else if (prv != res / 10 && sign == -1)
			return (0);
		i++;
	}
	if (!str[i])
		return ((int)(sign * res));
	return (-1);
}
