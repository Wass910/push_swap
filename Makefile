SRC=    ft_error_stdout.c	\
		ft_for_five.c       		\
		ft_atoi.c      \
		ft_for_four.c      \
		ft_for_three.c    \
		ft_hundred.c    	\
		ft_ope_stack.c     \
		ft_split.c     \
		push_swap.c     \
		tri.c     \


NAME= push_swap

OBJETS= ${SRC:.c=.o}


gcc=gcc 

$(NAME):    ${OBJETS}
			ar -rc ${NAME} $^
			ranlib ${NAME}

%.o: %.c
	${gcc} -o $@ -c $<


all: ${NAME}

re: fclean all

clean:
		rm -f ${OBJETS} $(OBJETS_BONUS)

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re