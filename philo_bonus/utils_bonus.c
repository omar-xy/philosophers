/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 02:12:51 by otaraki           #+#    #+#             */
/*   Updated: 2023/08/11 13:10:17 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_lstnew_ph(int id, t_table *table)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (node == NULL)
		return (NULL);
	node->id = id;
	node->table = table;
	node->next = NULL;
	return (node);
}

t_philo	*ft_lstlast_ph(t_philo *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back_ph(t_philo **lst, t_philo *new)
{
	if (!new && !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast_ph(*lst)->next = new;
}

void	ph_error(char *msg)
{
	printf("%s\n", msg);
	return ;
}
