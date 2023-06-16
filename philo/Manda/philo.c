/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:46:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/16 11:15:21 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

void check_args(t_table *arg)
{
	int	n;

	n = arg->forks;
	if (n < 1 || n > 200)
	{
		puts("OOOOOO");
		printf("the number of philos invalid\n");
		exit (0);
	}
	
}

void	add_philos(t_philo **ph, int n, char **av)
{
	int	i;
	t_philo *tmp;

	i = 0;
	printf("%d\n", n);
	while (i < n)
	{
		printf("%d\n", i);
		tmp = ft_lstnew_ph(i);
		tmp->time_to_die = ft_atoi(av[2]);
		tmp->time_to_eat = ft_atoi(av[3]);
		tmp->time_to_sleep = ft_atoi(av[4]);
		tmp->nbr_of_meals = ft_atoi(av[5]);
		ft_lstadd_back_ph(ph, tmp);
		// free(tmp);
		i++;
	}
	ft_lstlast_ph(*ph)->next = *ph;
}
t_table *set_args(char **av)
{
	t_table	*ph;
    
	ph = malloc(sizeof(t_table));
	if (ph == NULL)
		return NULL;
	ph->forks = ft_atoi(av[1]);
	if (ph->forks == 1)
	{
		printf("the philo must die\n");
	}
	else
	{
		check_args(ph);
		add_philos(&(ph->philos), ft_atoi(av[1]), av);
	}
	return (ph);
}

int main(int ac, char **av)
{
	t_table *philo;

    if (ac == 5 || ac == 6)
	{
		philo = set_args(av);
		t_philo *tmp;

		tmp = philo->philos;
		while (tmp != NULL)
		{
			printf("{%d}\n", tmp->id);
			tmp = tmp->next;
		}
	}
    else
        printf( "Inavlid args!\n");
}
