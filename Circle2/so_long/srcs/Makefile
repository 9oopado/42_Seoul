# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/19 17:32:27 by jikoo             #+#    #+#              #
#    Updated: 2022/10/20 18:44:45 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
MLX			= -lmlx -framework OpenGL -framework Appkit

# header files
HEADER_DIR  = includes/
HEADER_SRCS	= so_long.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# source files
SRCS        = main.c map.c game.c utils.c get_next_line.c
OBJS		= $(SRCS:c=o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re