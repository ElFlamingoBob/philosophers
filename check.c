/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:35:06 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/24 14:30:49 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(t_data_arg arg)
{
	if (arg.num_of_philo == 1)
	{
		printf("%d %d has taken a fork\n", 0, 1);
		usleep(arg.tto_die * 1000);
		printf("%d %d died\n", arg.tto_die, 1);
		return (1);
	}
	return (0);
}

long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "time error\n", 11);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_time();
	while (get_time() - start < time)
		usleep(50);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_params(char **args)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (ft_isdigit(args[i][j]) == 0)
				return (0);
		}
	}
	return (1);
}
