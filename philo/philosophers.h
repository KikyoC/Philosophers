/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:16 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/06 17:58:45 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philosopher
{
	struct s_philosopher	*previous;
	struct s_philosopher	*next;
	pthread_mutex_t			*left;
	pthread_mutex_t			*right;
	int						id;
	pthread_t				thread;
	
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*first;
	pthread_mutex_t			*forks;
	int						eat_time;
	int						sleep_time;
	int						die_time;
}	t_table;

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
t_table	*create_table(t_table *table, int count);
void	*destroy(t_table *table);
void	*free_forks(pthread_mutex_t *forks, int count);
void	*eat(t_philosopher *philosopher, unsigned int time);
void	routine(t_table *table);
#endif
