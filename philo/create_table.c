/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:35:05 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 16:59:13 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	add_back(t_table *table, t_philosopher *philosopher)
{
	t_philosopher	*current;

	current = table->first;
	if (!current)
	{
		table->first = philosopher;
		philosopher->previous = NULL;
		philosopher->right = NULL;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = philosopher;
	philosopher->previous = current;
	current->right = philosopher->left;
	philosopher->right = table->first->left;
}

t_philosopher	*assign_philosopher(t_philosopher *philosopher, t_table *table)
{
	t_fork	*fork;

	fork = ft_calloc(1, sizeof(t_fork));
	fork->mutex = &table->forks[philosopher->id - 1];
	fork->id = philosopher->id;
	philosopher->left = fork;
	philosopher->table = table;
	philosopher->previous = NULL;
	philosopher->next = NULL;
	if (pthread_mutex_init(&philosopher->eat, NULL) != 0)
	{
		pthread_mutex_destroy(fork->mutex);
		free(fork);
		return (NULL);
	}
	return (philosopher);
}

pthread_mutex_t	*get_forks(int count)
{
	pthread_mutex_t	*res;
	int				i;

	res = ft_calloc(count + 1, sizeof(pthread_mutex_t));
	if (!res)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&res[i], NULL) != 0)
			return (free_forks(res, i));
		i++;
	}
	return (res);
}

t_table	*create_table(t_table *table, int count)
{
	int				i;
	t_philosopher	*philosopher;

	i = 0;
	table->first = NULL;
	table->forks = get_forks(count);
	table->rounds = 10;
	if (!table->forks)
		return (NULL);
	gettimeofday(&table->tv, NULL);
	if (pthread_mutex_init(&table->write, NULL) != 0)
		return (destroy(table));
	while (i < count)
	{
		philosopher = ft_calloc(1, sizeof(t_philosopher));
		if (!philosopher)
			return (destroy(table));
		philosopher->id = i + 1;
		philosopher = assign_philosopher(philosopher, table);
		if (!philosopher)
			return (destroy(table));
		add_back(table, philosopher);
		i++;
	}
	return (table);
}
