/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:38:40 by tom               #+#    #+#             */
/*   Updated: 2025/01/13 15:55:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <sys/time.h>

void	set_last_eat_now(t_philosopher *philosopher)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(&philosopher->eat);
	philosopher->last_eat = tv;
	pthread_mutex_unlock(&philosopher->eat);
}

struct timeval	get_last_eat(t_philosopher *philosopher)
{
	struct timeval	res;

	pthread_mutex_lock(&philosopher->eat);
	res = philosopher->last_eat;
	pthread_mutex_unlock(&philosopher->eat);
	return (res);
}

