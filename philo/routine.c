/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:26:30 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 13:15:50 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*thread_routine(void *vd)
{
	t_philsopher	*philosopher;

	philosopher = (t_philsopher *)vd;
	printf("Hello I'm philosopher #%i\n", philosopher->id);
	return (NULL);
}
