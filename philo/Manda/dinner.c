/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 01:43:38 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_my_usleep(unsigned long t)
{
	unsigned long	period;

	period = time_now();
	while ((time_now() - period) < t)
		usleep(100);
	return ;
}

void	*pattern(void *temp)
{
	t_philo	*philo;

	philo = (t_philo *)temp;
	if ((philo->id % 2) != 0)
		usleep(400);
	pthread_mutex_lock(philo->protect);
	philo->last_meal = time_now();
	pthread_mutex_unlock(philo->protect);
	while (1)
	{
		lock_forks(philo);
		eating(philo);
		pthread_mutex_lock(philo->protect);
		philo->last_meal = time_now();
		pthread_mutex_unlock(philo->protect);
		ft_my_usleep(philo->table->time_to_eat);
		unlock_forks(philo);
		pthread_mutex_lock(philo->protect);
		philo->n_of_meals_per_philo++;
		pthread_mutex_unlock(philo->protect);
		sleeping(philo);
		ft_my_usleep(philo->table->time_to_sleep);
		thinking(philo);
	}
	return (NULL);
}

void	start_dinner(t_philo *filo, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_create(&filo->thread, NULL, &pattern, (void *)filo);
		filo = filo->next;
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_detach(filo->thread);
		filo = filo->next;
		i++;
	}
	check_death(filo);
}
