/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:33:46 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 13:18:27 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_table *table)
{
	t_philsopher	*current;

	current = table->first;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
}

void	printf_table(t_table *table)
{
	t_philsopher	*current;

	current = table->first;
	while (current)
	{
		printf("Philosopher #%i:\n  - %i\n  - %i\n",
			current->id, current->left_id, current->right_id);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!parse(argc, argv, &table))
		return (1);
	create_table(&table);
	join_threads(&table);
	destroy_table(&table);
}
