SRC=    ft_error_stdout.c	\
		ft_atoi.c       		\
		ft_five_hundred      \
		ft_for_five.c      \
		ft_for_four.c    \
		ft_for_three.c    	\
		ft_hundred.c     \
		ft_less_hundred.c     \
		ft_ope_stack.c     \
		ft_opti_hundred.c     \
		ft_split.c		\
		ft_test.c     \
		push_swap.c     \
		ft_tri.c     \

NAME= libftprintf.a

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
		rm -f ${OBJETS} 

fclean: clean
		rm -f ${NAME}

.PHONY: all clean fclean re