#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int     is_empty_stack(stack *st)
{
    if(st == NULL)
        return (1);
    return (0);
}

stack   *empiler(stack *pile, int nombre)
{
    stack *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
        exit(EXIT_FAILURE);
    element->value = nombre;
    element->next = pile;
    
    return (element);
}

stack   *clear_stack(stack *pile)
{
    stack *element;
    if(is_empty_stack(pile))
        return NULL;
    while(pile)
    {
        element = pile;
        pile = pile->next;
        free(element);
    }
    return (pile);
}

int   depiler(stack *pile)
{
    return (pile->value);
}

void    afficherPile(stack *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(!is_empty_stack(pile))
    {
        printf("[%d]\n", pile->value);
        pile = pile->next;
    }
    return ; 
}

stack   *ft_next_number(stack *pile)
{
    stack *tmp;

    tmp = pile;
    pile = pile->next;
    free(tmp);
    return (pile);
}

stack   *ft_free_stack(stack *pile)
{
    stack *element;

    element = pile->next;
    free(pile);
    return(element);
}

int	ft_lstsize(stack *pileA)
{
	int	size;

	size = 0;
	while (pileA)
	{
		++size;
		pileA = pileA->next;
	}
	return (size);
}