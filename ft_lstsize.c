#include "push_swap.h"

int	ft_lstsize(t_stack *pile_a)
{
	int	size;

	size = 0;
	while (pile_a)
	{
		++size;
		pile_a = pile_a->next;
	}
	return (size);
}
