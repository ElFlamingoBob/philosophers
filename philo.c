/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:12:39 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/07 13:31:54 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	core2(t_data **data)
{
	int	aliveornot;
	int	start;

	start = 0;
	aliveornot = 0;
	while (aliveornot++ < (*data)->datarg.notepme)
	{
		printf("%d %d\n", (*data)->index_philo, aliveornot);
		if (ft_eat(*data, start) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		if (ft_sleep(*data) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		if (ft_think(*data) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		start = 1;
	}
	return (0);
}

int	core(t_data **data)
{
	int	aliveornot;
	int	start;

	start = 0;
	aliveornot = 1;
	while (aliveornot)
	{
		if (ft_eat(*data, start) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		if (ft_sleep(*data) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		if (ft_think(*data) == 1)
		{
			(*data)->state_p[(*data)->index_philo - 1] = 1;
			return (1);
		}
		start = 1;
	}
	return (0);
}

void	thread_destroy(t_data *data)
{
	int	i;
	int j;

	i = -1;
	while (++i < data->datarg.num_of_philo)
	{
		// write(2, "1", 1);
		j = pthread_join(data[i].philo, NULL);
		// printf("%d\n", j);
		// write(2, "2", 1);
		pthread_mutex_destroy(&data[i].fork_philo);
		// write(2, "3", 1);
	}
}

void	thread_init(t_data *data)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = data->datarg.num_of_philo - 1;
	while (++i < data->datarg.num_of_philo)
	{
		if (i == 0)
		{
			data[i].fork_philo_m1 = data[tmp].fork_philo;
			data[i].fork_philo_m1_p = &data[tmp].fork_philo;
		}
		else
		{
			data[i].fork_philo_m1 = data[i - 1].fork_philo;
			data[i].fork_philo_m1_p = &data[i - 1].fork_philo;
		}
		pthread_create(&data[i].philo, NULL, ft_thread, &data[i]);
		data[i].index_philo = i + 1;
	}
}

void	*ft_thread(void *arg)
{
	struct timeval	current_time;
	t_data			*data;

	data = (t_data *)arg;
	while (*data->start)
		;
	gettimeofday(&current_time, NULL);
	data->start_ms = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (data->index_philo % 2 == 0)
		usleep (data->datarg.tto_eat * 1000);
	if (data->datarg.boolnotepme == 1)
	{
		if (core2(&data) == 1)
		{
			printf("test %d\n", data->index_philo);
			return (NULL);
		}
	}
	else
	{
		if (core(&data) == 1)
			return (NULL);
	}
	return (NULL);
}

void	thread_creation(t_data_arg arg)
{
	t_data	*data;
	int		start;
	int		*state;
	int		i;

	i = -1;
	start = 1;
	data = malloc(sizeof(t_data) * arg.num_of_philo);
	if (!data)
		return ;
	state = malloc(sizeof(int) * arg.num_of_philo);
	if (!state)
		return ;
	while (++i < arg.num_of_philo)
	{
		pthread_mutex_init(&data[i].fork_philo, NULL);
		data[i].fork_philo_p = &data[i].fork_philo;
		data[i].datarg = arg;
		data[i].start = &start;
		state[i] = 0;
		data[i].state_p = state;
	}
	thread_init(data);
	start = 0;
	thread_destroy(data);
	free(state);
	free(data);
}

int	main(int argc, char **argv)
{
	struct s_data_arg	datarg;

	if (argc < 5 || argc > 6)
	{
		printf("Wrong number of arguments\n");
		return (0);
	}
	datarg.num_of_philo = ft_atoi(argv[1]);
	datarg.tto_die = ft_atoi(argv[2]);
	datarg.tto_eat = ft_atoi(argv[3]);
	datarg.tto_sleep = ft_atoi(argv[4]);
	if (check(datarg) == 1)
		return (1);
	if (argc == 6)
	{
		datarg.notepme = ft_atoi(argv[5]);
		datarg.boolnotepme = 1;
	}
	else
		datarg.boolnotepme = 0;
	thread_creation(datarg);
	return (0);
}
