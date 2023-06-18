/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:46:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/18 02:05:31 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void check_args(t_table *arg)
{
	if (arg->nbr_of_philo == 1)
	{
		usleep(arg->time_to_eat);
		printf("the philo must die\n");
		exit (0);
	}
	else if (arg->nbr_of_philo < 1 || arg->nbr_of_philo > 200)
	{
		printf("the number of philos invalid\n");
		exit (0);
	}
	
}

void	add_philos(t_table **ph, int n, char **av)
{
	int	i;
	t_philo *tmp;

	i = 1;
	while (i <= n)
	{
		tmp = ft_lstnew_ph(i, *ph);
		if (av[5])
			tmp->nbr_of_meals = ft_atoi(av[5]);
		else
			tmp->nbr_of_meals = 0;
		ft_lstadd_back_ph(&(*ph)->philos, tmp);
		i++;
	}
	ft_lstlast_ph((*ph)->philos)->next = (*ph)->philos;
}

t_table *set_args(char **av)
{
	t_table	*ph;
    
	ph = malloc(sizeof(t_table));
	if (ph == NULL)
		return NULL;
	ph->nbr_of_philo = ft_atoi(av[1]);
	ph->time_to_die = ft_atoi(av[2]);
	ph->time_to_eat = ft_atoi(av[3]);
	ph->time_to_sleep = ft_atoi(av[4]);
	check_args(ph);
	add_philos(&ph, ph->nbr_of_philo, av);
	return (ph);
}

int main(int ac, char **av)
{
	t_table *philo;

    if (ac == 5 || ac == 6)
	{
		philo = set_args(av);
		start_dinner(philo->philos, philo->nbr_of_philo);
	}
	else
    	printf( "Inavlid args!\n");
}
 