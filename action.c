/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:22:56 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 14:58:27 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>
#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int	other_thread(t_data *data)
{
	pthread_mutex_lock(data->state_mutex);
	if (*(data->state_p) == 1)
		return (pthread_mutex_unlock(data->state_mutex), 1);
	pthread_mutex_unlock(data->state_mutex);
	return (0);
}

int	ft_eat(t_data *data)
{
	if (data->index_philo % 2 == 0)
	{
		if (lock_fork_rl(data) == 1)
			return (1);
	}
	else
	{
		if (lock_fork_lr(data) == 1)
			return (1);
	}
	print_state(data->index_philo, data, "is eating");
	pthread_mutex_lock(&data->last_meal_m);
	data->last_meal = get_time();
	pthread_mutex_unlock(&data->last_meal_m);
	ft_usleep(data->datarg.tto_eat);
	pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_l]);
	pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_r]);
	return (0);
}

int	ft_sleep(t_data *data)
{
	if (print_state(data->index_philo, data, "is sleeping") == 1)
		return (1);
	ft_usleep(data->datarg.tto_sleep);
	return (0);
}

int	ft_think(t_data *data)
{
	if (print_state(data->index_philo, data, "is thinking") == 1)
		return (1);
	return (0);
}
