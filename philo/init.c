/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:05:49 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 13:15:40 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_back(t_table *table, t_philsopher *to_add)
{
	t_philsopher	*current;

	current = table->first;
	if (!current)
	{
		table->first = to_add;
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
	}
	return (res);
}

t_philsopher	*create_philosopher(int id)
{
	t_philsopher	*res;

	res = ft_calloc(1, sizeof(t_philsopher));
	if (!res)
		return (NULL);
	res->id = id;
	res->left_id = id - 1;
	if (pthread_create(&res->thread, NULL, &thread_routine, res))
	{
		free(res);
		return (NULL);
	}
	return (res);
}

int	create_table(t_table *table)
{
	int				i;
	t_philsopher	*current;

	i = 0;
	table->first = NULL;
	while (i < table->count)
	{
		current = create_philosopher(i + 1);
		if (!current)
			return (0);
		add_back(table, current);
		i++;
	}
	return (1);
}
