/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:33:46 by tom               #+#    #+#             */
/*   Updated: 2025/03/10 11:23:27 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_threads(t_table *table)
{
	t_philosopher	*current;

	current = table->first;
	while (current)
	{
		pthread_join(current->thread, NULL);
		current = current->next;
	}
	pthread_join(table->die_manager, NULL);
}

int	main(int argc, char **argv)
{
	t_table		table;

	if (!parse(argc, argv, &table))
		return (1);
	create_table(&table);
	join_threads(&table);
	destroy_table(&table);
}
