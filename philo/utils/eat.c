/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:49:48 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 17:59:43 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*eat(t_philosopher *philosopher, unsigned int time)
{
	pthread_mutex_lock(philosopher->left);
	printf("Here");
	pthread_mutex_lock(philosopher->right);
	printf("Philosopher #%i is now eating\n", philosopher->id);
	usleep(time);
	pthread_mutex_unlock(philosopher->left);
	pthread_mutex_unlock(philosopher->right);
	printf("Philosopher #%i ate\n", philosopher->id);
	return (NULL);
}
