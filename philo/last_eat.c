/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:14:41 by togauthi          #+#    #+#             */
/*   Updated: 2025/03/11 10:05:13 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	increment_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->rounds_m);
	philo->rounds++;
	pthread_mutex_unlock(philo->rounds_m);
}

void	set_last_eat(t_philosopher *philo)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	pthread_mutex_lock(philo->last_eat_m);
	philo->last_eat = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	pthread_mutex_unlock(philo->last_eat_m);
}

int	is_full_eat(t_philosopher *philo)
{
	int	res;

	pthread_mutex_lock(philo->rounds_m);
	res = philo->rounds;
	pthread_mutex_unlock(philo->rounds_m);
	return (philo->table->rounds > 0 && res >= philo->table->rounds);
}

int	all_full_eat(t_table *table)
{
	t_philosopher	*current;

	current = table->first;
	while (current)
	{
		if (!is_full_eat(current))
			return (0);
		current = current->next;
	}
	return (1);
}

long	get_last_eat(t_philosopher *philo)
{
	long			res;

	pthread_mutex_lock(philo->last_eat_m);
	res = philo->last_eat;
	pthread_mutex_unlock(philo->last_eat_m);
	return (res);
}
