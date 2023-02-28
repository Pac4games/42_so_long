# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paugonca <paugonca@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 15:53:29 by paugonca          #+#    #+#              #
#    Updated: 2023/02/28 22:44:10 by paugonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		=	-Wall -Werror -Wall #-fsanitize=address
RM			=	rm -f
MKD			=	mkdir
MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_LINUX	=	-I/usr/include -Imlx_linux -O3

SRC_NAME	=	main.c			\
				map_load.c		\
				print_utils.c	\
				check_utils.c

SRC		=	$(addprefix $(SRC_PATH)/, $(SRC_NAME))
OBJ		=	$(patsubst $(SRC_PATH)/%.c, $(OBJ_PATH)/%.o, $(SRC))
DEPS	=	./libft/libft.a ./get_next_line/get_next_line.a

SRC_PATH = ./src
OBJ_PATH = ./obj

all: $(NAME)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) $(MLX_LINUX) -c $< -o $@
$(NAME): $(DEPS) $(OBJ_PATH) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(DEPS) $(MLXFLAGS) -o $(NAME)
		echo -e "\n[so_long successfully compiled!]"

LIBFT_PATH	= ./libft
./libft/libft.a: $(shell make -C $(LIBFT_PATH) -q libft.a || echo force)
	make bonus -C $(LIBFT_PATH)

GNL_PATH	= ./get_next_line
./get_next_line/get_next_line.a: $(shell make -C $(GNL_PATH) -q get_next_line.a ||echo force)
	make -C $(GNL_PATH)

$(OBJ_PATH):
	$(MKD) -p obj

clean:
	echo -e "[Removing object files...]\n"
	make clean -C $(LIBFT_PATH)
	make clean -C $(GNL_PATH)
	$(RM) -r $(OBJ_PATH)

fclean: clean
		echo -e "[Removing $(NAME)...]\n"
		make fclean -C $(LIBFT_PATH)
		make fclean -C $(GNL_PATH)
		$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re force
