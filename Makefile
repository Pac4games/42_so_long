# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 15:53:29 by paugonca          #+#    #+#              #
#    Updated: 2023/02/17 17:25:46 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(VERBOSE).SILENT:

NAME		=	so_long
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wall #-fsanitize=address
RM			=	rm -f
MKD			=	mkdir
MLXFLAGS	=	-Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LINUX	=	-I/usr/include -Imlx_linux -O3

SRC_NAME	=	main.c

SRC		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
DEPS	=	./libft/libft.a

SRC_PATH = ./src
OBJ_PATH = ./obj

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(MLX_LINUX) -c $< -o $@
$(NAME): $(DEPS) $(OBJ_PATH) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(DEPS) $(MLXFLAGS) -o $(NAME)
		echo "\x1b[36m[SO_LONG COMPILED]\x1b[0m"

LIBFT_PATH	= ./libft
./libft/libft.a: $(shell make -C $(LIBFT_PATH) -q libft.a || echo force)
	make -C $(LIBFT_PATH)

$(OBJ_PATH):
	$(MKD) -p obj

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) -r $(OBJ_PATH)
	echo "\033[33mRemoving object files...\033[0m"

fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)
		echo "\033[31mRemoving $(NAME)...\033[0m"

re: fclean all

.PHONY:	all clean fclean re force
