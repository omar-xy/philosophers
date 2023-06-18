/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/18 02:42:50 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void	*pattern(void *temp)
{
	t_philo *philo;
	
	philo = (t_philo *)temp;
	if (!(philo->id % 2))
		usleep(900);
	while (1)
	{
		pthread_mutex_lock(&philo->fork);
		printf("philo %d as taken a fork 1\n",philo->id);
		pthread_mutex_lock(&philo->next->fork);
		printf("philo %d as taken a fork 2\n", philo->id);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		sleep(1);
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
		pthread_join(filo->thread, NULL);
		filo = filo->next;
		i++;
	}
	printf("%d\n", filo->id);
}