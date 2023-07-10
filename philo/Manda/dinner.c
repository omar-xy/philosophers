/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/10 15:49:11 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

unsigned long time_now(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_my_usleep(unsigned long t, t_philo *philo)
{
	unsigned long	period;

	period = time_now();
	while((time_now() - period) < t)
	{
		if (time_now() - philo->last_meal > philo->table->time_to_die)
		{
			pthread_mutex_lock(philo->write);
			printf("%ld %d die \n",time_now() - philo->table->time_begin, philo->id);
			pthread_mutex_lock(philo->death);
			philo->table->died = 1;
			pthread_mutex_unlock(philo->death);
		}
		usleep(100);
	}
}

void	*pattern(void *temp)
{
	t_philo *philo;
	
	philo = (t_philo *)temp;
	if ((philo->id % 2) == 0)
		usleep(400);
	philo->last_meal = time_now();
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		pthread_mutex_lock(philo->write);
		printf("%lu %d has taken a fork 1\n", time_now() - philo->table->time_begin, philo->id);
		pthread_mutex_unlock(philo->write);//first fork
		pthread_mutex_lock(&philo->next->fork);
		pthread_mutex_lock(philo->write);
		printf("%lu %d has taken a fork 2\n", time_now() - philo->table->time_begin, philo->id);
		pthread_mutex_unlock(philo->write);// second fork
		eating(philo);
		ft_my_usleep(philo->table->time_to_eat, philo);
		philo->last_meal = time_now();
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		sleeping(philo);
		ft_my_usleep(philo->table->time_to_sleep, philo);
		thinking(philo);
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
	i = 0;
	while (i < n)
	{
		pthread_detach(filo->thread);
		filo = filo->next;
		i++;
	}
	while (1)
	{
		if (filo->table->died)
			return ;
		usleep(1000);
	}
	
}