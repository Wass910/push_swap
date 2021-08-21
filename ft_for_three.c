#include "push_swap.h"
stack   *ft_for_two(stack *pileA)
{
    stack *element;

    element = pileA->next;
    if(pileA->value > element->value)
        pileA = ft_swap(pileA);
    return (pileA);
}

stack    *only_three(stack *pileA, int arg)
{
    stack *element;

    element = pileA->next;
    if (arg == 3)
        return (ft_for_two(pileA));
    if(element->value > pileA->value && element->value > element->next->value)
    {
        if(pileA->value > element->next->value)
            pileA = ft_reverse_last(pileA);
        else
        {
            pileA = ft_swap(pileA);
            pileA = ft_reverse(pileA);
        }
    }
    else if(element->value < pileA->value && element->value > element->next->value)
    {
        pileA = ft_swap(pileA);
        pileA = ft_reverse_last(pileA);
    }
    else if(pileA->value > element->next->value)
        pileA = ft_reverse(pileA);
    else if(pileA->value < element->next->value && pileA->value > element->value)
        pileA = ft_swap(pileA);
    return (pileA);
}
