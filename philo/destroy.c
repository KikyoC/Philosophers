/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:34:30 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 13:17:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_table(t_table *table)
{
	t_philsopher	*current;
	t_philsopher	*next;

	current = table->first;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
