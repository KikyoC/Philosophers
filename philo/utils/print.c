/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:00:05 by tom               #+#    #+#             */
/*   Updated: 2025/01/13 13:22:38 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>

void	ft_log(t_table *table, char *str, unsigned long ts, int philosopher)
{
	(void)table;
	pthread_mutex_lock(&table->write);
	printf("%lu %i %s\n", ts, philosopher, str);
	pthread_mutex_unlock(&table->write);

}
