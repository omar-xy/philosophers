/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:24:02 by otaraki           #+#    #+#             */
/*   Updated: 2023/07/10 11:04:44 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#   define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
#include <sys/time.h>
# include "../libft/libft.h"

typedef struct s_philo
{
    int id;
    pthread_t thread;
    pthread_mutex_t fork;
    int nbr_of_meals;
    unsigned long last_meal;
    struct s_table *table;
    struct s_philo *next;
}               t_philo;
 
typedef struct s_table
{ 
    int nbr_of_philo;
	int died;
    unsigned long time_to_die;
    unsigned long time_to_eat;
    unsigned long time_to_sleep;
    unsigned long time_begin;
    pthread_mutex_t write;
    pthread_mutex_t death;
    struct s_philo *philos;
}               t_table;

//parse utils
t_philo	*ft_lstnew_ph(int id, t_table *table);
t_philo	*ft_lstlast_ph(t_philo *lst);
void	ft_lstadd_back_ph(t_philo **lst, t_philo *new);
t_table *set_args(char **av);
void check_args(t_table *arg);
unsigned long time_now(void);
//----------------------------------------------------------------
void	start_dinner(t_philo *filo, int n);
void	die_philo(t_table *fifo);
unsigned long time_now(void);

#endif