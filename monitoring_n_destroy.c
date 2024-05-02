/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_n_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:54:49 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 14:55:51 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thread_destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->datarg.num_of_philo)
		pthread_join(data[i].philo, NULL);
	i = -1;
	while (++i < data->datarg.num_of_philo)
	{
		pthread_mutex_destroy(&data[i].last_meal_m);
		pthread_mutex_destroy(&data[i].teme_m);
	}
	pthread_mutex_destroy(data->print);
	pthread_mutex_destroy(data->state_mutex);
	free(data->fork_s.forks);
	free(data);
}

int	metpme(t_data *data)
{
	pthread_mutex_lock(&data->teme_m);
	if (data->time_epe == 0)
		return (pthread_mutex_unlock(&data->teme_m), 1);
	return (pthread_mutex_unlock(&data->teme_m), 0);
}

void	change_state_p(t_data *data)
{
	pthread_mutex_lock(data->state_mutex);
	*data->state_p = 1;
	pthread_mutex_unlock(data->state_mutex);
}

void	ft_monitoring(t_data *data, t_data_arg arg, int i)
{
	long long	time;
	int			count;

	while (1)
	{
		i = -1;
		count = 0;
		while (++i < arg.num_of_philo)
		{
			time = get_time();
			pthread_mutex_lock(&data[i].last_meal_m);
			if (time - data[i].start_ms >= arg.tto_die \
				&& time - data[i].last_meal >= arg.tto_die)
			{
				print_state(data[i].index_philo, data + i, "died");
				change_state_p(data);
				return ((void)pthread_mutex_unlock(&data[i].last_meal_m));
			}
			pthread_mutex_unlock(&data[i].last_meal_m);
			count += (arg.boolnotepme && metpme(data + i));
		}
		if (count == arg.num_of_philo)
			return ((void)change_state_p(data));
		usleep(500);
	}
}
