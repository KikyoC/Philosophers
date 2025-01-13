/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 15:50:20 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <bits/types/struct_timeval.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	pthread_mutex_lock(philosopher->left->mutex);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philosopher->right->mutex);
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is eating",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	usleep(time * 1000);
	set_last_eat_now(philosopher);
	pthread_mutex_unlock(philosopher->left->mutex);
	pthread_mutex_unlock(philosopher->right->mutex);
	return (NULL);
}

void	*sleep_thread(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is sleeping",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	usleep(time * 1000);
	return (NULL);
}

void	*think(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is thinking",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	usleep(time * 1000);
	return (NULL);
}
