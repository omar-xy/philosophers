/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 03:46:03 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/16 04:22:22 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/philo.h"

long long int big = 0;

void *your_turn()
{
    pthread_mutex_t mutex;
    long long i = 0;
    while (i < 100)
    {
        pthread_mutex_lock(&mutex);
        i++;
        big++;
        pthread_mutex_lock(&mutex);         
    }
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, &your_turn, NULL);
    your_turn();
    your_turn();
    pthread_join(thread, NULL);
    pthread_join(thread, NULL);
    printf("the res is %lld\n", big);
}

