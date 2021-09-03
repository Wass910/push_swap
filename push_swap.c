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
        if(str[i] == '-')
            i++;
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
    int     arg;
    char **dest;
    int i = 0;

    arg = 0;
    pileA = NULL;
    pileB = NULL;
    if(argc <= 2)
    {
        dest = ft_split(argv[1], ' ');
        while(dest[i] != NULL)
            i++;
        arg = i;
        i--;
        if(i < 2)
        {
            return 0;
        }
        else
        {
           while(i >= 0)
            {
                pileA = empiler(pileA, ft_atoi(dest[i]));
                i--;
            }
        }
    }
    else
    {
        while(argc > 1)
        {
            dest = ft_split(argv[argc - 1], ' ');
            while(dest[i] != NULL)
                i++;
            i--;
            while(i >= 0)
            {
                pileA = empiler(pileA, ft_atoi(dest[i]));
                arg++;
                i--;
            }
            //if(argv[argc - 1][0] == '"')
            //    printf("salut");
            //if(ft_is_digit(argv[argc - 1]) == 1)
            //{
            //    printf("ERROR\n");
            //    return 0;
            //}
            //pileA = empiler(pileA, ft_atoi(argv[argc - 1]));
            i = 0;
            argc--;
        }  
        if(ft_verif_double(pileA) == 1)
        {
            printf("ERROR\n");
            clear_stack(pileA);
           return 0;
        }
    }
    printf("arg = %d", arg);
    pileA = tri_pile(pileA,pileB, arg);
    clear_stack(pileA);
    return 0;
}