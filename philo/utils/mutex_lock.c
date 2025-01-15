/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:43:50 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 09:38:37 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_lock(pthread_mutex_t *mutex, t_table *table)
{
	printf("Trying to lock %p\n", mutex);
	if (is_die_state(table))
		return (1);
	pthread_mutex_lock(mutex);
	printf("Locked %p\n", mutex);
	return (0);
}
