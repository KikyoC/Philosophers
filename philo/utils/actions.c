/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/14 13:38:45 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	if (ft_lock(*philosopher->left->mutex, philosopher->table))
		return (NULL);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	gettimeofday(&tv, NULL);
	if (ft_lock(*philosopher->right->mutex, philosopher->table))
	{
		pthread_mutex_unlock(philosopher->left->mutex);
		return (NULL);
	}
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

	if (is_die_state(philosopher->table))
		return (NULL);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is sleeping",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	usleep(time * 1000);
	return (NULL);
}

void	*think(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	if (is_die_state(philosopher->table))
		return (NULL);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is thinking",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	usleep(time * 1000);
	return (NULL);
}
