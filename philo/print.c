/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:40:12 by togauthi          #+#    #+#             */
/*   Updated: 2025/02/25 16:43:06 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(t_philosopher *philo, char *str)
{
	struct timeval	tv;
	int				time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) - philo->table->start_time;
	pthread_mutex_lock(philo->table->print);
	printf("%i #%i %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->table->print);
}
