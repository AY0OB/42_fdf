# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amairia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/26 13:14:16 by amairia           #+#    #+#              #
#    Updated: 2024/12/25 14:53:11 by amairia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf_exec

FDF = src/fdf.a

LIBFT_DIR = libft_with_gnl_printf
LIBFT = $(LIBFT_DIR)/libft.a

FIC = src/
MINILIBX_DIR = minilibx-linux
MINILIBX = -L./$(MINILIBX_DIR)/

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
MTH = -lm
MLXFLAGS = -lmlx -lX11 -lXext

SRC =	$(FIC)parsing.c $(FIC)coo_creator.c $(FIC)feed_coo.c $(FIC)free_lines_coo.c\
	$(FIC)fdf_manager.c $(FIC)trace_line.c $(FIC)draw_map.c $(FIC)main.c\
	$(FIC)do_key.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(FDF) $(LIBFT) $(MINILIBX)
	$(CC) -o $@ $^ $(MLXFLAGS) $(CFLAGS) $(MTH)

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
