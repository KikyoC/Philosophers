/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:04 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 17:15:33 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*destroy(t_table *table)
{
	t_element	*current;
	t_element	*next;

	current = table->first;
	while (current)
	{
		if (current->type && current->value)
			pthread_mutex_destroy(current->value);
		else if (!current->type && current->value)
			pthread_exit(current->value);
		next = current->next;
		free(current);
		current = next;
	}
	return (NULL);
}
