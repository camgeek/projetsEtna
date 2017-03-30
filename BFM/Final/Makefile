CC	=	gcc -Wall -Wextra -Werror

NAME	=	sta

SRC	=	my_strcmp.c \
		my_strdup.c \
		my_strlen.c \
		my_putstr.c \
		my_putchar.c \
		readLine.c \
		main.c \
		my_put_nbr.c \
		begin.c \
		getCreature.c \
		arg_control.c \
		container.c \
		start.c \
		OoB.c \
		IB.c \
		attack.c \
		competence.c \
		bonus.c \

OBJ	=	$(SRC:%.c=%.o)
RM	=	rm -vrf

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
