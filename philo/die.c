/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:34:52 by togauthi          #+#    #+#             */
/*   Updated: 2025/02/24 15:04:18 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_died(t_table *table)
{
	pthread_mutex_lock(table->die);
	table->someone_died = 1;
	pthread_mutex_unlock(table->die);
}

int	is_died(t_table *table)
{
	int	res;
	pthread_mutex_lock(table->die);
	res = table->someone_died;
	pthread_mutex_unlock(table->die);
	return (res);
}
