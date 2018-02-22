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

OS := $(shell uname)

MLX_DIR := $(LIB_DIR)minilibx/
MLX := $(MLX_DIR)libmlx.a

LFT_DIR := $(LIB_DIR)libft/
LFT := $(LFT_DIR)libft.a

SRC := main.c read_map.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_FLAG = -Wextra -Werror -Wall

ifeq ($(OS), Linux)
	FRAMWORK = -lXext -lX11
else 
	FRAMWORK = -framework OpenGL -framework AppKit
endif

LIN_FLAG = $(LFT) $(MLX) $(FRAMWORK) -I$(MLX_DIR) -I$(LFT_DIR)

CC = gcc

NAME = wolf3d

vpath %.c $(SRC_DIR)

.PHONY : all clean fclean re sdlfclean

all: $(NAME)

$(NAME): $(LFT) $(MLX) $(OBJ) 
	$(CC) $(OBJ) $(LIN_FLAG) -o $(NAME)

$(LFT):
	make -C $(LFT_DIR) 2> /dev/null

$(MLX):
	make -C $(MLX_DIR) > /dev/null 2> /dev/null

$(OBJ_DIR)%.o:%.c
	$(CC) $(OBJ_FLAG) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(LFT_DIR)

fclean: clean
	rm -f $(NAME)

cleanlib:
	make fclean -C $(LFT_DIR) > /dev/null 2> /dev/null
	make clean -C $(MLX_DIR) > /dev/null 2> /dev/null

re: fclean all
