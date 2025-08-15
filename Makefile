# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shunwata <shunwata@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 22:25:44 by shunwata          #+#    #+#              #
#    Updated: 2025/08/13 18:39:57 by shunwata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR) \
			-I $(LIBFT_DIR)/includes -I $(FT_PRINTF_DIR) -I $(GET_NEXT_LINE_DIR) -I $(MLX_DIR)

SRC_DIR = srcs
INC_DIR = includes

SRC = $(addprefix $(SRC_DIR)/, main.c map.c render.c)
OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = Libft

FT_PRINTF_DIR = $(LIBFT_DIR)/srcs/ft_printf
GET_NEXT_LINE_DIR = $(LIBFT_DIR)/srcs/get_next_line

MLX = $(MLX_DIR)/libmlx.a
MLX_DIR = minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
