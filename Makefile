# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 09:13:56 by efayolle          #+#    #+#              #
#    Updated: 2024/02/07 13:10:43 by efayolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CC=cc
FLAGS=-Wall -Werror -Wextra -g3
SOURCES= philo.c ft_atoi.c print.c action.c list.c check.c
OBJ = $(SOURCES:.c=.o)
INC = philo.h

all: $(NAME)

$(NAME): $(OBJ) $(INC) Makefile 
	$(CC) $(OBJ) -lpthread -o $(NAME)

%.o : %.c $(INC) Makefile
	$(CC) $(FLAGS) -g -I. -o $@ -c $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

allclean: all clean
