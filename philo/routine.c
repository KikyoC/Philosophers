/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/02/28 14:51:11 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>
#include <unistd.h>

void    ft_usleep(int t, t_table *table)
{
	long			end_time;
	struct timeval	tv;

	usleep(t * 1000);
	return ;
	gettimeofday(&tv, NULL);
	end_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + t;
	(void)table;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 < end_time && !is_died(table))
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
}

// void	philo_eat(t_philsopher *philo)
// {
// 	if (is_died(philo->table))
// 		return ;
// 	pthread_mutex_lock(philo->table->forks[philo->left_id]);
// 	if (is_died(philo->table))
// 	{
// 		pthread_mutex_unlock(philo->table->forks[philo->left_id]);
// 		return ;
// 	}
// 	print_message(philo, "has taken a fork");
// 	pthread_mutex_lock(philo->table->forks[philo->right_id]);
// 	if (is_died(philo->table))
// 	{
// 		pthread_mutex_unlock(philo->table->forks[philo->left_id]);
// 		pthread_mutex_unlock(philo->table->forks[philo->right_id]);
// 		return ;
// 	}
// 	print_message(philo, "has taken a fork");
// 	print_message(philo, "is eating");
// 	set_last_eat(philo);
// 	increment_eat(philo);
// 	print_message(philo, "Start eat process");
// 	ft_usleep(philo->table->eat_time, philo->table);
// 	print_message(philo, "Finished eat process");
// 	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
// 	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
// }

void	philo_eat(t_philsopher *philo)
{
	pthread_mutex_lock(philo->table->forks[philo->left_id]);
	print_message(philo, "has taken a fork");
	pthread_mutex_lock(philo->table->forks[philo->right_id]);
	print_message(philo, "has taken a fork");
	set_last_eat(philo);
	increment_eat(philo);
	print_message(philo, "is eating");
	usleep(100000);
	print_message(philo, "ate");
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

void	philo_sleep(t_philsopher *philo)
{
	print_message(philo, "is sleeping");
	if (is_died(philo->table))
		return ;
	ft_usleep(philo->table->sleep_time, philo->table);
	if (is_died(philo->table))
		return ;
	print_message(philo, "is thinking");
}

void	start(t_philsopher *philosopher, int round)
{

	philo_eat(philosopher);
	philo_sleep(philosopher);
	if (all_full_eat(philosopher->table))
		return ;
	if (!is_died(philosopher->table))
		return (start(philosopher, round + 1));
}

void	*thread_routine(void *vd)
{
	t_philsopher	*philo;

	philo = (t_philsopher *)vd;
	print_message(philo, "started");
	start(philo, 0);
	return (NULL);
}
