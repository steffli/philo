/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stephan <stephan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:50:53 by stephan           #+#    #+#             */
/*   Updated: 2025/07/22 15:38:57 by stephan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!(init_philo(argc, argv, &data)))
		exit(EXIT_FAILURE);
	// if (init_thread(&data))
	// 	return (1);
	exit(EXIT_SUCCESS);
	return (0);
}