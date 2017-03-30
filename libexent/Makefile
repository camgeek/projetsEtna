CC	=	gcc -Wall -Wextra -Werror -L.

FLAG	=	-lmy

NAME	=	a.out

LIB 	=	ar r

INDEX	=	ranlib

NAMELIB	=	libmy.a

SRC	=	my_strcmp.c \
		my_strdup.c \
		my_strlen.c \
		my_putstr.c \
		my_putchar.c \
		del_add_liste.c \
		gest_list.c \
		gest_param.c \
		my_put_nbr.c \
		gest_log.c \
		my_strcat.c \
		my_putstr_color.c \


COMPILE =	main.c \

OBJ	=	$(SRC:%.c=%.o)
OBJCP	=	$(COMPILE:%.c=%.o)
RM	=	rm -vrf

$(NAME)	:	$(OBJ) $(OBJCP)
		$(LIB) $(NAMELIB) $(OBJ)
		$(INDEX) $(NAMELIB)
		$(CC) $(OBJCP) $(FLAG)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) $(OBJCP)

fclean	:	clean
		$(RM) $(NAME)
		$(RM) $(NAMELIB)

re	:	fclean all
