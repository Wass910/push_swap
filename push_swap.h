#include <stdlib.h>
#include <stdio.h>

typedef struct StackElement
{
    int                       value;
    struct StackElement       *next;
}          stack;

void    afficherPile(stack *pile);
stack    *tri_pile(stack *pileA, stack *pileB);
int   depiler(stack *pile);
stack   *empiler(stack *pile, int nombre);
stack   *initalisation(stack *pile);
stack   *clear_stack(stack *pile);
stack   *ft_next_number(stack *pile);
int	ft_atoi(char *str);