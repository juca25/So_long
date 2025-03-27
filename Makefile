# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-ser <juan-ser@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 13:42:14 by juan-ser          #+#    #+#              #
#    Updated: 2025/03/27 15:42:18 by juan-ser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES = -I/usr/include -Imlx_linux
MLX_FLAGS = -L./minilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz

NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
all: $(NAME)

all: $(MLX_LIB) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)
re: fclean all