/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:59:01 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 09:33:59 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	set_die_state(t_table *table)
{
	pthread_mutex_lock(&table->die);
	table->is_dead = 1;
	pthread_mutex_unlock(&table->die);
}

int	is_die_state(t_table *table)
{
	int	res;

	pthread_mutex_lock(&table->die);
	res = table->is_dead;
	pthread_mutex_unlock(&table->die);
	return (res);
}
