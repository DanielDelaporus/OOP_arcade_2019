##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile to build project
##

CC		=	g++

FLAGS		=	-Werror -Wall -Wextra

SRC_CORE	=

HEADER		=	./header

OBJ     	=       $(SRC_CORE:.cpp=.o)

NAME    	=       MyGKrellm_ncurses

## NCURSE

SRC_NCURSE	=

NURSES_I	=		-lncurses

NCURSE_NAME	=	lib_arcade_ncurse.so

## SFML

SRC_SFML	=

SFML_FLAG	=	-lsfml-graphics -lsfml-window -lsfml-system

SFML_NAME	=	lib_arcade_sfml.so

all:		$(NAME) $(NAME_QT)

$(NAME):	$(OBJ)
		cp $(OBJ) ./obj/o_file
		$(CC) $(FLAGS) $(NURSES_I) -o $(NAME) ./obj/o_file/*.o

$(NAME_QT):
			make -C ./src/GUI/build-rush3_app-Desktop-Debug
			cp ./src/GUI/build-rush3_app-Desktop-Debug/rush3_app ./MyGKrellm

clean:
		rm -f $(OBJ)
		rm -rf ./obj/o_file/*.o
		make clean -C ./src/GUI/build-rush3_app-Desktop-Debug
		rm -f *~
		rm -f *#

fclean:		clean
		make clean -C ./src/GUI/build-rush3_app-Desktop-Debug
		rm -f $(NAME)
		rm -f $(NAME_QT)

re:		fclean all
		make clean -C ./src/GUI/build-rush3_app-Desktop-Debug
		make -C ./src/GUI/build-rush3_app-Desktop-Debug

auteur:
		echo $(USER) > auteur

.PHONY: 	all clean fclean re
