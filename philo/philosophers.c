/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 17:59:58 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
	// pthread_t		thread;	

	(void) argc;
	(void) argv;
	create_table(&table, 15);
	// pthread_create(&thread, NULL, &routine, NULL);
	// pthread_join(thread, NULL);
	// pthread_detach(thread);
	// pthread_mutex_lock((&table)->first->next->next->left);
	// printf("Locked\n");
	// check_table(&table);
	routine(&table);
	destroy(&table);
	return (1);
}
