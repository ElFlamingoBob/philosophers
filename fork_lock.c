/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:56:52 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 15:00:08 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	fork_l(t_data *data)
{
	pthread_mutex_lock(&data->fork_s.forks[data->id_forks_l]);
	if (print_state(data->index_philo, data, "has taken a fork") == 1)
		return (1);
	return (0);
}

int	fork_r(t_data *data)
{
	pthread_mutex_lock(&data->fork_s.forks[data->id_forks_r]);
	if (print_state(data->index_philo, data, "has taken a fork") == 1)
		return (1);
	return (0);
}

int	lock_fork_rl(t_data *data)
{
	if (fork_r(data) == 1)
		return (pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_r]), 1);
	if (fork_l(data) == 1)
	{
		pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_r]);
		pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_l]);
		return (1);
	}
	return (0);
}

int	lock_fork_lr(t_data *data)
{
	if (fork_l(data) == 1)
		return (pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_l]), 1);
	if (fork_r(data) == 1)
	{
		pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_r]);
		pthread_mutex_unlock(&data->fork_s.forks[data->id_forks_l]);
		return (1);
	}
	return (0);
}
