/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:12:39 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/29 13:23:27 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void *ft_thread(void *arg)
{
	struct timeval	current_time;
	t_data *data;
	int aliveornot;

	data = (t_data *)arg;
	aliveornot = 0;
	/* while (aliveornot)
	{
		gettimeofday(&current_time, NULL);
		pthread_mutex_lock(&data->fork_philo);
	} */
	printf("%d\n", data->index_philo);
	return (NULL);
}

void	thread_creation(t_data_arg *arg)
{
	t_data data[arg->num_of_philo];
	int			i = -1;

	while (++i < arg->num_of_philo)
		pthread_mutex_init(&data[i].fork_philo, NULL);
	i = -1;
	while (++i < arg->num_of_philo)
	{
		if (i == 0)
			data[i].fork_philo_m1 = &data[arg->num_of_philo].fork_philo;
		else
			data[i].fork_philo_m1 = &data[i - 1].fork_philo;
		pthread_create(&data[i].philo, NULL, ft_thread, &data[i]);
		data[i].index_philo = i + 1;
	}
	i = -1;
	while (++i < arg->num_of_philo)
	{
		pthread_join(data[i].philo, NULL);
		pthread_mutex_destroy(&data[i].fork_philo);
	}
}

int main(int argc, char **argv)
{
	t_data_arg datarg;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	datarg.num_of_philo = ft_atoi(argv[1]);
	datarg.tto_die = ft_atoi(argv[2]);
	datarg.tto_eat = ft_atoi(argv[3]);
	datarg.tto_sleep = ft_atoi(argv[4]);

	
	thread_creation(&datarg);

	
	return (0);
}
