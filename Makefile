##
## EPITECH PROJECT, 2019
## Piscine_C_J10
## File description:
## Makefile
##

.PHONY : all clean fclean re

SRC	=	parser.c \
		fill.c \
		result.c \
		negnbr.c \
		my_put_nbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	eval_expr

all:	$(OBJ)
##	make -sC ../lib/my
	gcc -o $(NAME) $(OBJ) -Wextra -Wall -Iinclude/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
