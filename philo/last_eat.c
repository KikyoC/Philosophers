/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:14:41 by togauthi          #+#    #+#             */
/*   Updated: 2025/02/25 16:43:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_last_eat(t_philosopher *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->last_eat_m);
	philo->last_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_unlock(philo->last_eat_m);
}

long	get_last_eat(t_philosopher *philo)
{
	long	res;

	pthread_mutex_lock(philo->last_eat_m);
	res = philo->last_eat;
	pthread_mutex_unlock(philo->last_eat_m);
	return (res);
}
