/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:31:18 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/14 14:05:12 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

void	*routine(t_table *table, int b)
{
	t_philosopher	*current;
	struct timeval	tv;
	int				count;

	current = table->first;
	count = 0;
	gettimeofday(&tv, NULL);
	while (current)
	{
		if (count % 2 == b)
			current->last_eat = tv;
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
	int				end;

	table = (t_table *)vd;
	end = 0;
	current = table->first;
	gettimeofday(&tv, NULL);
	while (current)
	{
		// printf("Diff is %li\n", ft_diff(tv, get_last_eat(current)));
		if (ft_diff(tv, get_last_eat(current)) > table->die_time)
		{
			ft_log(table, "died", ft_diff(tv, current->table->tv), current->id);
			set_die_state(table);
			end = 1;
			break;
		}
		current = current->next;
		usleep(10);
	}
	if (!end)
		return (dead_routine(vd));
	return (NULL);
}
