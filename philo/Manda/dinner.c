/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/14 00:19:40 by otaraki          ###   ########.fr       */
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
	while ((time_now() - period) < t)
		usleep(100);
	return ;
}

void	*pattern(void *temp)
{
	t_philo *philo;
	int		meal;

	meal = 0;
	philo = (t_philo *)temp;
	if ((philo->id % 2) == 0)
		usleep(400);
	philo->last_meal = time_now();
	while (1)
	{
		lock_forks(philo);
		eating(philo);
		if (meal < philo->nbr_of_meals)
			meal++;
		if (meal == philo->nbr_of_meals)
			philo->table->nbr_of_philo -= 1;
		ft_my_usleep(philo->table->time_to_eat);
		philo->last_meal = time_now();
		unlock_forks(philo);
		sleeping(philo);
		ft_my_usleep(philo->table->time_to_sleep);
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
	check_death(filo);
}