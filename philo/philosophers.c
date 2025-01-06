/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 13:23:40 by togauthi         ###   ########.fr       */
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
		if (current == table->first)
			break ;
	}
}

void	*routine()
{
	sleep(1);
	printf("Slept 1 sec\n");
	return (NULL);
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
	check_table(&table);
	destroy(&table);
	return (1);
}
