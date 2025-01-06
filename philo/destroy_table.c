/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:39:04 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 12:54:28 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*destroy(t_table *table)
{
	t_philosopher	*current;
	t_philosopher	*next;
	int	i;

	i = 0;
	current = table->first;
	while (current)
	{
		pthread_mutex_destroy(&current->left);
		next = current->next;
		free(current);
		current = next;
		i++;
	}
	return (NULL);
}
