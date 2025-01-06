/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:18 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 17:59:16 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	routine(t_table *table)
{
	t_philosopher	*current;
	int				i;

	current = table->first;
	i = 0;
	while (current)
	{
		if (i % 2)
			eat(current, 1);
		current = current->next;
		i++;
	}
}
