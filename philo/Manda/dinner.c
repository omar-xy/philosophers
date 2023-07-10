/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/10 11:01:24 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

unsigned long time_now(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_my_usleep(unsigned long t)
{
	unsigned long	period;

	period = time_now();
	while((time_now() - period) < t)
		usleep(100);
}

void	*pattern(void *temp)
{
	t_philo *philo;
	
	philo = (t_philo *)temp;
	if (!(philo->id % 2))
		usleep(500);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		printf("philo %d as taken a fork 1\n",philo->id);
		pthread_mutex_lock(&philo->next->fork);
		printf("philo %d as taken a fork 2\n", philo->id);
		printf("philo %d is eating\n", philo->id);
		philo->last_meal = time_now() - philo->table->time_begin;
		ft_my_usleep(philo->table->time_to_eat);
		if (time_now() - philo->last_meal < philo->table->time_to_die)
		{
			pthread_mutex_lock(&philo->table->write);
			printf("the zb die %d\n", philo->id);
			pthread_mutex_lock(&philo->table->death);
			philo->table->died = 1;
			pthread_mutex_unlock(&philo->table->death);
		}
		pthread_mutex_unlock(&philo->fork);
		// pthread_mutex_unlock(&philo->next->fork);
		pthread_mutex_unlock(&philo->next->fork);
		// pthread_mutex_unlock(&philo->next->fork);
		printf("philo %d is sleeping\n", philo->id);
		ft_my_usleep(philo->table->time_to_sleep);
	}
	return (philo);
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
	die_philo(filo->table);
	i = 0;
	while (i < n)
	{
		pthread_join(filo->thread, NULL);
		filo = filo->next;
		i++;
	}
	printf("%d\n", filo->id);
}