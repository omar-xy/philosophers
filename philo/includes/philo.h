/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:24:02 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/16 01:42:58 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				n_of_meals_per_philo;
	unsigned long	last_meal;
	pthread_t		thread;
	pthread_mutex_t	fork;
	pthread_mutex_t	*write;
	pthread_mutex_t	*protect;
	struct s_table	*table;
	struct s_philo	*next;
}						t_philo;
typedef struct s_table
{
	int				nbr_of_philo;
	int				nbr_of_meals;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_begin;
	struct s_philo	*philos;
}						t_table;

//parse utils
int				ft_atoi(const char *str);
t_philo			*ft_lstnew_ph(int id, t_table *table);
t_philo			*ft_lstlast_ph(t_philo *lst);
t_table			*set_args(char **av);
void			ft_lstadd_back_ph(t_philo **lst, t_philo *new);
unsigned long	time_now(void);

unsigned long	time_now(void);
void			ft_my_usleep(unsigned long t);
void			start_dinner(t_philo *filo, int n);
void			lock_forks(t_philo *philo);
void			unlock_forks(t_philo *philo);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			check_death(t_philo *filo);
int				check_meal(t_philo *philo);
void			ph_error(char *msg);
void			destroy_data(t_philo *philo);
#endif