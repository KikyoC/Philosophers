/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:49 by tom               #+#    #+#             */
/*   Updated: 2025/03/10 11:18:27 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_back(t_table *table, t_philosopher *to_add)
{
	t_philosopher	*current;

	current = table->first;
	if (!current)
	{
		table->first = to_add;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = to_add;
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
		return (destroy_philosopher(res));
	res->rounds_m = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!res->rounds_m)
		return (destroy_philosopher(res));
	pthread_mutex_init(res->rounds_m, NULL);
	pthread_mutex_init(res->last_eat_m, NULL);
	set_last_eat(res);
	res->id = id;
	res->left_id = id - 1;
	if (table->forks[id] == NULL)
		res->right_id = 0;
	else
		res->right_id = id;
	res->table = table;
	add_back(table, res);
	return (res);
}

int	start_threads(t_table *table)
{
	t_philosopher	*current;
	int				i;
	pthread_t		die_manager;

	current = table->first;
	i = 0;
	while (current)
	{
		if (pthread_create(&current->thread, NULL, thread_routine, current))
			return (0);
		i++;
		current = current->next;
	}
	pthread_create(&die_manager, NULL, die_routine, table);
	table->die_manager = die_manager;
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
