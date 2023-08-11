/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:08:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 13:23:36 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

typedef struct s_philo
{
	int				id;
	unsigned long	last_meal;
	struct s_table	*table;
	struct s_philo	*next;
}						t_philo;
typedef struct s_table
{
	int				nbr_of_philo;
	int				nbr_meals;
	int				died;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	time_begin;
	sem_t			*death;
	sem_t			*write;	
	sem_t			*fork;
	sem_t			*nb_of_meals;
	struct s_philo	*philos;
}						t_table;

//parse utils
int				ft_atoi(const char *str);
t_philo			*ft_lstnew_ph(int id, t_table *table);
t_philo			*ft_lstlast_ph(t_philo *lst);
t_table			*set_args(char **av);
void			ft_lstadd_back_ph(t_philo **lst, t_philo *new);
unsigned long	time_now(void);
void			ph_error(char *msg);
void			ft_my_usleep(unsigned long t);
void			fork_for_philo(t_philo *ph, char **av);
// actions
void			lock_forks(t_philo *philo);
void			unlock_forks(t_philo *philo);
void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			*check_death(void *param);
void			kill_child(pid_t *pids, t_philo *ph);
#endif