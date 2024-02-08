/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:35:06 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/08 10:06:36 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check(t_data_arg arg)
{
	if (arg.num_of_philo == 1)
	{
		usleep(arg.tto_die * 1000);
		printf("%d %d died\n", arg.tto_die, 1);
		return (1);
	}
	return (0);
}

void	ft_usleep(int wait)
{
	struct timeval	now;
	long			time;
	long			diff;

	gettimeofday(&now, NULL);
	time = now.tv_sec * 1000000 + now.tv_usec;
	diff = time + wait * 1000;
	while (time < diff)
	{
		if (diff - time > 40)
			usleep((diff - time) / 2);
		gettimeofday(&now, NULL);
		time = now.tv_sec * 1000000 + now.tv_usec;
	}
	return ;
}
