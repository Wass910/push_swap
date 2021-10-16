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
#include "push_swap.h"

stack   *ft_new_algo(stack *pileA, stack *pile_b)
{
    int count;
    int i;
    stack *tab;
    int size_a;
    
    count = 0;
    size_a = (ft_lstsize(pileA) / 11) - 1;
    while(count < 10)
    {
        i = 1;
        tab = ft_index(pileA, size_a);
        tab = ft_tri_tab_five(tab, size_a);
        while (tab)
        {
            if(tab->value == i)
            {
                pile_b = ft_swap_between_b(pile_b, pileA->value);
                pileA = ft_free_stack(pileA);
                tab = tab->next;
            }
            else
                pileA= ft_reverse(pileA);
            i++;
        }
        count++; 
    }
    count = 0;
    while(count < 11)
    {
        pileA = ft_hundred(pileA);
        while(pileA)
        {
            pileA = ft_reverse_last(pileA);
            pile_b = ft_swap_between_b(pile_b, pileA->value);
            pileA = ft_free_stack(pileA);
            pile_b = ft_reverse_b(pile_b);
        }
        i = 0;
        while(i < (size_a + 1))
        {
            pileA = ft_swap_between(pileA, pile_b->value);
            pile_b = ft_free_stack(pile_b);
            i++;
        }
        count++;
    }
    while(pile_b)
    {
        pileA = ft_swap_between(pileA, pile_b->value);
        pile_b = ft_free_stack(pile_b);
    }
    //printf("\nEtat de la pile A:\n");
    //afficherPile(pile_b);
    return (pileA);
}