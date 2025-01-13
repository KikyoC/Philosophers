/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:18 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 13:32:10 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(t_table *table, int b)
{
	t_philosopher	*current;
	int				count;

	current = table->first;
	count = 0;
	while (current)
	{
		if (count % 2 == b && pthread_create(
				&current->thread, NULL, &thread_routine, current) != 0)
			return (destroy(table));
		current = current->next;
		count ++;
	}
	if (b == 0)
	{
		usleep(1000);
		routine(table, 1);
	}
	return (NULL);
}
