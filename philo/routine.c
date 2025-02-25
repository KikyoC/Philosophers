/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/02/25 11:44:04 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eat(t_philsopher *philo)
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
	usleep(philo->table->eat_time * 1000);
	set_last_eat(philo);
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

void	philo_sleep(t_philsopher *philo)
{
	if (is_died(philo->table))
		return ;
	print_message(philo, "is sleeping");
	usleep(philo->table->sleep_time * 1000);
	print_message(philo, "is thinking");
}

void	start(t_philsopher *philosopher, int round)
{

	while (!is_died(philosopher->table))
	{
		philo_eat(philosopher);
		philo_sleep(philosopher);
		round ++;
	}
}

void	*thread_routine(void *vd)
{
	start((t_philsopher *) vd, 0);
	return (NULL);
}
