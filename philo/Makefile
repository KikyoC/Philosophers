# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: togauthi <togauthi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/19 13:14:36 by togauthi          #+#    #+#              #
#    Updated: 2024/12/19 14:27:05 by togauthi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= philo

SRCS= philosophers.c \
	utils/atoi.c

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
	@echo "$(GREEN)Objs compiled.$(WHITE)"
	@echo "$(AQUA)mmmmm  #        \"    \"\"#                                #"
	@echo "$(AQUA)#   \"# # mm   mmm      #     mmm    mmm    mmm   mmmm   # mm    mmm    m mm    mmm"
	@echo "$(AQUA)#mmm#\" #\"  #    #      #    #\" \"#  #   \"  #\" \"#  #\" \"#  #\"  #  #\"  #   #\"  \"  #   \""
	@echo "$(AQUA)#      #   #    #      #    #   #   \"\"\"m  #   #  #   #  #   #  #\"\"\"\"   #       \"\"\"m"
	@echo "$(AQUA)#      #   #  mm#mm    \"mm  \"#m#\"  \"mmm\"  \"#m#\"  ##m#\"  #   #  \"#mm\"   #      \"mmm\""
	@echo "$(AQUA)                                                 #         "
	@echo "$(AQUA)                                                 \"$(WHITE)"

clean:
	@echo "$(YELLOW)Cleaning objs..."
	@rm -rf objs/
	@echo "$(GREEN)Objs cleaned$(WHITE)"

fclean: clean
	@echo "$(YELLOW)Removing executable"
	@rm -f $(NAME)
	@echo "$(GREEN)Executable removed"

re: fclean all