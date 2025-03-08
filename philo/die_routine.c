/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:34:49 by togauthi          #+#    #+#             */
/*   Updated: 2025/02/28 16:27:55 by togauthi         ###   ########.fr       */
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
	while (current && !is_died(table))
	{
		gettimeofday(&tv, NULL);
		if ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - get_last_eat(current) > table->die_time)
		{
			print_message(current, "died");
			set_died(table);
			return (NULL);
		}
		current = current->next;
	}
	if (!is_died(table))
	{
		usleep(1000);
		return (die_routine(vd));
	}
	return (NULL);
}
