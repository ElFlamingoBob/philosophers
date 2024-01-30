/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:43:52 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/30 11:30:32 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(int state, int timestamp, int philo_num)
{
	if (state == 1)
		printf("%d %d has taken a fork\n", timestamp, philo_num);
	if (state == 2)
		printf("%d %d is eating\n", timestamp, philo_num);
	if (state == 3)
		printf("%d %d is sleeping\n", timestamp, philo_num);
	if (state == 4)
		printf("%d %d is thinking\n", timestamp, philo_num);
	if (state == 5)
		printf("%d %d died\n", timestamp, philo_num);
}