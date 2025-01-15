/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/15 09:35:02 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <sys/time.h>

int	lock(t_philosopher *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "try to get left fork", ft_diff(tv, philosopher->table->tv), philosopher->id);
	if (ft_lock(philosopher->left->mutex, philosopher->table))
		return (1);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "try to get right fork", ft_diff(tv, philosopher->table->tv), philosopher->id);
	if (ft_lock(philosopher->right->mutex, philosopher->table))
	{
		pthread_mutex_unlock(philosopher->left->mutex);
		return (1);
	}
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	return (0);
}

int	lockk(t_philosopher *philosopher)
{
	struct timeval	tv;

	if (ft_lock(philosopher->left->mutex, philosopher->table))
		return (1);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	gettimeofday(&tv, NULL);
	if (ft_lock(philosopher->right->mutex, philosopher->table))
	{
		pthread_mutex_unlock(philosopher->left->mutex);
		return (1);
	}
	ft_log(philosopher->table, "has taken a fork",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	return (0);
}

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	if (lock(philosopher))
		return (NULL);
	gettimeofday(&tv, NULL);
	ft_log(philosopher->table, "is eating",
		ft_diff(tv, philosopher->table->tv), philosopher->id);
	ft_usleep(time);
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
	ft_usleep(time);
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
