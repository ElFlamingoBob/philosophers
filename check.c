/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:35:06 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/07 11:28:41 by efayolle         ###   ########.fr       */
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
