/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 13:38:00 by tom              ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_table			table;
	t_philosopher	*current;

	(void) argc;
	(void) argv;
	create_table(&table, 14);
	routine(&table, 0);
	current = table.first;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
	destroy(&table);
	return (1);
}
