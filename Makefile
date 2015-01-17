# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 17:40:16 by gpetrov           #+#    #+#              #
#    Updated: 2015/01/17 20:29:11 by gpetrov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_gkrellm
FILES	= main.cpp
OBJS	= $(FILES:%.cpp=.obj/%.o)
INC 	= 
FLAGS	= -Wall -Wextra -Werror
LIB		= -lncurses
CC		= g++	

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) -lncurses 
	@echo "\n > \033[36m$(NAME)\033[m project compilation [\033[32mDONE\033[m]\n"

.obj/%.o: %.cpp
	@mkdir -p .obj
	@g++ -c $< -o $@ $(FLAGS)
	@echo -n .

clean:
	@rm -rf .obj

fclean: clean
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"

re: fclean all

.PHONY: all clean fclean re
