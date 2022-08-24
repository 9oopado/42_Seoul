# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 13:49:36 by jikoo             #+#    #+#              #
#    Updated: 2022/08/24 16:44:37 by jikoo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC          = cc

CFLAGS      = -Wall -Wextra -Werror

HEADER      = ft_printf.h

SRCS        = ft_printf.c ft_printf_utils.c ft_print_char.c ft_print_string.c \
			  ft_print_decimal.c ft_print_hexadecimal.c

OBJS		= $(SRCS:c=o)

NAME		= ft_printf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re