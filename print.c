/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:43:52 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/26 11:46:33 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_state(int state, int timestamp, int philo_num)
{
	if (state == 1)
		printf("%d %d has taken a fork", timestamp, philo_num);
	if (state == 2)
		printf("%d %d is eating", timestamp, philo_num);
	if (state == 3)
		printf("%d %d is sleeping", timestamp, philo_num);
	if (state == 4)
		printf("%d %d is thinking", timestamp, philo_num);
	if (state == 5)
		printf("%d %d died", timestamp, philo_num);
}