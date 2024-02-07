/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:01:22 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/02 12:25:17 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list *lst_new(pthread_mutex_t *tab, int index)
{
	t_list *lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->index = index;
	lst->tab = tab;
	lst->state = 0;
	lst->next = NULL;
	return (lst);
}
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == (void *)0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}