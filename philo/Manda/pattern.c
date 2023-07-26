/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:27:07 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/25 01:30:09 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	pthread_mutex_lock(philo->write);
	printf("%lu %d has taken a fork 1\n", time_now() - philo->table->time_begin, philo->id);
	pthread_mutex_unlock(philo->write);
	pthread_mutex_lock(&philo->next->fork);
	pthread_mutex_lock(philo->write);
	printf("%lu %d has taken a fork 2\n", time_now() - philo->table->time_begin, philo->id);
	pthread_mutex_unlock(philo->write);
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->next->fork);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%lu %d is eating\n", time_now() - philo->table->time_begin, philo->id);
	pthread_mutex_unlock(philo->write);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%lu %d is sleeping\n", time_now() - philo->table->time_begin,  philo->id);
	pthread_mutex_unlock(philo->write);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->write);
	printf("%lu %d is thinking\n", time_now() - philo->table->time_begin, philo->id);
	pthread_mutex_unlock(philo->write);
}

void	check_death(t_philo *filo)
{
	while (filo)
	{
		usleep(1000);
		if (time_now() - filo->last_meal > filo->table->time_to_die)
		{
			pthread_mutex_lock(filo->write);
			printf("%ld %d died \n",time_now() - (filo->table->time_begin), filo->id);
			pthread_mutex_lock(filo->death);
			filo->table->died = 1;
			pthread_mutex_unlock(filo->death);
		}
		if (filo->table->died || filo->table->nbr_of_philo <= 0)
			return ;
		filo = filo->next;
	}
	destroy_data(filo);
}
