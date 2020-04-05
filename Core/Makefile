##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

SRC	=		main.cpp \
			lib_graph_handle.cpp \
			lib_games_handle.cpp

NAME	=	arcade

all:		game

game:
		g++ -Wall -Wextra -o $(NAME) $(SRC) -ldl
		mv $(NAME) ..

clean:
		rm -f *.o

fclean:		clean
		rm -f ../$(NAME)

re:		fclean all

auteur:
		echo $(USER) > auteur

#.PHONY: 	all clean fclean re