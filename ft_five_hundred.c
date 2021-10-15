#include "push_swap.h"

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
