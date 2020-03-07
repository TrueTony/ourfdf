# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksenaida <ksenaida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 15:18:38 by ksenaida          #+#    #+#              #
#    Updated: 2020/03/07 16:27:26 by ksenaida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c draw.c read_file.c keys.c add_func.c\
	colors.c get_next_line.c sonya.c counter.c
OBJ = $(SRC:.c=.o)
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@gcc -c $(FLAGS) $<

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@gcc -o fdf $(FLAGS) $(OBJ) $(LIBFT) $(FRAMEWORK)

clean:
	@/bin/rm -f $(OBJ)
	@$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	@/bin/rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re