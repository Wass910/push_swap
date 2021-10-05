#include "push_swap.h"

stack   *ft_norme_for_tritab_five(int count, int tmp, stack *tmp_tab, stack *tab)
{
    while(count > 0)
    {
        tmp = ft_morceaux_suite(tab, tmp);
        tmp_tab = empiler(tmp_tab, tmp);
        count--;
    }
    return tmp_tab;
}

stack     *ft_tri_tab_five(stack *tab, int count)
{
    int i;
    int tmp;
    stack *tmp_tab;
    stack *final;

    tmp_tab = NULL;
    final = NULL;
    tmp = tab->value;
    tmp = ft_morceaux(tab, tmp);
    tmp_tab = empiler(tmp_tab, tmp);
    tmp_tab = ft_norme_for_tritab_five(count, tmp, tmp_tab, tab);
    tmp = count + 1;
    count = 0;
    while(count < tmp)
    {
        final = ft_swap_between_tmp(final, tmp_tab->value);
        tmp_tab = ft_free_stack(tmp_tab);
        count++;
    }
    return final;
}

stack   *ft_norme_for_find_litle_five(stack *tmp_elem, stack *pileA, stack *tab, int tmp, int count)
{
    int pos;
    stack *element;

    element = pileA;
    while(count > 0)
    {
        pos = 1;
        tmp = ft_morceaux_suite(tmp_elem, tmp);
        while(element->value != tmp)
        {
            pos++;
            element = element->next;
        }
        element = pileA;
        tab = empiler(tab, pos);
        count--;
    }
    return tab;
}

stack   *ft_find_little_five(stack *pileA, int count)
{
    stack *tmp_elem;
    stack *tab;
    stack *element;
    int tmp;
    int pos;

    tab = NULL;
    tmp_elem = pileA;
    element = pileA;
    tmp = tmp_elem->value;
    tmp = ft_morceaux(tmp_elem, tmp);
    pos = 1;
    while(element->value != tmp)
    {
        pos++;
        element = element->next;
    }
    tab = empiler(tab, pos);
    element = pileA;
    tab = ft_norme_for_find_litle_five(tmp_elem, pileA, tab, tmp, count);
    return tab;
}

stack   *ft_opti_five_hundred(stack *pileA)
{
    int i;
    stack *tab;
    stack *pileB;
    int count;
    int size_a;
    
    size_a = (ft_lstsize(pileA) / 3) - 1;
    count = 0;
    pileB = NULL;
    while(count < 2)
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
    pileA = ft_hundred(pileA);
    pileB = ft_hundred_b(pileB);
    while(pileB)
    {
        pileB = ft_reverse_last_b(pileB);
        pileA = ft_swap_between(pileA, pileB->value);
        pileB = ft_free_stack(pileB);
    }
    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileA);
    return (pileA);
} 