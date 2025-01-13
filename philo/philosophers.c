/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 16:45:53 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	check_table(t_table *table)
{
	t_philosopher	*current;

	current = table->first;
	if (!current)
		printf("Current does not exists\n");
	while (current)
	{
		printf("Philosopher #%i\n", current->id);
		current = current->next;
	}
}

int	create_die_thread(t_table *table)
{
	table->is_dead = 0;
	if (pthread_mutex_init(&table->die, NULL) != 0)
		return (1);
	if (pthread_create(&table->dead_checker, NULL, &dead_routine, &table) != 0)
	{
		pthread_mutex_destroy(&table->die);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_table			table;
	t_philosopher	*current;

	(void) argc;
	(void) argv;
	if (pthread_mutex_init(&table.die, NULL) != 0)
		return (1);
	create_table(&table, 14);
	routine(&table, 0);
	// pthread_create(&table.dead_checker, NULL, &dead_routine, &table);
	current = table.first;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
	destroy(&table);
	return (1);
}
