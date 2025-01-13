/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:16 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 14:27:50 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_fork
{
	int						id;
	pthread_mutex_t			*mutex;
}	t_fork;

typedef struct s_philosopher
{
	struct s_philosopher	*previous;
	struct s_philosopher	*next;
	struct s_fork			*left;
	struct s_fork			*right;
	int						id;
	struct s_table			*table;
	pthread_t				thread;
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*first;
	pthread_mutex_t			*forks;
	int						eat_time;
	int						sleep_time;
	int						die_time;
	int						rounds;
	struct timeval			tv;
	pthread_mutex_t			write;
}	t_table;

int		ft_atoi(const char *nptr);
void	*ft_calloc(size_t nmemb, size_t size);
t_table	*create_table(t_table *table, int count);
void	*destroy(t_table *table);
void	*free_forks(pthread_mutex_t *forks, int count);
void	*eat(t_philosopher *philosopher, unsigned int time);
void	*routine(t_table *table, int b);
void	*thread_routine(void *vd);
void	ft_print(char *str, struct timeval tv, int id, struct timeval start);
void	ft_log(t_table *table, char *str, unsigned long timestamp, int philosopher);
void	*think(t_philosopher *philosopher, unsigned int time);
void	*sleep_thread(t_philosopher *philosopher, unsigned int time);
#endif
