/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:34:30 by tom               #+#    #+#             */
/*   Updated: 2025/02/24 16:23:20 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	destroy_forks(pthread_mutex_t **forks)
{
	int	i;

	i = 0;
	if (!forks)
		return ;
	while (forks[i])
	{
		pthread_mutex_destroy(forks[i]);
		free(forks[i]);
		i++;
	}
	free(forks);
}

void	destroy_philosopher(t_philsopher *philo)
{
	if (philo->last_eat_m)
	{
		pthread_mutex_destroy(philo->last_eat_m);
		free(philo->last_eat_m);
	}
	free(philo);
}

void	destroy_table(t_table *table)
{
	t_philsopher	*current;
	t_philsopher	*next;

	current = table->first;
	while (current)
	{
		next = current->next;
		destroy_philosopher(current);
		current = next;
	}
	if (table->print)
		free(table->print);
	if (table->die)
	{
		pthread_mutex_destroy(table->die);
		free(table->die);
	}
	destroy_forks(table->forks);
}
