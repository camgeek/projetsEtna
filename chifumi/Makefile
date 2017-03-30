CC = 	gcc
NAME = 	chifumi
SRC  =  add_item.c \
	aff_error.c \
	arg_control.c \
	control_game_n.c \
	entry_control.c \
	fill_game.c \
	fill_game_e.c \
	init.c \
	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	my_strcmp.c \
	my_strcpy.c \
	put_stroke.c \
	readLine.c \
	main.c
OBJ  =	 $(SRC:%.c=%.o)
RM   =	rm -f

CFLAGS = -Wall -Wextra -Werror

.PHONY  :	fclean

ALL	:	$(NAME)

$(NAME) :	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean   :
		$(RM) $(OBJ)

fclean  :	clean
		$(RM) $(NAME)

re      :	fclean ALL
