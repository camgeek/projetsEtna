CC = 	gcc
NAME = 	my_ftl
SRC  =  air_shed.c \
	attack.c \
	container.c \
	enemy_fct.c \
	game.c \
	my_put_nbr.c \
	my_string.c \
	player_ftc.c \
	player_ftc_sup.c \
	random.c \
	readline.c \
	system_control.c \
	system_repair.c \
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