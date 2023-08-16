/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:18:08 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 01:45:33 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

t_philo	*ft_lstnew_ph(int id, t_table *table)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (node == NULL)
		return (NULL);
	node->id = id;
	node->table = table;
	pthread_mutex_init(&node->fork, NULL);
	node->next = NULL;
	return (node);
}

t_philo	*ft_lstlast_ph(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_ph(t_philo **lst, t_philo *new)
{
	if (!new && !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast_ph(*lst)->next = new;
}

void	check_death(t_philo *filo)
{
	while (filo)
	{
		usleep(1000);
		pthread_mutex_lock(filo->protect);
		if (time_now() - filo->last_meal > filo->table->time_to_die)
		{
			pthread_mutex_unlock(filo->protect);
			pthread_mutex_lock(filo->write);
			printf("%ld %d died \n", 
				time_now() - (filo->table->time_begin), filo->id);
			return ;
		}
		if (check_meal(filo))
		{
			pthread_mutex_unlock(filo->protect);
			break ;
		}
		pthread_mutex_unlock(filo->protect);
		filo = filo->next;
	}
	destroy_data(filo);
}
