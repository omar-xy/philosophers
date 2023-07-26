/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 23:43:33 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/24 23:41:56 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

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
		pthread_mutex_destroy((philo->death));
		pthread_mutex_destroy((philo->write));
		i++;
	}
}
