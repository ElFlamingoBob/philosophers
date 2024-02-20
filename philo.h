/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:14:03 by efayolle          #+#    #+#             */
/*   Updated: 2024/02/14 09:10:37 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_data_arg
{
	int	num_of_philo;
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
	int	notepme;
	int	boolnotepme;
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
	int				*state_p;
}							t_data;

int		other_thread(t_data *data);
int		ft_eat(t_data *data, int s);
int		ft_sleep(t_data *data);
int		ft_think(t_data *data);
int		check_tto_die(t_data *data, int s);

int		check(t_data_arg arg);
void	ft_usleep(int wait);

int		core(t_data **data);
int		core2(t_data **data);

int		ft_atoi(const char *src);

void	print_state(int state, int philo_num, t_data *data);

#endif