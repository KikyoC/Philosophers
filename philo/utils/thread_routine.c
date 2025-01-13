/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 10:27:27 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 11:31:45 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*thread_routine(void *vd)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)vd;
	eat(philosopher, 100);
	return (NULL);
}
