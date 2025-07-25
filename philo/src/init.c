/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:40:44 by stephan           #+#    #+#             */
/*   Updated: 2025/07/25 15:18:25 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(int argc, char **argv, t_data *data)
{
	data->num_philo = ft_atol(argv[1]);
	data->time_die = ft_atol(argv[2]);
	data->time_eat = ft_atol(argv[3]);
	data->time_sleep = ft_atol(argv[4]);
	data->dead = 1;
	if (argc == 6)
		data->max_meals = ft_atol(argv[5]);
	else
		data->max_meals = 99999999;
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_message(philo, "is thinking");
	while (philo->data->dead == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_message(philo, "has taken a fork");
		print_message(philo, "is eating");
		pthread_mutex_lock(&philo->data->data_mutex);
		philo->last_meal = get_current_time();
		philo->x_meals++;
		pthread_mutex_unlock(&philo->data->data_mutex);
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_message(philo, "is sleeping");
		usleep(philo->data->time_sleep * 1000);
		print_message(philo, "is thinking");
	}
	return (NULL);
}

void	init_threads(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	if (!data->philos)
		return (0);
	while (i < data->num_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].x_meals = 0;
		data->philos[i].last_meal = 0;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		i++;
	}
	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&data->philos[i].thread, NULL, philo_routine,
			&data->philos[i] != 0);
		i++;
	}
	return (1);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (0);
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (0);
		i++;
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (0);
	return (1);
}

void	msg(t_philo *philo, char *str)
{
	long	t;

	t = get_current_time() - philo->data->start_time;
	if (philo->data->dead == 1)
		printf("%ld %d %s\n", t, philo->id, str);
}