# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slyazid <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/15 00:41:25 by slyazid           #+#    #+#              #
#    Updated: 2018/11/26 17:13:23 by mzahir           ###   ########.fr        #
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
	/bin/rm -rf *.o *.swp *.gch
fclean: clean
	/bin/rm -rf $(NAME)
re: fclean all
