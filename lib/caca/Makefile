##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

## SFML

SRC_CACA	=	Lib_arcade_caca.cpp

CACA_I	=	`pkg-config --libs --cflags caca`

CACA_NAME	=	lib_arcade_caca.so

all:		caca

caca:
		g++ -fPIC -shared $(CACA_I) -o $(CACA_NAME) $(SRC_CACA)
		mv $(CACA_NAME) ..

clean:
		rm -f *.o

fclean:		clean
		rm -f ../lib_arcade_caca.so

re:		fclean all

auteur:
		echo $(USER) > auteur

#.PHONY: 	all clean fclean re