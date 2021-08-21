#include "push_swap.h"

stack   *ft_next_number(stack *pile)
{
    stack *tmp;

    tmp = pile;
    pile = pile->next;
    free(tmp);
    return (pile);
}

stack   *ft_free_stack(stack *pile)
{
    stack *element;

    element = pile->next;
    free(pile);
    return(element);
}

stack   *ft_swap(stack *pile)
{
    stack *element;
    stack *tmp;
    
    tmp = NULL;
    element = NULL;
    element = empiler(element, pile->value);
    tmp = empiler(tmp, pile->next->value);
    pile->value = tmp->value;
    pile->next->value = element->value;
    free(element);
    free(tmp);
    printf("oui\n");
    return (pile);
}

stack   *ft_add_back(stack **alst, stack *new)
{
    stack *tmp;

    tmp = *alst;
    while(tmp->next)
    {
        tmp = tmp->next; 
    }
    tmp->next = new;
    new->next = NULL;
    return (tmp);
}

stack   *ft_reverse(stack *pile)
{
    stack *element;
    stack *tmp;

    tmp = NULL;
    element = NULL;
    element = empiler(element, depiler(pile));
    pile = ft_next_number(pile);
    tmp = pile;
    pile = ft_add_back(&tmp, element);
    printf("oui\n");
    return (tmp);
}

stack *ft_add_front(stack **alst, stack *new)
{
    stack *tmp;

    tmp = NULL;
    tmp = *alst;
    /*if(!(*alst))
    {
        *alst = new;
        return (*alst);
    }*/
    new->next = tmp;
    tmp = new;
    return(tmp);
}

stack   *ft_reverse_last(stack *pile)
{
    stack *element;
    stack *tmp;
    stack *final;

    final = NULL;
    tmp = NULL;
    element = NULL;
    tmp = pile;
    while(tmp->next)
        tmp = tmp->next;
    while(pile->next)
    {
        element = empiler(element, pile->value);
        pile = ft_next_number(pile);
    }
    while(element)
    {
        final = empiler(final, element->value);
        element = ft_next_number(element);
    }
    final = ft_add_front(&final, tmp);
    printf("oui\n");
    return (final);
}

stack    *ft_swap_between(stack *pile_more, int add)
{
    stack *element;

    element = NULL;
    element = empiler(element, add);
    pile_more = ft_add_front(&pile_more, element);
    printf("oui\n");
    return (pile_more);
}


stack    *tri_pile(stack *pileA, stack *pileB, int arg)
{
    if(arg == 3 || arg == 4)
        pileA = only_three(pileA, arg);
    else if(arg > 4 && arg < 7)
        pileA = only_five(pileA, pileB, arg);
    else
        pileA = ft_hundred(pileA, pileB);
    //printf("\nEtat de la pile B:\n");

    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileB);
    
    //pileB = ft_swap_between(pileB, pileA->value);
    //pileA = ft_free_stack(pileA);
    //pileA = only_three(pileA, pileB, arg);
    //pileA = ft_swap(pileA);

    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    
    //pileA = ft_swap(pileA);
    //printf("\nEtat de la pile B:\n");
    //afficherPile(pileB);

    printf("Etat de la pile A:\n");
    afficherPile(pileA);

    //pileA = ft_reverse_last(pileA);
    //printf("\nEtat de la pile A:\n");
    //afficherPile(pileA);
    //if(pileA->value > pileA->next->value)
    //printf("%d\n", element);
    free(pileB);
    return (pileA);
}