/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 03:33:53 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/25 03:50:41 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	lock_forks(t_philo *philo) 
{
	sem_wait(philo->table->fork);
	sem_wait(philo->table->fork);
	printf("%lu %d has taken a fork 1\n", time_now() - philo->table->time_begin, philo->id);
	printf("%lu %d has taken a fork 2\n", time_now() - philo->table->time_begin, philo->id);
}

void	unlock_forks(t_philo *philo)
{
	sem_post(philo->table->fork);
	sem_post(philo->table->fork);
}

void	eating(t_philo *philo)
{
	printf("%lu %d is eating\n", time_now() - philo->table->time_begin, philo->id);
}

void	sleeping(t_philo *philo)
{
	printf("%lu %d is sleeping\n", time_now() - philo->table->time_begin,  philo->id);
}

void	thinking(t_philo *philo)
{
	printf("%lu %d is thinking\n", time_now() - philo->table->time_begin, philo->id);
}
