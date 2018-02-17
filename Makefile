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

SDL_TAR := $(LIB_DIR)SDL2-2.0.7.tar.gz
SDL_DIR := $(SDL_TAR:.tar.gz=/)
SDL := $(SDL_DIR)build/.libs/libSDL2.a

SRC := 

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_FLAG = -Wextra -Werror -Wall

LIN_FLAG = 

CC = gcc

NAME = 

vpath %.c $(SRC_DIR)

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(SDL) $(OBJ)
	%(СС) $(LIN_FLAG) -o $(NAME)

$(SDL): $(SDL_DIR)
	

l : $(SDL_DIR)

$(SDL_DIR): $(SDL_TAR)
	tar -xf $(SDL_TAR) -C $(LIB_DIR)

$(OBJ_DIR)%.o:%.c
	$(CC) $(OBJ_FLAG) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

