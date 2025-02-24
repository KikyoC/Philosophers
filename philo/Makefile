# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tom <tom@42angouleme.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 11:38:09 by tom               #+#    #+#              #
#    Updated: 2025/02/24 16:20:14 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo
CFLAGS = -Wall -Werror -Wextra -g

SRCS= philosophers.c \
	parsing.c \
	libc.c \
	init.c \
	routine.c \
	destroy.c \
	print.c \
	die.c \
	die_routine.c \
	last_eat.c

OBJS_DIR= objs/

OBJS= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))


all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $@

objs/%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p objs

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -rf $(OBJS_DIR)

re: fclean all


.PHONY: all
