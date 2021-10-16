#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

void	afficherPile(stack *pileA, stack *pileB, int pivot)
{
	if (pileA == NULL && pileB == NULL)
		exit(EXIT_FAILURE);
	    printf("Pile a --pivot = %d -- PileB\n", pivot);
	while (!is_empty_stack(pileA) || !is_empty_stack(pileB))
	{
		if (!is_empty_stack(pileA)){
		printf("[%d]  ---     ", pileA->value);
		pileA = pileA->next;
		} else {
		printf("        ");
		}
		if (!is_empty_stack(pileB)){
		printf("[%d]\n", pileB->value);
		pileB = pileB->next;
		}else {
		printf("    \n");
		}
	}
		    printf("--------------------------\n");

	return ;
}

int	main(int argc, char **argv)
{
	stack	*pile_a;
	stack	*pile_b;
	int		arg;
	char	*dest;

	arg = 0;
	pile_a = NULL;
	pile_b = NULL;
	if (argc <= 2)
		pile_a = ft_argc_min(argv, pile_a);
	else
		pile_a = ft_argc_max(argv, argc, pile_a);
    arg = ft_lstsize(pile_a);
    printf("oui");
    pile_a = tri_pile(pile_a, pile_b, argc);
    printf("oui");
    get_next_line( &dest); 
	afficherPile(pile_a, pile_b, 14);
	return (0);
}