/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:24:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/25 06:22:56 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long time_now(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_my_usleep(unsigned long t, t_philo *filo)
{
	unsigned long	period;

	period = time_now();
	while ((time_now() - period) < t)
    {
        if (time_now() - filo->last_meal > filo->table->time_to_die)
		{
			printf("%ld %d died \n",time_now() - (filo->table->time_begin), filo->id);
			sem_post(filo->table->death);
            exit(0);
		} 
	    usleep(100);
    }
	return ;
}