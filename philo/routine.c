/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:18 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 16:11:49 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <unistd.h>

void	*routine(t_table *table, int b)
{
	t_philosopher	*current;
	int				count;

	current = table->first;
	count = 0;
	while (current)
	{
		if (count % 2 == b && pthread_create(
				&current->thread, NULL, &thread_routine, current) != 0)
			return (destroy(table));
		current = current->next;
		count ++;
	}
	if (b == 0)
	{
		usleep(1000);
		routine(table, 1);
	}
	return (NULL);
}

void	*dead_routine(void *vd)
{
	t_table			*table;
	t_philosopher	*current;
	struct timeval	tv;

	table = (t_table *)vd;
	usleep(5000);
	current = table->first;
	gettimeofday(&tv, NULL);
	while (current)
	{
		if (ft_diff(tv, get_last_eat(current)) > 10)
		{
			set_die_state(table);
			break ;
		}
		current = current->next;
		usleep(5000);
	}
	return (NULL);
}
