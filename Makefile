
CMPL	=	gcc
FLGS	=	-Wall -Wextra -Werror

NAME	=	./resources/players/slyazid.filler
LIBR	=	libft
LBIN	=	libft/libft.a

SRCS	=	heat_map.c initialize_params.c tools.c token.c piece.c main.c
HDRS	=	filler.h

all: $(NAME)

$(NAME):
	@make -C $(LIBR)
	@gcc $(FLGS) -o $(NAME) $(SRCS) $(LBIN)
	@echo player created and ready to play!!

clean:
	@make clean -C $(LIBR)
	@echo clean

fclean: clean
	@make fclean -C $(LIBR)
	@rm -f $(NAME)
	@echo fclean

re: fclean all
