/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/15 09:37:32 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

void	join_threads(t_table *table)
{
	t_philosopher	*current;

	current = table->first;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
	pthread_join(table->dead_checker, NULL);
}

int	main(int argc, char **argv)
{
	t_table			table;

	if (!parse(argc, argv, &table))
		return (1);
	table.is_dead = 0;
	if (pthread_mutex_init(&table.die, NULL) != 0)
		return (1);
	create_table(&table, table.count);
	printf("Locks:\n - %p\n", &table.write);
	routine(&table, 0);
	pthread_create(&table.dead_checker, NULL, &dead_routine, &table);
	join_threads(&table);
	destroy(&table);
	return (1);
}
