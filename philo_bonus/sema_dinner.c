/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:33:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/05 02:02:03 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_death(void *param)
{
	t_philo	*filo;
	int		i;

	i = 0;
	filo = (t_philo *)param;
	while (1)
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
	
}

void	routine(t_philo *ph)
{
	int		meal;
	pthread_t	pthread;

	meal = 0;
	if ((ph->id % 2) == 0)
		usleep(400);
	pthread_create(&pthread, NULL, check_death, ph);
	ph->last_meal = time_now();
	while (1)
	{
		lock_forks(ph);
		eating(ph);
		ph->last_meal = time_now();
		ft_my_usleep(ph->table->time_to_eat, ph);
		unlock_forks(ph);
		if (ph->table->nbr_meals != -1 && meal < ph->table->nbr_meals)
			meal++;
		if (meal == ph->table->nbr_meals)
		{
			sem_post(ph->table->nb_of_meals);
			exit(0);	
		}
		sleeping(ph);
		ft_my_usleep(ph->table->time_to_sleep, ph);
		thinking(ph);
	}
}
// should handle the case of one philo
// should handle the
void	fork_for_philo(t_philo *ph, char **av)
{
	int		i;
	pid_t	*pids;
	pid_t	p;
	t_philo	*tmp;

	i = 0;
	tmp = ph;
	pids = malloc(sizeof(pid_t) * ph->table->nbr_of_philo);
	while (i < ph->table->nbr_of_philo)
	{
		p = fork();
		if (p < 0)
			break ;
		if (p == 0)
		{
			routine(tmp);
			exit(0);
		}
		tmp = tmp->next;
		pids[i] = p;
		i++;
	}
	if (av[5])
	{
		i = 0;
		while (i < ph->table->nbr_of_philo)
		{
			sem_wait(ph->table->nb_of_meals);
			i++;
		}
		sem_post(ph->table->death);
	}
	sem_wait(ph->table->death);
	i = 0;
	while (i < ph->table->nbr_of_philo)
	{
		kill(pids[i], SIGTERM);
        i++;
	}
	free(pids);
}