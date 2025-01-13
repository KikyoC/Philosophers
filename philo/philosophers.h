/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:07:16 by togauthi          #+#    #+#             */
/*   Updated: 2025/01/13 16:12:09 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <bits/types/struct_timeval.h>
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
	struct timeval			last_eat;
	pthread_mutex_t			eat;
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
	pthread_mutex_t			die;
	int						is_dead;
	pthread_t				dead_checker;
	struct timeval			tv;
	pthread_mutex_t			write;
}	t_table;

int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
t_table			*create_table(t_table *table, int count);
void			*destroy(t_table *table);
void			*free_forks(pthread_mutex_t *forks, int count);
void			*eat(t_philosopher *philosopher, unsigned int time);
void			*routine(t_table *table, int b);
void			*thread_routine(void *vd);
void			ft_print(char *str, struct timeval tv, int id, struct timeval start);
void			ft_log(t_table *table, char *str, unsigned long ts, int philosopher);
void			*think(t_philosopher *philosopher, unsigned int time);
void			*sleep_thread(t_philosopher *philosopher, unsigned int time);
long			ft_diff(struct timeval t1, struct timeval t2);
struct timeval	get_last_eat(t_philosopher *philosopher);
void			set_last_eat_now(t_philosopher *philosopher);
void			set_die_state(t_table *table);
int				is_die_state(t_table *table);
void			*dead_routine(void *vd);

#endif
