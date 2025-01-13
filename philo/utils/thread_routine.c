/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:27:27 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 14:57:13 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <unistd.h>

void	start_loop(t_philosopher *philosopher, int round)
{
	eat(philosopher, 100);
	sleep_thread(philosopher, 100);
	think(philosopher, 100);
	if (round >= philosopher->table->rounds)
		return ;
	start_loop(philosopher, round + 1);
}

void	*thread_routine(void *vd)
{
	start_loop((t_philosopher *)vd, 0);
	return (NULL);
}
