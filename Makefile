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
			  ft_operation.c \
			  ft_operation2.c \
			  ft_lstsize.c \
			  get_next_line_utils.c \
			  utils.c \
			  checker_utils.c

BSRCS			= ft_atoi.c \
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
				  tri.c \
				  get_next_line.c \
				  ft_operation.c \
				  ft_operation2.c \
				  ft_lstsize.c \
				  get_next_line_utils.c \
				  checker.c \
				  utils.c \
				  checker_utils.c \

OBJS			= $(SRCS:.c=.o)

BOBJS			= $(BSRCS:.c=.o)

NAME			= push_swap

NAMECHECKER		= checker


CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

$(NAMECHECKER):	$(BOBJS)
				$(CC) $(CFLAGS) $(BOBJS) -o $(NAMECHECKER) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS) $(BOBJS) 

fclean:			clean
				$(RM) $(NAME) $(NAMECHECKER)

re:				fclean all

bonus:			$(NAMECHECKER)

.PHONY:			all clean fclean c.o re bonus