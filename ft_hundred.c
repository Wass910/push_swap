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

stack   *ft_hundred(stack *pileA, stack *pileB)
{
    int i ;
    int tmp;
    int pos;
    stack *element;

    element = pileA;
    while(pileA)
    {
        pos = 1;
        i = 1;
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
        pileA = ft_tri_hundred(pileA, pos, i);
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