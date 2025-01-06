# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 13:14:36 by togauthi          #+#    #+#              #
#    Updated: 2025/01/06 09:32:57 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

SRCS= philosophers.c \
	utils/atoi.c \
	utils/ft_calloc.c \
	create_table.c \
	destroy_table.c

OBJS = $(addprefix objs/, $(SRCS:.c=.o));

CFLAGS = -Wall -Werror -Wextra -g

OBJS_DIR= objs/ \
	objs/utils

GREEN = \e[0;32m
WHITE = \e[0;37m
AQUA = \e[0;36m
YELLOW = \e[0;33m

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)Destination built"

objs/%.o: %.c
	@echo "$(AQUA)Compiling $<..."
	@cc $(CFLAGS) -c $< -o $@
	@echo "$(AQUA)$< compiled$(WHITE)"

$(NAME): $(OBJS_DIR) $(OBJS)
	@echo "$(YELLOW)Compiling objs... $(WHITE)"
	@cc $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Objs compiled.$(AQUA)"
	@figlet -t philosophers

clean:
	@echo "$(YELLOW)Cleaning objs..."
	@rm -rf objs/
	@echo "$(GREEN)Objs cleaned$(WHITE)"

fclean: clean
	@echo "$(YELLOW)Removing executable"
	@rm -f $(NAME)
	@echo "$(GREEN)Executable removed"

re: fclean all