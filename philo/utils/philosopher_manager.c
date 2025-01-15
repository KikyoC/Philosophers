/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:03:54 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 10:12:52 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	set_philosoph_end(t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->end_m);
	philosopher->end = 1;
	pthread_mutex_unlock(&philosopher->end_m);
}

int	is_philosopher_end(t_philosopher *philosopher)
{
    int	res;

    pthread_mutex_lock(&philosopher->end_m);
    res = philosopher->end;
    printf("Philosopher %d end state: %d\n", philosopher->id, res);
    pthread_mutex_unlock(&philosopher->end_m);
    return (res);
}
