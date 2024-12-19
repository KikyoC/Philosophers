/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:06:30 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 14:29:23 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc < 4)
		return (0);
	table.die_time = ft_atoi(argv[1]);
	table.eat_time = ft_atoi(argv[2]);
	table.sleep_time = ft_atoi(argv[3]);
	printf("%d, %d, %d", table.die_time, table.eat_time, table.sleep_time);
	return (1);
}
