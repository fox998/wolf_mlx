# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afokin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/17 13:42:39 by afokin            #+#    #+#              #
#    Updated: 2018/02/17 13:42:43 by afokin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR := ./src/
LIB_DIR := ./lib/
INC_DIR := ./inc/
OBJ_DIR := ./obj/

SRC := 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_FLAG = -Wextra -Werror -Wall

LIN_FLAG = 

CC = gcc

NAME = 

vpath %.c $(SRC_DIR)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	%(СС) $(LIN_FLAG) -o $(NAME)

$(OBJ_DIR)%.o:%.c
	$(CC) $(OBJ_FLAG) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

