/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:22:39 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/07 17:57:22 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	ft_print(char *str, struct timeval tv, int id, struct timeval sim_start)
{
	printf("%ld %i %s\n", (tv.tv_sec * 1000000 + tv.tv_usec / 1000) - (sim_start.tv_sec * 1000000 + sim_start.tv_usec / 1000) , id, str);
}
