/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:33:53 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 17:18:58 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	lock_forks(t_philo *philo)
{
	sem_wait(philo->table->fork);
	printf("%lu %d has taken a fork\n", \
			time_now() - philo->table->time_begin, philo->id);
	if (philo->table->nbr_of_philo == 1)
	{
		usleep(philo->table->time_to_die * 1000);
		printf("%ld %d died \n", \
				time_now() - (philo->table->time_begin), philo->id);
		sem_post(philo->table->death);
		sem_post(philo->table->nb_of_meals);
		exit(0);
	}
	sem_wait(philo->table->fork);
	printf("%lu %d has taken a fork\n", \
			time_now() - philo->table->time_begin, philo->id);
}

void	unlock_forks(t_philo *philo)
{
	sem_post(philo->table->fork);
	sem_post(philo->table->fork);
}

void	eating(t_philo *philo)
{
	printf("%lu %d is eating\n", \
			time_now() - philo->table->time_begin, philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", \
			time_now() - philo->table->time_begin, philo->id);
}

void	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", \
			time_now() - philo->table->time_begin, philo->id);
}
