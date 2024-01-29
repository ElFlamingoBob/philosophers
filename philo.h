/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:14:03 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/29 13:23:09 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>



typedef struct s_data
{
	pthread_t		philo;
	pthread_mutex_t	fork_philo;
	pthread_mutex_t	*fork_philo_m1;
	int				index_philo;
}							t_data;

typedef struct s_data_arg
{
	int	num_of_philo;
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
}							t_data_arg;


int		ft_atoi(const char *src);

void	print_state(int state, int timestamp, int philo_num);

#endif