/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:18:08 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/16 04:24:13 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/philo.h"

int kko(char **b)
{
    (void )b;
    int x = 2;
    int pid = fork();
    
    if (pid < 0)
        return 1;
    if (pid == 0)
        x++;
    printf("the value of %d\n", x);
    if (pid != 0)
        wait(NULL);
    return 0;
}