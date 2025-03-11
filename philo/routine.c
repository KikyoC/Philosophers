/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/03/11 10:05:04 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(int t, t_table *table)
{
	long			end_time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	end_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + t;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 < end_time && !is_died(table))
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->table->forks[philo->left_id]);
	if (is_died(philo->table))
	{
		pthread_mutex_unlock(philo->table->forks[philo->left_id]);
		return ;
	}
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->table->forks[philo->right_id]);
	if (is_died(philo->table))
	{
		pthread_mutex_unlock(philo->table->forks[philo->left_id]);
		pthread_mutex_unlock(philo->table->forks[philo->right_id]);
		return ;
	}
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	set_last_eat(philo);
	increment_eat(philo);
	ft_usleep(philo->table->eat_time, philo->table);
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

void	philo_sleep(t_philosopher *philo)
{
	if (is_died(philo->table))
		return ;
	print_message(philo, "is sleeping");
	ft_usleep(philo->table->sleep_time, philo->table);
	if (is_died(philo->table))
		return ;
	print_message(philo, "is thinking");
}

void	*alone_philo(t_philosopher *philo)
{
	pthread_mutex_lock(philo->table->forks[0]);
	print_message(philo, "has taken a fork");
	while (!is_died(philo->table))
		usleep(1000);
	pthread_mutex_unlock(philo->table->forks[0]);
	return (NULL);
}

void	*thread_routine(void *vd)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)vd;
	if (philo->left_id == philo->right_id)
		return (alone_philo(philo));
	if (philo->id % 2)
		usleep(100);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		if (is_died(philo->table))
			return (NULL);
	}
	return (NULL);
}
