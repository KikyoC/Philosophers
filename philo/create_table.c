/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:35:05 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 13:22:06 by togauthi         ###   ########.fr       */
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
		philosopher->right = philosopher->left;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = philosopher;
	philosopher->previous = current;
	current->right = philosopher->left;
	philosopher->right = table->first->left;
}

t_philosopher	*assign_philosopher(t_philosopher *philosopher)
{
	pthread_mutex_t lock;

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		free(philosopher);
		return (NULL);
	}
	philosopher->left = lock;
	philosopher->previous = NULL;
	philosopher->next = NULL;
	return (philosopher);
}

t_table	*create_table(t_table *table, int count)
{
	int				i;
	t_philosopher	*philosopher;

	i = 0;
	table->first = NULL;
	while (i < count)
	{
		philosopher = ft_calloc(1, sizeof(t_philosopher));
		if (!philosopher)
			return (destroy(table));
		philosopher = assign_philosopher(philosopher);
		if (!philosopher)
			return (destroy(table));
		add_back(table, philosopher);
		philosopher->id = i;
		i++;
	}
	return (table);
}
