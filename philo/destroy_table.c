/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:04 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:56 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*free_forks(pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	return (NULL);
}


void	*destroy(t_table *table)
{
	t_philosopher	*current;
	t_philosopher	*next;
	int	i;

	i = 0;
	current = table->first;
	while (current)
	{
		pthread_mutex_destroy(current->left->mutex);
		free(current->left);
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	free(table->forks);
	return (NULL);
}
