/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:46:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 17:17:50 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_args(char **av)
{
	int	i;

	i = 2;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

pthread_mutex_t	*allocate_mutex(int n)
{
	pthread_mutex_t	*tmp;

	tmp = malloc(sizeof(pthread_mutex_t) * n);
	if (!tmp)
		return (NULL);
	return (tmp);
}

t_table	*initialize_philos(t_table **ph, int n)
{
	int				i;
	t_philo			*tmp;
	pthread_mutex_t	*w;
	pthread_mutex_t	*p;

	p = allocate_mutex(n);
	w = allocate_mutex(1);
	if (pthread_mutex_init(w, NULL))
		ph_error("Failed to initialize!\n");
	i = 1;
	while (i <= n)
	{
		if (pthread_mutex_init(&p[i - 1], NULL))
			ph_error("Failed to initialize!\n");
		tmp = ft_lstnew_ph(i, *ph);
		tmp->write = w;
		tmp->protect = &p[i - 1];
		tmp->n_of_meals_per_philo = 0;
		ft_lstadd_back_ph(&(*ph)->philos, tmp);
		i++;
	}
	ft_lstlast_ph((*ph)->philos)->next = (*ph)->philos;
	free(p);
	free(w);
	return (*ph);
}

t_table	*set_args(char **av)
{
	t_table	*ph;

	ph = malloc(sizeof(t_table));
	if (!ph)
		return (NULL);
	ph->nbr_of_philo = ft_atoi(av[1]);
	if (ph->nbr_of_philo == 0)
	{
		ph_error("Number of philos should be greater than 0 !\n");
		return (free(ph), NULL);
	}
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		ph->nbr_of_meals = ft_atoi(av[5]);
	else
		ph->nbr_of_meals = -1;
	ph->time_begin = time_now();
	return (ph);
}

int	main(int ac, char **av)
{
	t_table	*philo;

	if (ac == 5 || ac == 6)
	{
		if (!check_args(av))
		{
			ph_error("Invalide args");
			return (1);
		}
		philo = set_args(av);
		if (!philo)
			return (1);
		philo = initialize_philos(&philo, philo->nbr_of_philo);
		if (!philo)
			return (1);
		start_dinner(philo->philos, philo->nbr_of_philo);
	}
	else
	{
		printf("Inavlid number of args!\n");
		return (1);
	}
}
