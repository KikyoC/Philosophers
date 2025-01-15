/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:52 by tom               #+#    #+#             */
/*   Updated: 2025/01/15 13:16:59 by tom              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_philosopher
{
	struct s_table			*table;
	int						id;
	struct s_philosopher	*next;
	pthread_t				thread;
	int						left_id;
	int						right_id;
}	t_philsopher;

typedef struct s_table
{
	struct s_philosopher	*first;
	int						count;
	int						rounds;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	pthread_mutex_t			**forks;
}	t_table;

char	*ft_itoa(int n);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		parse(int argc, char **argv, t_table *table);
int		create_table(t_table *table);
void	*thread_routine(void *vd);
void	destroy_table(t_table *table);

#endif
