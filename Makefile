# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efayolle <efayolle@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 09:13:56 by efayolle          #+#    #+#              #
#    Updated: 2024/04/25 15:18:55 by efayolle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
FLAGS = -Wall -Werror -Wextra -g3
SOURCES = philo.c ft_atoi.c print.c action.c check.c core.c \
		ft_bzero.c monitoring_n_destroy.c fork_lock.c init_thread.c
OBJ = $(SOURCES:.c=.o)
INC = philo.h
ODIR = ./obj/

TEST = $(addprefix $(ODIR), $(OBJ))

all: DIR $(NAME)

$(NAME): $(TEST) $(INC) Makefile 
	$(CC) $(TEST) -lpthread  -o $(NAME)

$(ODIR)%.o: %.c $(INC) Makefile
	$(CC) $(FLAGS) -I. -o $@ -c $<

DIR: 
	@mkdir -p $(ODIR)

clean:
		rm -rf $(ODIR)

fclean: clean
		rm -rf $(NAME)

re: fclean all

allclean: all clean

# -fsanitize=thread