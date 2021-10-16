#include "push_swap.h"

int     ft_calculate_pivot(stack *pile, stack *tab, int size)
{
    int i = 0;
    stack  *tmp_pile;
    stack *tmp_tab;

    i = 0;
    tmp_pile = pile;
    tmp_tab = tab;
    while(tmp_tab && i < size)
    {
        tmp_tab = tmp_tab->next;
        i++;
    }
    i = tmp_tab->value;
    while(tmp_pile && i > 1)
    {
        tmp_pile = tmp_pile->next;
        i--;
    }
    return (tmp_pile->value);
}

stack   *ft_quick_sort_a(stack *pileA, stack *pileB, int i)
{
    int count;
    stack *tab;
    int val;
    int size_a;

    count = 0;
    while(count < i)
    {
        val = 0;
        size_a = (ft_lstsize(pileA)) - 1;
        tab = ft_find_little_five(pileA, size_a);
        val = ft_calculate_pivot(pileA, tab, (ft_lstsize(pileA)) / 2);
        while(pileA->value > val)
            pileA = ft_reverse(pileA);
        pileB = ft_swap_between_b(pileB, pileA->value);
		pileA = ft_free_stack(pileA);
        count++; 
    }
    return (pileB);
}

stack   *ft_quick_sort_b(stack *pileA, stack *pileB, int i, int what_pivot)
{
    int count;
    stack *tab;
    int val;
    int size_a;

    count = 0;
    while(count < i)
    {
        val = 0;
        size_a = (ft_lstsize(pileB)) - 1;
        tab = ft_find_little_five(pileB, size_a);
        val = ft_calculate_pivot(pileB, tab, (ft_lstsize(pileB)) / what_pivot);
        while(pileB->value < val)
            pileB = ft_reverse_b(pileB);
        pileA = ft_swap_between(pileA, pileB->value);
		pileB = ft_free_stack(pileB);
        count++; 
    }
    afficherPile(pileA, pileB, 49);
    return (pileA);
}

stack   *ft_parcing_all(stack *pileA, stack *pileB, int what_pivot)
{
    int count;
    int i;
    stack *tab = NULL;
    stack   *tmp_pileA = NULL;
    int val = 0;

    i = ft_lstsize(pileA);
    pileB = ft_quick_sort_a(pileA, pileB, i);
    tmp_pileA = ft_quick_sort_b(tmp_pileA,pileB, i, what_pivot);
    tmp_pileA = ft_hundred(tmp_pileA);
    
    while(pileA)
        pileA = ft_free_stack(pileA);
    //afficherPile(tmp_pileA, tab, val);
    return (tmp_pileA);
}
