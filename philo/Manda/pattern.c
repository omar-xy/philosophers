/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 09:27:07 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/11 20:50:27 by otaraki          ###   ########.fr       */
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
