/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:35:05 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/07 17:51:21 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	philosopher->table = table;
	if (pthread_create(&philosopher->thread, NULL, &thread_routine, philosopher) != 0)
	{
		free(fork);
		return (NULL);
	}
	philosopher->left = fork;
	philosopher->previous = NULL;
	philosopher->next = NULL;
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
	if (!table->forks)
		return (NULL);
	gettimeofday(&table->tv, NULL);
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
