/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:38:05 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/17 00:53:15 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	start_dinner(t_table **ilo)
{
	int			i;
	pthread_t	*thread;

	thread = ft_calloc(sizeof(pthread_t) , (*ilo)->forks);
	i = 0;
	while (i < (*ilo)->forks)
	{
		pthread_create();
	}
}