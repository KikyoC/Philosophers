/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/02/25 15:03:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	wait_philo(int time, t_table *table)
{
	(void)table;
	// usleep(time * 1000);
	while (time > 20 && !is_died(table))	
	{
		usleep(20000);
		time-=20;
	}
	usleep(time * 1000);
}


void	philo_eat(t_philosopher *philo)
{
	//Take left fork
	pthread_mutex_lock(philo->table->forks[philo->left_id]);
	print_message(philo, "has taken a fork");
	//Take right fork
	pthread_mutex_lock(philo->table->forks[philo->right_id]);
	print_message(philo, "has taken a fork");
	//eat
	set_last_eat(philo);
	print_message(philo, "is eating");
	wait_philo(philo->table->eat_time, philo->table);
	set_last_eat(philo);
	//free forks
	pthread_mutex_unlock(philo->table->forks[philo->left_id]);
	pthread_mutex_unlock(philo->table->forks[philo->right_id]);
}

void	philo_sleep(t_philosopher *philo)
{
	print_message(philo, "is sleeping");
	wait_philo(philo->table->sleep_time, philo->table);
	print_message(philo, "is thinking");
}

void	*thread_routine(void *vd)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)vd;
	set_last_eat(philo);
	if (philo->id % 2 != 0)
	{
		usleep(5000);
		set_last_eat(philo);
	}
	while (!is_died(philo->table))
	{
		//Do the routine
		philo_eat(philo);
		philo_sleep(philo);
	}
	return (NULL);
}

