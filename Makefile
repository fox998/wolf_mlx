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

MLX_DIR := $(LIB_DIR)minilibx/
MLX := $(MLX_DIR)libmlx.a

SRC := main.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

OBJ_FLAG = -Wextra -Werror -Wall

LIN_FLAG = -lmlx -lXext -lX11 -L $(MLX_DIR) -I$(MLX_DIR)

CC = gcc

NAME = ./wolf3d

vpath %.c $(SRC_DIR)

.PHONY : all clean fclean re sdlfclean

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	%(СС) $(LIN_FLAG) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(OBJ_DIR)%.o:%.c
	$(CC) $(OBJ_FLAG) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(MLX_DIR)

re: fclean all
