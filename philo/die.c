/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:34:52 by togauthi          #+#    #+#             */
/*   Updated: 2025/02/25 11:46:56 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

void	set_died(t_table *table)
{
	t_philsopher	*current;

	pthread_mutex_lock(table->die);
	table->someone_died = 1;
	pthread_mutex_unlock(table->die);
	current = table->first;
	while (current)
	{
		pthread_detach(current->thread);
		current = current->next;
	}
}

int	is_died(t_table *table)
{
	int	res;
	pthread_mutex_lock(table->die);
	res = table->someone_died;
	pthread_mutex_unlock(table->die);
	return (res);
}
