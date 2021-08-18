#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int     is_empty_stack(stack *st)
{
    if(st == NULL)
        return (1);
    return (0);
}

stack   *empiler(stack *pile, int nombre)
{
    stack *element;

    element = malloc(sizeof(*element));
    if(element == NULL)
        exit(EXIT_FAILURE);
    element->value = nombre;
    element->next = pile;
    
    return (element);
}

stack   *clear_stack(stack *pile)
{
    stack *element;
    if(is_empty_stack(pile))
        return NULL;
    while(pile)
    {
        element = pile;
        pile = pile->next;
        free(element);
    }
    return (pile);
}

int   depiler(stack *pile)
{
    return (pile->value);
}

void    afficherPile(stack *pile)
{
    if (pile == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while(!is_empty_stack(pile))
    {
        printf("[%d]\n", pile->value);
        pile = pile->next;
    }
    return ; 
}

int     ft_is_digit(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return 1;
        i++; 
    }
    return 0;
}

int     ft_verif_double(stack *pile)
{
    stack   *pile_tmp;
    int     val;

    while(pile)
    {
        pile_tmp = pile->next;
        val = pile->value;
        while(pile_tmp)
        {
            if(val == pile_tmp->value)
                return (1);
            pile_tmp = pile_tmp->next;
        }
        pile = pile->next;
    }
    return (0);
}

int main(int argc, char **argv)
{
    stack   *pileA;
    stack   *pileB;

    pileA = NULL;
    pileB = NULL;
    while(argc > 1)
    {
        if(ft_is_digit(argv[argc - 1]) == 1)
        {
            printf("ERROR\n");
            //fflush(stdout);
	        //system("leaks a.out | grep 'Process'");
            return 0;
        }
        pileA = empiler(pileA, ft_atoi(argv[argc - 1]));
        argc--;
    }
    if(ft_verif_double(pileA) == 1)
    {
        printf("ERROR\n");
        clear_stack(pileA);
        //fflush(stdout);
	    //system("leaks a.out | grep 'Process'");
        return 0;
    }
    /*pileB = empiler(pileB, 1);
    pileB = empiler(pileB, 2);
    pileB = empiler(pileB, 3);
    pileB = empiler(pileB, 4);
    pileB = empiler(pileB, 5);
    pileB = empiler(pileB, 6);
    pileB = empiler(pileB, 7);
   */
    pileA = tri_pile(pileA,pileB);
    //afficherPile(pileA);
    clear_stack(pileA);
    fflush(stdout);
	system("leaks a.out | grep 'Process'");
    return 0;
}