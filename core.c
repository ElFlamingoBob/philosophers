/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:59:01 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 14:46:19 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

int	core2(t_data **data)
{
	while (1)
	{
		if (ft_eat(*data) == 1)
			return (1);
		pthread_mutex_lock(&(*data)->teme_m);
		if ((*data)->time_epe > 0)
			(*data)->time_epe--;
		pthread_mutex_unlock(&(*data)->teme_m);
		if (ft_sleep(*data) == 1)
			return (1);
		usleep(500);
		if (ft_think(*data) == 1)
			return (1);
	}
	return (0);
}

int	core(t_data **data)
{
	while (1)
	{
		if (ft_eat(*data) == 1)
			return (1);
		if (ft_sleep(*data) == 1)
			return (1);
		usleep(500);
		if (ft_think(*data) == 1)
			return (1);
	}
	return (0);
}
