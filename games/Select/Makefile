##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

SRC	=		SelectScreen.cpp

NAME	=	lib_arcade_SelectScreen.so

all:		game

game:
		g++ -fPIC -shared -o $(NAME) $(SRC)
		mv $(NAME) ..

clean:
		rm -f *.o

fclean:		clean
		rm -f ../$(NAME)

re:		fclean all

auteur:
		echo $(USER) > auteur

#.PHONY: 	all clean fclean re