/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:51:20 by stephan           #+#    #+#             */
/*   Updated: 2025/07/25 15:07:34 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

# define USE "\n\
╔═════════════════════════════╗\n\
║        Usage Format         ║\n\
╠═════════════════════════════╣\n\
║ number_of_philosophers      ║\n\
║ time_to_die      (ms)       ║\n\
║ time_to_eat      (ms)       ║\n\
║ time_to_sleep    (ms)       ║\n\
║ [number_of_meals] (optional)║\n\
╚═════════════════════════════╝\n"

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				x_meals;
	long long		last_meal;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meals;
	int				dead;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	pthread_mutex_t	death_lock;
	pthread_mutex_t	data_mutex;
	t_philo			*philos;
}	t_data;

//Parse input
int		init_philo(int argc, char **argv, t_data *data);
void	init_data(int argc, char **argv, t_data *data);
long	ft_atol(char *str);

#endif