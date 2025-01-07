/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/07 17:57:00 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	struct timeval	tv;
	pthread_mutex_lock(philosopher->left->mutex);
	gettimeofday(&tv, NULL);
	ft_print("has taken a fork", tv, philosopher->id, philosopher->table->tv);
	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philosopher->right->mutex);
	ft_print("has taken a fork", tv, philosopher->id, philosopher->table->tv);
	gettimeofday(&tv, NULL);
	ft_print("is eating", tv, philosopher->id, philosopher->table->tv);
	usleep(100);
	(void)time;
	pthread_mutex_unlock(philosopher->left->mutex);
	pthread_mutex_unlock(philosopher->right->mutex);
	return (NULL);
}
