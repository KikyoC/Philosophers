/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 17:16:37 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_table(t_table *table)
{
	t_element	*current;

	current = table->first;
	if (!current)
		printf("Current does not exists\n");
	while (current)
	{
		printf("%s\n", current->type ? "Fork" : "Philosopher");
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_table			table;

	(void) argc;
	(void) argv;
	create_table(&table, 5);
	print_table(&table);
	destroy(&table);
	return (1);
}
