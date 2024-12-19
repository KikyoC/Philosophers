/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 17:16:55 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_element
{
	struct s_element	*previous;	
	struct s_element	*next;
	int					type;
	void				*value;

}	t_element;

typedef struct s_table
{
	struct s_element	*first;
	int					eat_time;
	int					sleep_time;
	int					die_time;
}	t_table;

int		ft_atoi(const char *nptr);
void	*destroy_philosophers(t_element **philosophers);
void	*destroy_forks(t_element **forks);
void	create_table(t_table *table, int count);
void	*destroy(t_table *table);
#endif
