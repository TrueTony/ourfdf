# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 20:46:43 by ksenaida          #+#    #+#              #
#    Updated: 2020/03/07 20:57:31 by ksenaida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB = ./libft/
LIBLIBX = ./minilibx_macos/
LIBFT = $(LIB)libft.a
LIBLIBX_F = $(LIBLIBX)libmlx.a
SRC = main.c draw.c read_file.c keys.c keys2.c add_func.c \
	colors.c get_next_line.c sonya.c counter.c
OBJ = $(SRC:.c=.o)
HDR = ./includes/fdf.h
CC = gcc
FLAGS =  -Wall -Wextra -Werror
FRAME = -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $<

$(NAME): $(OBJ) $(HDR) $(SRC)
	$(MAKE) -C $(LIB)
	$(MAKE) -C $(LIBLIBX)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBLIBX_F) $(FRAME)

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIB) clean
	$(MAKE) -C $(LIBLIBX) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB) fclean
	$(MAKE) -C $(LIBLIBX) clean

re: fclean all