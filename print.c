/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:43:52 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/07 11:33:21 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int state, int philo_num, t_data *data)
{
	long			timestamp;
	struct timeval	tv;

	if (other_thread(data) == 1)
		return ;
	gettimeofday(&tv, NULL);
	timestamp = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - data->start_ms;
	if (state == 1)
		printf("%ld %d has taken a fork\n", timestamp, philo_num);
	if (state == 2)
		printf("%ld %d is eating\n", timestamp, philo_num);
	if (state == 3)
		printf("%ld %d is sleeping\n", timestamp, philo_num);
	if (state == 4)
		printf("%ld %d is thinking\n", timestamp, philo_num);
	if (state == 5)
		printf("%ld %d died\n", timestamp, philo_num);
}
