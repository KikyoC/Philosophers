/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:46:33 by tom               #+#    #+#             */
/*   Updated: 2025/02/24 16:32:16 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	to_int(char *c)
{
	char	*str;
	int		res;
	int		len;

	len = 0;
	while (c[len])
		len++;
	res = ft_atoi(c);
	str = ft_itoa(res);
	if (!str)
	{
		write(2, "Allocation error\n", 17);
		return (0);
	}
	if (ft_strncmp(c, str, len) || res <= 0)
	{
		write(2, "Parameter not good\n", 19);
		return (0);
	}
	free(str);
	return (res);
}

int	parse(int argc, char **argv, t_table *table)
{
	if (argc < 5)
	{
		write(2, "Not enough arguments\n", 21);
		return (0);
	}
	table->count = to_int(argv[1]);
	table->die_time = to_int(argv[2]);
	table->eat_time = to_int(argv[3]);
	table->sleep_time = to_int(argv[4]);
	if (argc == 6)
		table->rounds = to_int(argv[5]);
	else
		table->rounds = -1;
	return (table->die_time
		&& table->rounds
		&& table->sleep_time
		&& table->eat_time);
}
