/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:22:56 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/08 10:06:19 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	other_thread(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->datarg.num_of_philo)
	{
		if (data->state_p[i] == 1)
			return (1);
	}
	return (0);
}

int	ft_eat(t_data *data, int s)
{
	struct timeval	ct;
	int				check;

	if (s == 0)
		check = check_tto_die(data, 0);
	else
		check = check_tto_die(data, 1);
	if (check == 1)
		return (1);
	pthread_mutex_lock(data->fork_philo_p);
	pthread_mutex_lock(data->fork_philo_m1_p);
	if (s == 0)
		check = check_tto_die(data, 0);
	else
		check = check_tto_die(data, 1);
	if (check == 1)
		return (1);
	print_state(1, data->index_philo, data);
	print_state(2, data->index_philo, data);
	gettimeofday(&ct, NULL);
	data->last_meal = ct.tv_sec * 1000 + ct.tv_usec / 1000;
	ft_usleep(data->datarg.tto_eat);
	pthread_mutex_unlock(data->fork_philo_p);
	pthread_mutex_unlock(data->fork_philo_m1_p);
	return (0);
}

int	ft_sleep(t_data *data)
{
	int	check;

	check = check_tto_die(data, 1);
	if (check == 1)
		return (1);
	print_state(3, data->index_philo, data);
	ft_usleep(data->datarg.tto_sleep);
	return (0);
}

int	ft_think(t_data *data)
{
	int	check;

	check = check_tto_die(data, 1);
	if (check == 1)
		return (1);
	print_state(4, data->index_philo, data);
	return (0);
}

int	check_tto_die(t_data *data, int s)
{
	long			diff;
	struct timeval	cu_ti;

	if (other_thread(data) == 1)
		return (1);
	gettimeofday(&cu_ti, NULL);
	if (s == 0)
	{
		diff = (cu_ti.tv_sec * 1000 + cu_ti.tv_usec / 1000) - data->start_ms;
		if (diff > data->datarg.tto_die)
		{
			print_state(5, data->index_philo, data);
			return (1);
		}
	}
	else
	{
		diff = (cu_ti.tv_sec * 1000 + cu_ti.tv_usec / 1000) - data->last_meal;
		if (diff > data->datarg.tto_die)
		{
			print_state(5, data->index_philo, data);
			return (1);
		}
	}
	return (0);
}
