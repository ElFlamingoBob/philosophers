# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 09:13:56 by efayolle          #+#    #+#              #
#    Updated: 2024/01/26 13:05:01 by efayolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
FLAGS=-Wall -Werror -Wextra -lpthread -g3
SOURCES= philo.c ft_atoi.c
OBJ = $(SOURCES:.c=.o)
INC = philo.h

all: $(NAME)

$(NAME): $(OBJ) $(INC) Makefile 
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

allclean: all clean
