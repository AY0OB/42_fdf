# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amairia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 13:14:16 by amairia           #+#    #+#              #
#    Updated: 2024/12/23 06:37:33 by amairia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_exec

FDF = fdf.a

LIBFT_DIR = libft_with_gnl_printf
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = minilibx-linux
MINILIBX = -L./$(MINILIBX_DIR)/

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
MLXFLAGS = -lmlx -lX11 -lXext

SRC =	src/parsing.c src/coo_creator.c src/feed_coo.c src/free_lines_coo.c
	src/fdf_manager.c src/trace_line src/draw_map.c src/do_key.c src/main.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(FDF) $(LIBFT) $(MINILIBX)
	$(CC) -o $@ $^ $(MLXFLAGS) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(FDF) : $(OBJ)
	$(AR) $@ $^

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR) pfgnl

$(MINILIBX) :
	$(MAKE) -C $(MINILIBX_DIR) all

all : $(NAME)

clean :
	rm -f $(OBJ) $(FDF)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
