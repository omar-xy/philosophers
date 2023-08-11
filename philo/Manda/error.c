/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:43:33 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 16:41:48 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ph_error(char *msg)
{
	printf("%s\n", msg);
	return ;
}

void	destroy_data(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->nbr_of_philo)
	{
		pthread_mutex_destroy(&(philo->fork));
		i++;
	}
	pthread_mutex_destroy((philo->death));
	pthread_mutex_destroy((philo->write));
}

int	check_meal(t_philo *philo)
{
	if (philo->table->nbr_of_meals >= 0)
	{
		if (philo->n_of_meals_per_philo == philo->table->nbr_of_meals)
			return (1);
		else
			return (0);
	}
	return (0);
}
