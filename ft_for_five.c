#include "push_swap.h"

stack   *ft_parcing_five(stack *pileA, stack *pileB, int tmp)
{
    if(tmp == 3)
    {
        pileA = ft_reverse_last(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileA = ft_reverse(pileA);
        pileA = ft_reverse(pileA);
    }
    else if(tmp == 2)
    {
        pileA = ft_reverse(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileA = ft_swap(pileA);
        pileA = ft_reverse_last(pileA);
    }
    else if(tmp == 1)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileA = ft_swap(pileA);
    }
    else if(tmp == 0)
        pileA = ft_swap_between(pileA, pileB->value);
    return (pileA);
}

stack   *for_five(stack *pileA, stack *pileB)
{
    stack   *element;
    int tmp;

    element = pileA;
    tmp = 0;
    while(pileB->value > element->value && tmp < 3)
    {
        element = element->next;
        tmp++;
    }
    if(element->value < pileB->value)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileA = ft_reverse(pileA);
    }
    else 
        pileA = ft_parcing_five(pileA, pileB, tmp);
    return (pileA);
}

stack   *only_five(stack *pileA, stack *pileB, int arg)
{
    stack *element;
    int tmp = 0;

    if (arg == 5)
    {
        pileA = for_four(pileA, pileB);
        return (pileA);
    }
    pileB = ft_swap_between(pileB, pileA->value);
    pileA = ft_free_stack(pileA);
    pileB = ft_swap_between(pileB, pileA->value);
    pileA = ft_free_stack(pileA);
    pileA = only_three(pileA, arg);
    element = pileA;
    pileA = ft_for_four(pileA, pileB, element);
    pileB = ft_free_stack(pileB);
    if (arg == 6)
        pileA = for_five(pileA, pileB);
    pileB = ft_free_stack(pileB);
    return (pileA);
}