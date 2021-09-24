#include "push_swap.h"

stack   *ft_tri_hundred(stack *pileA, int pos, int i)
{
    if((pos / 2) <= i)
    {
        while(i < pos)
        {
            pileA = ft_reverse_last(pileA);
            i++;
        }
    }
    else
    {
        while(i > 1)
        {
            pileA = ft_reverse(pileA);
            i--;
        }
    }
    return (pileA);
}

stack   *ft_tri_hundred_b(stack *pileA, int pos, int i)
{
    if((pos / 2) <= i)
    {
        while(i < pos)
        {
            pileA = ft_reverse_last_b(pileA);
            i++;
        }
    }
    else
    {
        while(i > 1)
        {
            pileA = ft_reverse_b(pileA);
            i--;
        }
    }
    return (pileA);
}

int     ft_what_position(int i, int pos, stack *element)
{
    int tmp;

    tmp = element->value;
    while(element)
    {
        if(tmp > element->value)
        {
            tmp = element->value;
            i = pos;
        }
        pos++;
        element = element->next; 
    }
    return i;
}

stack   *ft_hundred_b(stack *pileA)
{
    int i ;
    stack *element;
    stack *pileB;

    pileB = NULL;
    element = pileA;
    while(pileA)
    {
        i = ft_what_position(1, 1, element);
        pileA = ft_tri_hundred_b(pileA, ft_lstsize(pileA) + 1, i);
        pileB = ft_swap_between(pileB, pileA->value);
        pileA = ft_free_stack(pileA);
        element = pileA;
    }
    while(pileB)
    {
        pileA = ft_swap_between_b(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
    }
    return (pileA);
}

stack   *ft_hundred(stack *pileA)
{
    int i;
    stack *element;
    stack *pileB;

    pileB = NULL;
    element = pileA;
    while(pileA)
    {
        i = ft_what_position(1, 1, element);
        pileA = ft_tri_hundred(pileA, ft_lstsize(pileA) + 1, i);
        pileB = ft_swap_between_b(pileB, pileA->value);
        pileA = ft_free_stack(pileA);
        element = pileA;
    }
    while(pileB)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
    }
    return (pileA);
}