/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:14:03 by efayolle          #+#    #+#             */
/*   Updated: 2024/01/31 11:37:07 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data_arg
{
	int	num_of_philo;
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
}							t_data_arg;

typedef struct s_data
{
	pthread_t		philo;
	pthread_mutex_t	fork_philo;
	pthread_mutex_t	fork_philo_m1;
	pthread_mutex_t	*fork_philo_p;
	pthread_mutex_t	*fork_philo_m1_p;
	int				index_philo;
	t_data_arg		datarg;
	long			start_ms;
	long			last_meal;
	int				*start;
}							t_data;

int		ft_atoi(const char *src);

void	print_state(int state, int timestamp, int philo_num);

void	ft_eat(t_data *data);
void	ft_sleep(t_data *data);
void	ft_think(t_data *data);

#endif