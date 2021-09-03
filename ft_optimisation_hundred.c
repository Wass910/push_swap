#include "push_swap.h"

stack   *ft_tri_opti_hundred(stack *pileA, int pos, int i)
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

int     find_median(stack *element,int tmp)
{
    int med;
    int i;
    int pos;
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
    return med;
}
stack   *ft_opti_hundred(stack *pileA, stack *pileB)
{
    int i ;
    int tmp;
    int big;
    int pos;
    stack *element;
    int count = 100;

    element = pileA;
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
    element = pileA;
    while(count < 50 )
    {
        while(element)
        {
            if(element->value > tmp)
                tmp = element->value;
            element = element->next;
        }
        element = pileA;
        count--;
    }
    printf("tmp = %d\n", tmp);
    /*while(count > 0)
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
        count--;
        printf("tmp = %d\n", tmp);
        pileA = ft_tri_opti_hundred(pileA, pos, i);
        pileB = ft_swap_between(pileB, pileA->value);
        pileA = ft_free_stack(pileA);
        element = pileA;
    }*/
    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileB);
    while(pileB)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
    }
    //printf("i = %d\n", i);
    return (pileA);
}