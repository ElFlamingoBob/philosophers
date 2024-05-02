/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:14:03 by efayolle          #+#    #+#             */
/*   Updated: 2024/04/25 15:04:14 by efayolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <bits/types/struct_timeval.h>
# include <strings.h>

typedef struct s_data_arg
{
	int	num_of_philo;
	int	tto_die;
	int	tto_eat;
	int	tto_sleep;
	int	notepme;
	int	boolnotepme;
}							t_data_arg;

typedef struct s_shared_var
{
	int				state_p;
	int				time_epe;
	pthread_mutex_t	print_m;
	pthread_mutex_t	state_m;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	teme_m;
}							t_shared_var;

typedef struct s_fork
{
	pthread_mutex_t	*forks;
}	t_fork;

typedef struct s_data
{
	pthread_t		philo;
	pthread_mutex_t	teme_m;
	pthread_mutex_t	last_meal_m;
	pthread_mutex_t	*state_mutex;
	pthread_mutex_t	*print;
	t_fork			fork_s;
	int				id_forks_l;
	int				id_forks_r;
	int				index_philo;
	t_data_arg		datarg;
	long			start_ms;
	long long		last_meal;
	long			time;
	int				*start;
	int				*state_p;
	int				time_epe;
	t_shared_var	*sh_var;
}							t_data;

int			other_thread(t_data *data);
int			ft_eat(t_data *data);
int			ft_sleep(t_data *data);
int			ft_think(t_data *data);

int			check(t_data_arg arg);
int			ft_usleep(size_t time);
long long	get_time(void);
int			check_params(char **args);

int			core(t_data **data);
int			core2(t_data **data);

int			ft_atoi(const char *src);
void		ft_bzero(void *s, size_t n);

int			print_state(int philo_num, t_data *data, char *message);

void		thread_destroy(t_data *data);
void		ft_monitoring(t_data *data, t_data_arg arg, int i);

int			fork_l(t_data *data);
int			fork_r(t_data *data);
int			lock_fork_rl(t_data *data);
int			lock_fork_lr(t_data *data);

void		thread_init(t_data *data);

#endif