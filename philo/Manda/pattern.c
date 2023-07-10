/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:27:07 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/10 10:08:00 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void eat_pattern(int n)
{
    printf("philo %d is eating\n", n);
}

void die_philo(t_table *fifo)
{
    int i;

    i = 0;
    while (i < fifo->nbr_of_philo)
	{
		if (time_now() - fifo->philos->last_meal < fifo->time_to_die)
		{
			pthread_mutex_lock(&fifo->death);
			printf("the zb die %d\n", fifo->philos->id);
			pthread_mutex_unlock(&fifo->death);
		}
	}
}