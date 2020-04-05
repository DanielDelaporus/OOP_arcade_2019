##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

## NCURSE

SRC_NCURSE	=	Lib_arcade_ncurse.cpp

NCURSES_I	=	-lncurses

NCURSE_NAME	=	lib_arcade_ncurse.so

## SFML

SRC_SFML	=

SFML_FLAG	=	-lsfml-graphics -lsfml-window -lsfml-system

SFML_NAME	=	lib_arcade_sfml.so

all:		ncurse

ncurse:
		g++ -fPIC -shared $(NCURSES_I) -o $(NCURSE_NAME) $(SRC_NCURSE)
		mv $(NCURSE_NAME) ..

clean:
		rm -f *.o

fclean:		clean
		rm -f ../lib_arcade_ncurse.so

re:		fclean all

auteur:
		echo $(USER) > auteur

#.PHONY: 	all clean fclean re