#include <stdlib.h>
#include <stdio.h>

typedef struct StackElement
{
    int                       value;
    struct StackElement       *next;
}          stack;

void    afficherPile(stack *pile);
stack   *tri_pile(stack *pileA, stack *pileB, int arg);
int     depiler(stack *pile);
stack   *empiler(stack *pile, int nombre);
stack   *initalisation(stack *pile);
stack   *clear_stack(stack *pile);
stack   *ft_next_number(stack *pile);
int     ft_atoi(char *str);
stack   *ft_free_stack(stack *pile);
stack   *ft_swap(stack *pile);
stack   *ft_add_back(stack **alst, stack *new);
stack   *ft_reverse(stack *pile);
stack   *ft_add_front(stack **alst, stack *new);
stack   *ft_reverse_last(stack *pile);
stack   *ft_swap_between(stack *pile_more, int add);
stack   *only_three(stack *pileA, int arg);
stack   *only_five(stack *pileA, stack *pileB, int arg);
stack   *ft_for_four(stack *pileA, stack *pileB, stack *element);
stack   *for_four(stack *pileA, stack *pileB);
stack   *for_five(stack *pileA, stack *pileB);
stack   *ft_for_two(stack *pileA);
stack   *ft_parcing_five(stack *pileA, stack *pileB, int tmp);
stack   *ft_hundred(stack *pileA);
stack   *ft_opti_hundred(stack *pileA, stack *pileB);
stack   *ft_swap_between_b(stack *pile_more, int add);
char	**ft_split(char const *s, char c);
void    ft_verif_double(stack *pile);
int     ft_is_digit(char *str);
int	    ft_lstsize(stack *pileA);
int     ft_is_order(stack *pileA);
stack   *ft_tri_hundred(stack *pileA, int pos, int i);
stack    *ft_swap_between_tmp(stack *pile_more, int add);
stack   *ft_hundred_b(stack *pileA);
stack   *ft_reverse_b(stack *pile);
stack   *ft_reverse_last_b(stack *pile);