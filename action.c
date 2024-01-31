/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:22:56 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/31 11:44:50 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_data *data)
{
	pthread_mutex_lock(data->fork_philo_p);
	pthread_mutex_lock(data->fork_philo_m1_p);
	print_state(1, 0, data->index_philo);
	print_state(2, 0, data->index_philo);
	usleep(data->datarg.tto_eat * 10000);
	pthread_mutex_unlock(data->fork_philo_p);
	pthread_mutex_unlock(data->fork_philo_m1_p);
}

void	ft_sleep(t_data *data)
{
	print_state(3, 0, data->index_philo);
	usleep(data->datarg.tto_sleep * 10000);
}

void	ft_think(t_data *data)
{
	print_state(4, 0, data->index_philo);
}

void	check_tto_die(t_data *data, struct timeval cu_ti, int s)
{
	int diff;
	
	gettimeofday(&cu_ti, NULL);
	if (s == 1)
	{
		diff = cu_ti.tv_usec - data->start_ms;
		if (diff > data->datarg.tto_die)
			print_state(5, 0, data->index_philo);
	}
	else
	{
		diff = cu_ti.tv_usec - data->last_meal;
		if (diff > data->datarg	.tto_die)
			print_state(5, 0, data->index_philo);
	}
}
