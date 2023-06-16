/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otaraki <otaraki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 04:18:08 by otaraki           #+#    #+#             */
/*   Updated: 2023/06/16 11:11:20 by otaraki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../includes/philo.h"

t_philo	*ft_lstnew_ph(int id)
{
	t_philo	*node;

	node = (t_philo *)malloc(sizeof(t_philo));
	if (node == NULL)
		return (NULL);
	node->id = id;
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
