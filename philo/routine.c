/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/02/24 16:54:08 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	ft_usleep(int t, t_table *table)
{
	while (t > 10000 && !is_died(table))
	{
		usleep(10000);
		t -= 10000;
	}
	if (t > 0 && !is_died(table))
		usleep(t);
}

void	philo_eat(t_philsopher *philo)
{
	if (is_died(philo->table))
		return ;
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
	ft_usleep(philo->table->eat_time * 1000, philo->table);
	set_last_eat(philo);
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

void	philo_sleep(t_philsopher *philo)
{
	if (is_died(philo->table))
		return ;
	print_message(philo, "is sleeping");
	ft_usleep(philo->table->sleep_time * 1000, philo->table);
	if (is_died(philo->table))
		return ;
	print_message(philo, "is thinking");
}

void	start(t_philsopher *philosopher, int round)
{

	philo_eat(philosopher);
	philo_sleep(philosopher);
	if (!is_died(philosopher->table) || (round >= philosopher->table->rounds && philosopher->table->rounds > 0))
		return (start(philosopher, round + 1));
}

void	*thread_routine(void *vd)
{
	start((t_philsopher *) vd, 0);
	return (NULL);
}
