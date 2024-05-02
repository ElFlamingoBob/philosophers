/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:01:35 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:09 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_thread(void *arg)
{
	struct timeval	current_time;
	t_data			*data;

	data = (t_data *)arg;
	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&data->last_meal_m);
	data->last_meal = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	pthread_mutex_unlock(&data->last_meal_m);
	if (data->index_philo % 2 == 0)
		usleep(data->datarg.tto_eat * 800);
	if (data->datarg.boolnotepme == 1)
	{
		if (core2(&data) == 1)
			return (NULL);
	}
	else
	{
		if (core(&data) == 1)
			return (NULL);
	}
	return (NULL);
}

void	thread_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->datarg.num_of_philo)
		pthread_create(&data[i].philo, NULL, ft_thread, &data[i]);
}
