/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_lock.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:43:50 by tom               #+#    #+#             */
/*   Updated: 2025/01/14 12:47:27 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	ft_lock(pthread_mutex_t mutex, t_table *table)
{
	if (is_die_state(table))
		return (1);
	pthread_mutex_lock(&mutex);
	return (0);
}
