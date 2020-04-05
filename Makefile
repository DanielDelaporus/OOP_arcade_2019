##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

all:		graphicals games core

core:
			make -C Core/
			make -C games/Select/

games:
			make -C games/Solar\ Fox/
			make -C games/Pacman/

graphicals:
			make -C lib/ncurse/
			make -C lib/SFML/

clean:
			make clean -C lib/ncurse
			make clean -C games/Solar\ Fox/
			make clean -C games/Pacman/
			make clean -C Core/
			make clean -C games/Select/
			make clean -C lib/SFML/

fclean:		clean
			make fclean -C lib/ncurse
			make fclean -C games/Solar\ Fox/
			make fclean -C games/Pacman/
			make fclean -C Core/
			make fclean -C games/Select/
			make fclean -C lib/SFML/

re:			fclean all

auteur:
			echo $(USER) > auteur

.PHONY: 	all clean fclean re games graphicals core
