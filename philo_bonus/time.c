/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:24:42 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/26 01:21:56 by otaraki          ###   ########.fr       */
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
	int				i;

	i = 0;
	period = time_now();
	while ((time_now() - period) < t)
    {
	    usleep(1000);
        if (time_now() - filo->last_meal > filo->table->time_to_die)
		{
			sem_wait(filo->table->write);
			printf("%ld %d died \n", time_now() - (filo->table->time_begin), filo->id);
			sem_post(filo->table->death);
			if (filo->table->nbr_meals != -1)
			{
				while (i < filo->table->nbr_of_philo)
				{
					sem_post(filo->table->nb_of_meals);
					i++;
				}
			}
            exit(0);
		} 
    }
	return ;
}