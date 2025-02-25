/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:33:46 by tom               #+#    #+#             */
/*   Updated: 2025/02/25 15:02:17 by togauthi         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_table		table;
	pthread_t	die_checker;

	if (!parse(argc, argv, &table))
		return (1);
	create_table(&table);
	usleep(1000);
	pthread_create(&die_checker, NULL, die_routine, &table);
	join_threads(&table);
	destroy_table(&table);
}
