/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:16 by togauthi          #+#    #+#             */
/*   Updated: 2024/12/19 12:59:18 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
// # include <string.h>
# include <pthread.h>

typedef struct	s_philosopher
{
	struct s_fork	*previous;	
	struct s_fork	*next;	
}	t_philosopher;

typedef struct	s_fork
{
	struct s_philosopher	*previous;	
	struct s_philosopher	*next;
}	t_fork;

typedef struct	s_table
{
	struct s_philosopher	*first;
	int						eat_time;
	int						sleep_time;
} 	t_table;

#endif