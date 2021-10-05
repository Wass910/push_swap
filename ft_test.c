#include "push_swap.h"

stack   *ft_new_algo(stack *pileA, stack *pileB)
{

    int i;
    stack *tab;
    
    i = 1;
    tab = ft_find_little_less(pileA, ((ft_lstsize(pileA) / 2) - 1));
    tab = ft_tri_tab_less(tab, ((ft_lstsize(pileA) / 2)- 1));
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
    pileB = ft_less_hundred(pileB);
    pileA = ft_less_hundred(pileA);
    pileA = ft_norme_for_lesshundred(pileA, pileB);
    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    return (pileA);
}