SRCS		= ft_atoi.c \
			  ft_error_stdout.c \
			  ft_five_hundred.c \
			  ft_for_five.c \
			  ft_for_four.c \
			  ft_for_three.c \
			  ft_hundred.c \
			  ft_ope_stack.c \
			  ft_opti_hundred.c \
			  ft_quick_sort.c \
			  ft_split.c \
			  push_swap.c \
			  tri.c \
			  get_next_line.c \

OBJS			= $(SRCS:.c=.o)


NAME			= push_swap

NAMECHECKER		= checker

HEADERS			= includes/

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS) 

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS) 

fclean:			clean
				$(RM) $(NAME) $(NAMECHECKER)

re:				fclean all


.PHONY:			all clean fclean c.o re bonus
