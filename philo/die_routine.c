/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:34:49 by togauthi          #+#    #+#             */
/*   Updated: 2025/03/10 16:23:12 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*die_routine(void *vd)
{
	t_table			*table;
	t_philosopher	*current;
	struct timeval	tv;

	table = (t_table *) vd;
	current = table->first;
	while (!is_died(table))
	{
		usleep(100);
		if (!current)
			current = table->first;
		gettimeofday(&tv, NULL);
		if ((tv.tv_sec * 1000 + tv.tv_usec / 1000)
			- get_last_eat(current) > table->die_time)
		{
			print_message(current, "died");
			set_died(table);
			return (NULL);
		}
		if (all_full_eat(table))
			set_died(table);
		current = current->next;
	}
	return (NULL);
}
