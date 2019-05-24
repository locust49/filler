# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyazid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 00:41:25 by slyazid           #+#    #+#              #
#    Updated: 2018/10/15 15:14:30 by slyazid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = *.c

NAME = libft.a

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME) :
	gcc $(FLAG) -c $(SRC)
	ar rc $(NAME) *.o
clean:
	/bin/rm -rf *.o
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
