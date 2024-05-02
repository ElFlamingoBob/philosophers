/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:12:39 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 15:21:28 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <bits/pthreadtypes.h>

void	init_struct_var(t_data *data, t_data_arg arg)
{
	int			i;
	long long	time;

	time = get_time();
	i = -1;
	while (++i < arg.num_of_philo)
	{
		pthread_mutex_init(&data[i].last_meal_m, NULL);
		pthread_mutex_init(&data[i].teme_m, NULL);
		data[i].datarg = arg;
		data[i].start_ms = time;
		data[i].last_meal = time;
		data[i].index_philo = i + 1;
		data[i].id_forks_l = i;
		data[i].id_forks_r = (i + 1) % data->datarg.num_of_philo;
		if (data->datarg.boolnotepme)
			data[i].time_epe = data->datarg.notepme;
	}
}

void	start_fct(t_data *data, t_data_arg arg)
{
	int	i;

	i = -1;
	thread_init(data);
	usleep(data->datarg.tto_die / 2);
	ft_monitoring(data, arg, i);
	thread_destroy(data);
}

void	thread_creation(t_data_arg arg, int i)
{
	t_data			*data;
	t_shared_var	sh_var;
	t_fork			forks;

	data = malloc(sizeof(t_data) * arg.num_of_philo);
	if (!data)
		return ;
	forks.forks = malloc(sizeof(pthread_mutex_t) * arg.num_of_philo);
	if (!forks.forks)
		return (free(data));
	while (++i < arg.num_of_philo)
		pthread_mutex_init(&forks.forks[i], NULL);
	ft_bzero(&sh_var, sizeof(t_shared_var));
	pthread_mutex_init(&sh_var.state_m, NULL);
	pthread_mutex_init(&sh_var.print_m, NULL);
	init_struct_var(data, arg);
	i = -1;
	while (++i < data->datarg.num_of_philo)
	{
		data[i].fork_s = forks;
		data[i].state_mutex = &sh_var.state_m;
		data[i].print = &sh_var.print_m;
		data[i].state_p = &sh_var.state_p;
	}
	start_fct(data, arg);
}

int	main(int argc, char **argv)
{
	struct s_data_arg	datarg;
	int					i;

	i = -1;
	if (argc < 5 || argc > 6)
		return (printf("Wrong number of arguments\n"), 1);
	if (check_params(argv) == 0)
		return (printf("Bad parameters\n"), 1);
	datarg.num_of_philo = ft_atoi(argv[1]);
	datarg.tto_die = ft_atoi(argv[2]);
	datarg.tto_eat = ft_atoi(argv[3]);
	datarg.tto_sleep = ft_atoi(argv[4]);
	if (check(datarg) == 1)
		return (1);
	if (argc == 6)
		datarg.notepme = ft_atoi(argv[5]);
	if (datarg.num_of_philo < 1 || (argc == 6 && datarg.notepme <= 0))
		return (printf("Bad parameters\n"), 1);
	datarg.boolnotepme = (argc == 6);
	thread_creation(datarg, i);
	return (0);
}
