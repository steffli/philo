/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 15:12:36 by stephan           #+#    #+#             */
/*   Updated: 2025/07/22 16:03:42 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (!*str || !str)
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	checker(int argc, char **argv)
{
	int		args;
	long	num;

	args = 1;
	if (argc < 5 || argc > 6)
		return (printf("Incorrect number of Arguments.\nUsage:\n%s", USE), 0);
	if (ft_atol(argv[1]) < 1)
		return (printf("You need at least 1 philosopher."), 0);
	while (args < argc)
	{
		num = ft_atol(argv[args]);
		if (!is_valid(argv[args]) || num <= 0 || num > INT_MAX)
			return (printf("Invalid arguments.Check your data."), 0);
		args++;
	}
	return (1);
}

int	init_philo(int argc, char **argv, t_data *data)
{
	if (!checker(argc, argv))
		return (0);
	else
	{
		init_data(argc, argv, data);
		printf("\n=== Stored Data Validation ===\n");
		printf("Number of philosophers: %d\n", data->num_philo);
		printf("Time to die (ms): %d\n", data->time_die);
		printf("Time to eat (ms): %d\n", data->time_eat);
		printf("Time to sleep (ms): %d\n", data->time_sleep);
		if (argc == 6)
			printf("Max meals: %d\n", data->max_meals);
		else
			printf("Max meals: unlimited (no count specified)\n");
		printf("=============================\n\n");
		return (1);
	}
}

    // // Debug print to verify stored data
    // printf("\n=== Stored Data Validation ===\n");
    // printf("Number of philosophers: %d\n", data->num_philos);
    // printf("Time to die (ms): %d\n", data->time_to_die);
    // printf("Time to eat (ms): %d\n", data->time_to_eat);
    // printf("Time to sleep (ms): %d\n", data->time_to_sleep);
    // if (argc == 6)
    //     printf("Max meals: %d\n", data->max_meals);
    // else
    //     printf("Max meals: unlimited (no count specified)\n");
    // printf("=============================\n\n");