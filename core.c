/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:59:01 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/08 09:59:06 by efayolle         ###   ########.fr       */
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
