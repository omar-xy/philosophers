/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sema_dinner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:33:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 13:28:50 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	loop_of_life(t_philo *phipho)
{
	int	meal;

	meal = 0;
	phipho->last_meal = time_now();
	while (1)
	{
		lock_forks(phipho);
		eating(phipho);
		phipho->last_meal = time_now();
		ft_my_usleep(phipho->table->time_to_eat);
		unlock_forks(phipho);
		if (phipho->table->nbr_meals != -1 && meal < phipho->table->nbr_meals)
			meal++;
		if (meal == phipho->table->nbr_meals)
		{
			sem_post(phipho->table->nb_of_meals);
			exit(0);
		}
		sleeping(phipho);
		ft_my_usleep(phipho->table->time_to_sleep);
		thinking(phipho);
	}
}

void	routine(t_philo *ph)
{
	pthread_t	pthread;

	if ((ph->id % 2) == 0)
		usleep(400);
	pthread_create(&pthread, NULL, check_death, ph);
	loop_of_life(ph);
}

void	optional_case(t_philo *phi, char **v)
{
	int	i;

	if (v[5])
	{
		i = 0;
		while (i < phi->table->nbr_of_philo)
		{
			sem_wait(phi->table->nb_of_meals);
			i++;
		}
		sem_post(phi->table->death);
	}
}

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
		pids[i++] = p;
	}
	optional_case(ph, av);
	sem_wait(ph->table->death);
	kill_child(pids, ph);
	free(pids);
}
