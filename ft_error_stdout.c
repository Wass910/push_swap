#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

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

void     ft_verif_double(stack *pile)
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
            {
                printf("ERROR\n");
                exit(EXIT_FAILURE);
            }
            pile_tmp = pile_tmp->next;
        }
        pile = pile->next;
    }
    return ;
}