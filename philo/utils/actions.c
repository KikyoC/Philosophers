/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 11:35:59 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

unsigned long	get_time(struct timeval tv, struct timeval start)
{
	return ((tv.tv_sec * 1000000 + tv.tv_usec / 1000)
		- (start.tv_sec * 1000000 + start.tv_usec / 1000));
}

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;

	pthread_mutex_lock(philosopher->left->mutex);
	gettimeofday(&tv, NULL);
	printf("%lu %i has taken a fork\n",
		get_time(tv, philosopher->table->tv),
		philosopher->id);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philosopher->right->mutex);
	printf("%lu %i has taken a fork\n",
		get_time(tv, philosopher->table->tv),
		philosopher->id);
	usleep(time * 1000);
	gettimeofday(&tv, NULL);
	printf("%lu %i is eating\n", get_time(tv,
			philosopher->table->tv),
		philosopher->id);
	pthread_mutex_unlock(philosopher->left->mutex);
	pthread_mutex_unlock(philosopher->right->mutex);
	return (NULL);
}
