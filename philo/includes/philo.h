/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:24:02 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/16 10:42:25 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#   define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include "../libft/libft.h"

typedef struct s_philo
{
    int id;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nbr_of_meals;
    struct s_philo *next;
}               t_philo;

typedef struct s_table
{ 
    int forks;
    struct s_philo *philos;        
}               t_table;

//parse utils
t_philo	*ft_lstnew_ph(int id);
t_philo	*ft_lstlast_ph(t_philo *lst);
void	ft_lstadd_back_ph(t_philo **lst, t_philo *new);
t_table *set_args(char **av);
void check_args(t_table *arg);

#endif