/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:30:18 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 17:20:15 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

sem_t	*sem_open_parms(char *str, int flag)
{
	sem_t	*sem;

	sem_unlink(str);
	sem = sem_open(str, O_CREAT, 0654, flag);
	if (sem == SEM_FAILED)
		exit (1);
	return (sem);
}

t_table	*initialize_philos(t_table **ph, int n, char **av)
{
	int				i;
	t_philo			*tmp;

	i = 1;
	(*ph)->fork = sem_open_parms("fork", (*ph)->nbr_of_philo);
	(*ph)->death = sem_open_parms("death", 0);
	(*ph)->write = sem_open_parms("write", 1);
	if (av[5])
	{
		(*ph)->nbr_meals = ft_atoi(av[5]);
		(*ph)->nb_of_meals = sem_open_parms("nbr_of_meals", 0);
	}
	else
		(*ph)->nbr_meals = -1;
	while (i <= n)
	{
		tmp = ft_lstnew_ph(i, *ph);
		ft_lstadd_back_ph(&(*ph)->philos, tmp);
		i++;
	}
	return (*ph);
}

t_table	*set_args(char **av)
{
	t_table	*ph;

	ph = malloc(sizeof(t_table));
	if (ph == NULL)
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
	ph->time_begin = time_now();
	return (ph);
}

int	main(int ac, char **av)
{
	t_table	*philo;

	if (ac == 5 || ac == 6)
	{
		if (check_args(av) == 0)
		{
			ph_error("Invalide args");
			return (1);
		}
		philo = set_args(av);
		if (!philo)
			return (1);
		philo = initialize_philos(&philo, philo->nbr_of_philo, av);
		if (!philo)
			return (1);
		fork_for_philo(philo->philos, av);
	}
	else
	{
		printf("Inavlid number of args!\n");
		return (1);
	}
}
