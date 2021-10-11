#include "push_swap.h"

stack   *ft_new_algo(stack *pileA, stack *pileB)
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
        tab = ft_find_little_five(pileA, size_a);
        tab = ft_tri_tab_five(tab, size_a);
        while (tab)
        {
            if(tab->value == i)
            {
                pileB = ft_swap_between_b(pileB, pileA->value);
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
            pileB = ft_swap_between_b(pileB, pileA->value);
            pileA = ft_free_stack(pileA);
            pileB = ft_reverse_b(pileB);
        }
        i = 0;
        while(i < (size_a + 1))
        {
            pileA = ft_swap_between(pileA, pileB->value);
            pileB = ft_free_stack(pileB);
            i++;
        }
        count++;
    }
    while(pileB)
    {
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
    }
    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    return (pileA);
}