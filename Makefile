# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cperrard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 14:05:51 by cperrard          #+#    #+#              #
#    Updated: 2018/06/08 14:34:41 by cperrard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/ft_*.c

SRCO = ./*.o

HDR = ./inc/ft_printf.h

all : $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC)
	@ar rc $(NAME) $(SRCO)

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)

re: fclean all
