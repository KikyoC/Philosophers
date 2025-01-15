/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:00:05 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 09:33:47 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>

void	ft_log(t_table *table, char *str, unsigned long ts, int philosopher)
{
	if (is_die_state(table))
		return ;
	pthread_mutex_lock(&table->write);
	printf("%lu %i %s\n", ts, philosopher, str);
	pthread_mutex_unlock(&table->write);
}
