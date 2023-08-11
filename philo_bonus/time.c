/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:24:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 11:44:40 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_my_usleep(unsigned long t)
{
	unsigned long	period;
	int				i;

	i = 0;
	period = time_now();
	while ((time_now() - period) < t)
		usleep(1000);
	return ;
}
