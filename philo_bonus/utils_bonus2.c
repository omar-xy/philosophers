/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:18:11 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 13:23:11 by otaraki          ###   ########.fr       */
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
			printf("%ld %d died \n", \
				time_now() - (filo->table->time_begin), filo->id);
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

void	kill_child(pid_t *pids, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->table->nbr_of_philo)
	{
		kill(pids[i], SIGTERM);
		i++;
	}
}
