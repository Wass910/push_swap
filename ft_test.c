#include "push_swap.h"

stack   *ft_new_algo_2(stack *pileA, stack *pileB)
{
    int count;
    int i;
    stack *tab;
    int size_a;
    
    count = 0;
    size_a = (ft_lstsize(pileA) / 5) - 1;
    while(count < 4)
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
    while(count < 5)
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
    //afficherPile(pileB);
    return (pileA);
}


/*stack   *ft_quick_sort_b(stack *pileA, stack *pileB)
{
    int count = 0;
    stack *tab;
    int size_a;
    stack   *tmp_pile;
    int pivot;

    while(count < ft_lstsize(pileB))
    {
        pivot = 0;
        tmp_pile = pileB;
        size_a = (ft_lstsize(pileB)) - 1;
        tab = ft_find_little_five(pileB, size_a);
        pivot = ft_calculate_pivot(pileB, tab, tmp_pile);
        //printf("val = %d\n", val);
        while(pileB->value > pivot)
        {
            pileB = ft_reverse_b(pileB);
        }
        pileA = ft_swap_between_b(pileA, pileB->value);
		pileB = ft_free_stack(pileB);
        count++; 
    }
    return (pileA);
}

stack   *ft_quick_sort_a(stack *pileA, stack *pileB)
{
    int count = 0;
    int i;
    stack *tab;
    int size_a;
    stack   *tmp_pile;
    int pivot;

    while(count < ft_lstsize(pileA))
    {
        i = 0;
        printf("taille pile = %d\n" , ft_lstsize(pileA));
        pivot = 0;
        tmp_pile = pileA;
        size_a = (ft_lstsize(pileA)) - 1;
        tab = ft_find_little_five(pileA, size_a);
        pivot = ft_calculate_pivot(pileA, tab, tmp_pile);
        printf("val = %d\n", pivot);
        while(pileA->value > pivot)
        {
            pileA = ft_reverse(pileA);
        }
        pileB = ft_swap_between_b(pileB, pileA->value);
		pileA = ft_free_stack(pileA);
        tab = ft_free_stack(tab);
        count++; 
    }
    return (pileB);
}*/

int     ft_calculate_pivot(stack *pile, stack *tab, int size)
{
    int i = 0;
    stack  *tmp_pile = pile;
    stack *tmp_tab = tab;

    
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

stack   *ft_new_algo(stack *pileA, stack *pileB)
{
   int count;
    int i;
    stack *tab;
    int size_a;
    stack   *tmp_pile;
    int val;
    
    count = 0;
    i = ft_lstsize(pileA);
    while(count < i)
    {

        val = 0;
        tmp_pile = pileA;
        size_a = (ft_lstsize(pileA)) - 1;
        tab = ft_find_little_five(pileA, size_a);
        val = ft_calculate_pivot(pileA, tab, (ft_lstsize(pileA)) / 2);
        while(pileA->value > val)
        {
            pileA = ft_reverse(pileA);
        }
        pileB = ft_swap_between_b(pileB, pileA->value);
		pileA = ft_free_stack(pileA);
        //tab = ft_free_stack(tab);
        count++; 
    }
    //afficherPile(pileA, pileB, val);
    count = 0;
    while(count < i)
    {

        val = 0;
        tmp_pile = pileB;
        size_a = (ft_lstsize(pileB)) - 1;
        tab = ft_find_little_five(pileB, size_a);
        val = ft_calculate_pivot(pileB, tab, (ft_lstsize(pileB)) / 6);
        while(pileB->value < val)
        {
            pileB = ft_reverse_b(pileB);
        }
         //afficherPile(pileA, pileB, val);
         //sleep(2);
        pileA = ft_swap_between(pileA, pileB->value);
		pileB = ft_free_stack(pileB);
        //tab = ft_free_stack(tab);
        count++; 
    }
    pileA = ft_hundred(pileA);
    afficherPile(pileA, pileB, val);
    return (pileA);
}
