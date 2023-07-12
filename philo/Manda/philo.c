/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:46:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/12 18:58:52 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

t_table	*initialize_philos(t_table **ph, int n, char **av)
{
	int				i;
	t_philo			*tmp;
	pthread_mutex_t	d;	
	pthread_mutex_t	w;

	pthread_mutex_init(&d, NULL);
	pthread_mutex_init(&w, NULL);
	i = 1;
	while (i <= n)
	{
		tmp = ft_lstnew_ph(i, *ph);
		tmp->death = &d;
		tmp->write = &w;
		if (av[5])
			tmp->nbr_of_meals = ft_atoi(av[5]);
		else
			tmp->nbr_of_meals = -1;
		ft_lstadd_back_ph(&(*ph)->philos, tmp);
		i++;
	}
	ft_lstlast_ph((*ph)->philos)->next = (*ph)->philos;
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
		return NULL;// indicate the error
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	ph->time_begin = time_now();
	ph->died = 0;
	return (ph);
}

int main(int ac, char **av)
{
	t_table *philo;

    if (ac == 5 || ac == 6)
	{
		philo = set_args(av);
		if (!philo)
			return (1);
		philo = initialize_philos(&philo, philo->nbr_of_philo, av);
		if (!philo)
			return (1);
		start_dinner(philo->philos, philo->nbr_of_philo);
	}
	else
	{
    	printf( "Inavlid args!\n");
		return 1;
	}
}
