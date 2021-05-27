NAME =	libftprintf.a

SRC =	ft_printf.c \
		ft_utils.c \
		ft_utils2.c \
		ft_run_parser.c \
		ft_run_converter.c \
		ft_run_cs.c \
		ft_run_p.c \
		ft_run_diuxp.c

HEADER = ft_printf.h

OBJ =	$(SRC:.c=.o)

CC =	gcc

FLAGS =	-Werror -Wall -Wextra

RM =	/bin/rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER)
		ar rc $(NAME) $(OBJ)

%.o:%.c
		$(CC) $(FLAGS) -I $(HEADER) -c $< -o $@

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: clean fclean all re
