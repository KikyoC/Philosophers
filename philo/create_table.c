/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:35:05 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 17:15:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	add_back(t_table *table, t_element *element)
{
	t_element	*current;

	current = table->first;
	if (!current)
	{
		table->first = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}

void	assign_values(t_table *table)
{
	t_element	*current;

	current = table->first;
	while (current)
	{
		if (current->type)
			pthread_mutex_init(current->value, NULL);
		// else: create thread
		current = current->next;
	}
}

void	create_table(t_table *table, int count)
{
	int			i;
	t_element	*current;

	i = 0;
	table->first = NULL;
	count *= 2;
	while (i < count)
	{
		current = malloc(sizeof(t_element));
		if (!current)
		{
			destroy(table);
			return ;
		}
		current->next = NULL;
		current->previous = NULL;
		current->type = i % 2 == 0;
		current->value = NULL;
		add_back(table, current);
		i++;
	}
}
