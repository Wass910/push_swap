#include "push_swap.h"

stack    *only_three(stack *pileA, int arg)
{
    stack *element;

    element = pileA->next;
    if (arg == 3)
    {
        if(pileA->value > element->value)
            pileA = ft_swap(pileA);
        return (pileA);
    }
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

stack    *only_five(stack *pileA, stack *pileB, int arg)
{
    stack *element;
    int i = 4;
    int tmp = 0;

    //element = NULL;
    pileB = ft_swap_between(pileB, pileA->value);
    pileA = ft_free_stack(pileA);
    pileB = ft_swap_between(pileB, pileA->value);
    pileA = ft_free_stack(pileA);
    pileA = only_three(pileA, arg);
    element = pileA;
    while(pileB->value > element->value && tmp < 2)
    {
        element = element->next;
        tmp++;
    }
    if(element->value < pileB->value)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        pileA = ft_reverse(pileA);
        i = i + 2;
    }
    else if(tmp == 2)
    {
        pileA = ft_reverse_last(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        pileA = ft_reverse_last(pileA);
        pileA = ft_reverse_last(pileA);
        i = i + 4;
    }
    else if(tmp == 1)
    {
        pileA = ft_reverse(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        i = i + 2;
    }
    else if(tmp == 0)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        i++;
    }
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
        pileB = ft_free_stack(pileB);
        pileA = ft_reverse(pileA);
        i = i + 2;
    }
    else if(tmp == 3)
    {
        pileA = ft_reverse_last(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        pileA = ft_reverse(pileA);
        pileA = ft_reverse(pileA);
        i = i + 4;
    }
    else if(tmp == 2)
    {
        pileA = ft_reverse(pileA);
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        pileA = ft_swap(pileA);
        pileA = ft_reverse_last(pileA);
        i = i + 4;
    }
    else if(tmp == 1)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        pileA = ft_swap(pileA);
        i = i + 2;
    }
    else if(tmp == 0)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
        i++;
    }
    
    printf("nombre d operation = %d\n",i);
    return (pileA);
}