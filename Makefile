##
## Makefile for wolf3d in /home/barrau_h/Desktop/Wolf3D
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Thu Jan 15 16:58:55 2015 Hippolyte Barraud
## Last update Sun Jan 18 19:01:14 2015 Hippolyte Barraud
##

CC	=	gcc

SRC	=	src/main.c					\
		src/display.c					\
		src/get_next_line.c				\
		src/hitbox.c					\
		src/get_initial_values.c			\
		src/check_move.c				\
		src/expose_manage.c				\
		src/event_manage.c				\
		src/show_wall.c					\
		src/found_initial.c				\
		src/move.c					\
		src/put_wall.c					\
		src/get_the_map.c				\
		src/get_background.c				\
		src/fps_meter.c

SRCL	=	library/source_libmy/my_putchar.c		\
		library/source_libmy/my_putstr.c		\
		library/source_libmy/my_strlen.c		\
		library/source_libmy/show_tab.c			\
		library/source_libmy/my_tablen.c		\
		library/source_libmy/my_strdup.c		\
		library/source_libmy/my_putnbr.c		\
		library/source_libmy/my_getnbr.c		\
		library/source_libmy/retmalloc.c		\
		library/source_libmy/my_putnbr_base.c		\
		library/source_libmy/my_getnbr_base.c		\
		library/source_libmy/cmp_char.c			\
		library/source_libmy/my_printf_extend.c		\
		library/source_libmy/my_printf.c		\
		library/source_libmy/xmalloc.c

OBJL	=	$(SRCL:.c=.o)

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wextra -Wall -W
CFLAGS	+=	-ansi -pedantic -O3
CFLAGS	+=	-I./include

LIB	=	libmy.a

LDFLAGS =	-lm
LDFLAGS +=	-L ./library/ -lmy -lmlx
LDFLAGS +=	-L /usr/X11/lib -lXext -lX11

NAME	=	wolf3d

all	:	$(NAME)

$(NAME) :	$(LIB) $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

$(LIB)	:	$(OBJL)
		ar rc $(LIB) $(OBJL)
		ranlib $(LIB)
		mv $(LIB) ./library/

clean	:
		rm -f $(OBJ)
		rm -f $(OBJL)

fclean	:	clean
		rm -f $(NAME)
		rm -f ./library/$(LIB)

re	:	clean $(NAME)

.PHONY	:	all clean fclean re
