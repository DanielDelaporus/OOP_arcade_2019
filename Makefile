##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

CC		=	g++

FLAGS		=	-Werror -Wall -Wextra

SRC_CORE	=

HEADER		=	./arcade

OBJ     	=       $(SRC_CORE:.cpp=.o)

NAME    	=       MyGKrellm_ncurses

all:		graphicals games core

core:
			make -C Core/
			make -C games/Select/

games:
			make -C games/Solar\ Fox/
			make -C games/Pacman/

graphicals:
			make -C lib/ncurse/

clean:
			make clean -C lib/ncurse
			make clean -C games/Solar\ Fox/
			make clean -C games/Pacman/
			make clean -C Core/
			make clean -C games/Select/

fclean:		clean
			make fclean -C lib/ncurse
			make fclean -C games/Solar\ Fox/
			make fclean -C games/Pacman/
			make fclean -C Core/
			make fclean -C games/Select/

re:			fclean all

auteur:
			echo $(USER) > auteur

.PHONY: 	all clean fclean re games graphicals core
