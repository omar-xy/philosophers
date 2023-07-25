/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 01:30:18 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/25 06:28:22 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int check_args(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
			return 0;
		i++;
	}
	return 1;
}

t_table	*initialize_philos(t_table **ph, int n, char **av)
{
	int				i;
	t_philo			*tmp;
	sem_t			*forks;
	sem_t			*dead;
	// sem_t			*nb_m;
	

	i = 1;
	sem_unlink("forks");
	sem_unlink("dead");
	// sem_unlink("nbr_of_meals");
	forks = sem_open("forks", O_CREAT, 0654, ft_atoi(av[1]));
	dead = sem_open("dead", O_CREAT, 0654, 0);
	// if (av[5])
	// {
	// 	nb_m = sem_open("nbr_of_meals", O_CREAT, 0654, 0);
	// 	(*ph)->nb_of_meals = nb_m;
	// 	(*ph)->nbr_meals = ft_atoi(av[5]);
	// }
	// else
	// 	(*ph)->nbr_meals = -1;
	(*ph)->fork = forks;
	(*ph)->death = dead;
	while (i <= n)
	{
		tmp = ft_lstnew_ph(i, *ph);
		ft_lstadd_back_ph(&(*ph)->philos, tmp);
		i++;
	}
	return (*ph);
}

t_table *set_args(char **av)
{
	t_table	*ph;

	ph = malloc(sizeof(t_table));
	if (ph == NULL)
		return (NULL);
	ph->nbr_of_philo = ft_atoi(av[1]);
	if (ph->nbr_of_philo == 0)
	{
		ph_error("Number of philos should be greater than 0 !\n");
		return NULL;
	}
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	ph->time_begin = time_now();
	return (ph);
}

int main(int ac, char **av)
{
	t_table *philo;

    if (ac == 5 || ac == 6)
	{
		if (check_args(av) == 0)
		{
			ph_error("Invalide args");
			return 1;
		}
		philo = set_args(av);
		if (!philo)
			return (1);
		philo = initialize_philos(&philo, philo->nbr_of_philo, av);
		if (!philo)
			return (1);
		fork_for_philo(philo->philos, av);
		
		// sema_dinner(philo, philo->nbr_of_philo);
	}
	else
	{
    	printf( "Inavlid number of args!\n");
		return 1;
	}
}