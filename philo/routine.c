/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/03/10 10:04:10 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    ft_usleep(int t, t_table *table)
{
	long			end_time;
	struct timeval	tv;

	// usleep(t * 1000);
	// return ;
	gettimeofday(&tv, NULL);
	end_time = (tv.tv_sec * 1000 + tv.tv_usec / 1000) + t;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 < end_time && !is_died(table))
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
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
	set_last_eat(philo);
	increment_eat(philo);
	print_message(philo, "start eat");
	ft_usleep(philo->table->eat_time, philo->table);
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

// void	philo_eat(t_philsopher *philo)
// {
// 	pthread_mutex_lock(philo->table->forks[philo->left_id]);
// 	print_message(philo, "has taken a fork");
// 	pthread_mutex_lock(philo->table->forks[philo->right_id]);
// 	print_message(philo, "has taken a fork");
// 	set_last_eat(philo);
// 	increment_eat(philo);
// 	print_message(philo, "is eating");
// 	ft_usleep(philo->table->eat_time, philo->table);
// 	print_message(philo, "ate");
// 	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
// 	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
// }

void	philo_sleep(t_philsopher *philo)
{
	if (is_died(philo->table))
		return ;
	print_message(philo, "is sleeping");
	ft_usleep(philo->table->sleep_time, philo->table);
	if (is_died(philo->table))
		return ;
	print_message(philo, "is thinking");
}

void	*thread_routine(void *vd)
{
	t_philsopher	*philo;
	int				round;

	round = 0;
	philo = (t_philsopher *)vd;
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		if (is_died(philo->table))
			return (NULL);
		round ++;
	}
	return (NULL);
}
