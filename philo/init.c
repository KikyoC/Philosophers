/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:49 by tom               #+#    #+#             */
/*   Updated: 2025/02/25 14:53:09 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	add_back(t_table *table, t_philosopher *to_add)
{
	t_philosopher	*current;

	current = table->first;
	if (!current)
	{
		table->first = to_add;
		to_add->right_id = 1;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = to_add;
	current->right_id = to_add->left_id;
}

pthread_mutex_t	**get_forks(t_table *table)
{
	pthread_mutex_t	**res;
	int				i;

	res = ft_calloc(table->count + 1, sizeof(pthread_mutex_t *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < table->count)
	{
		res[i] = ft_calloc(1, sizeof(pthread_mutex_t));
		if (!res[i])
		{
			while (--i > 0)
				free(res[i]);
			return (NULL);
		}
		pthread_mutex_init(res[i], NULL);
		i++;
	}
	return (res);
}

t_philosopher	*create_philosopher(int id, t_table *table)
{
	t_philosopher	*res;

	res = ft_calloc(1, sizeof(t_philosopher));
	if (!res)
		return (NULL);
	res->last_eat_m = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->last_eat_m)
	{
		free(res);
		return (NULL);
	}
	pthread_mutex_init(res->last_eat_m, NULL);
	res->id = id;
	res->left_id = id - 1;
	res->table = table;
	add_back(table, res);
	return (res);
}

int start_threads(t_table *table)
{
	t_philosopher	*current;
	int				i;

	current = table->first;
	i = 0;
	while (current)
	{
		if (pthread_create(&current->thread, NULL, thread_routine, current))
			return (0);
		i++;
		current = current->next;
	}
	return (1);
}

int	create_table(t_table *table)
{
	int				i;
	struct timeval	tv;

	i = 0;
	gettimeofday(&tv, NULL);
	table->first = NULL;
	table->forks = get_forks(table);
	table->print = ft_calloc(1, sizeof(pthread_mutex_t));
	table->die = ft_calloc(1, sizeof(pthread_mutex_t));
	table->someone_died = 0;
	if (table->print)
		pthread_mutex_init(table->print, NULL);
	if (table->die)
		pthread_mutex_init(table->die, NULL);
	table->start_time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (i < table->count)
	{
		if (!create_philosopher(i + 1, table))
			return (0);
		i++;
	}
	start_threads(table);
	return (1);
}
