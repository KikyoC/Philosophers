/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:27:27 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/15 09:09:29 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	start_loop(t_philosopher *philosopher, int round)
{
	if (round >= philosopher->table->rounds && philosopher->table->rounds > 0)
	{
		set_philosoph_end(philosopher);
		return ;
	}
	printf("Philosopher #%i is starting round %i\n", philosopher->id, round);
	eat(philosopher, philosopher->table->eat_time);
	sleep_thread(philosopher, philosopher->table->sleep_time);
	if (is_die_state(philosopher->table))
		return ;
	start_loop(philosopher, round + 1);
}

void	*thread_routine(void *vd)
{
	start_loop((t_philosopher *)vd, 0);
	return (NULL);
}
