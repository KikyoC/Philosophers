/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:52 by tom               #+#    #+#             */
/*   Updated: 2025/03/11 10:05:09 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	struct s_table			*table;
	int						id;
	struct s_philosopher	*next;
	pthread_t				thread;
	int						left_id;
	int						right_id;
	long					last_eat;
	pthread_mutex_t			*last_eat_m;
	int						rounds;
	pthread_mutex_t			*rounds_m;
}	t_philosopher;

typedef struct s_table
{
	struct s_philosopher	*first;
	int						count;
	int						rounds;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						start_time;
	int						someone_died;
	pthread_mutex_t			**forks;
	pthread_mutex_t			*print;
	pthread_mutex_t			*die;
	pthread_t				die_manager;
}	t_table;

char	*ft_itoa(int n);

int		ft_atoi(const char *nptr);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

int		parse(int argc, char **argv, t_table *table);

int		create_table(t_table *table);

void	*thread_routine(void *vd);

void	destroy_table(t_table *table);

void	print_message(t_philosopher *philo, char *str);

int		is_died(t_table *table);

void	set_died(t_table *table);

void	*die_routine(void *vd);

void	set_last_eat(t_philosopher *philo);

long	get_last_eat(t_philosopher *philo);

void	*destroy_philosopher(t_philosopher *philo);

int		all_full_eat(t_table *table);

void	increment_eat(t_philosopher *philo);

#endif
