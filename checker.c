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

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= 0)
		return (0);
	while (n > 1 && (*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

stack	*ft_verification(char *str, stack *pileA, stack *pileB)
{
	afficherPile(pileA, pileB, 12);
	if(ft_strncmp(str, "pa", 2) == 0)
	{
		pileA = ft_swap_between_tmp(pileA, pileB->value);
	}
	else if (ft_strncmp(str, "pb", 2) == 0)
	{
		pileB = ft_swap_between_tmp(pileB, pileA->value);
		pileA = ft_free_stack(pileA);
	}
	else if (ft_strncmp(str, "pb", 2) == 0)
		pileB = ft_swap_check(pileB);
	else if (ft_strncmp(str, "pa", 2) == 0)
		pileA = ft_swap_check(pileA);
	else if (ft_strncmp(str, "rb", 2) == 0)
		pileB = ft_reverse_tmp(pileB);
	else if (ft_strncmp(str, "ra", 2) == 0)
		pileA = ft_reverse_tmp(pileA);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		pileB = ft_reverse_last_check(pileB);
	else if (ft_strncmp(str, "rra", 3) == 0)
		pileA = ft_reverse_last_check(pileA);

	return (pileA);
}

void	ft_check(char *line, int count, stack *pileA)
{
	char tmp[4];
	int i = 0;
	int ope = 0;
	stack	*pileB = NULL;

	while(count > 1)
	{
		while(line[ope] != '\n' && line[ope] != '\0')
		{
			tmp[i] = line[ope];
			i++;
			ope++;
		}
		tmp[i] = '\0';
		count--;
		i = 0;
		ope++;
		if(ft_strncmp(tmp, "pa", 2) == 0)
	{
		pileA = ft_swap_between_tmp(pileA, pileB->value);
		pileB = pileB->next;
	}
	else if (ft_strncmp(tmp, "pb", 2) == 0)
	{
		pileB = ft_swap_between_tmp(pileB, pileA->value);
		pileA = ft_free_stack(pileA);
	}
	else if (ft_strncmp(tmp, "pb", 2) == 0)
		pileB = ft_swap_check(pileB);
	else if (ft_strncmp(tmp, "pa", 2) == 0)
		pileA = ft_swap_check(pileA);
	else if (ft_strncmp(tmp, "rb", 2) == 0)
		pileB = ft_reverse_tmp(pileB);
	else if (ft_strncmp(tmp, "ra", 2) == 0)
		pileA = ft_reverse_tmp(pileA);
	else if (ft_strncmp(tmp, "rrb", 3) == 0)
		pileB = ft_reverse_last_check(pileB);
	else if (ft_strncmp(tmp, "rra", 3) == 0)
		pileA = ft_reverse_last_check(pileA);
		afficherPile(pileA, pileB, count);
	}
	afficherPile(pileA, pileB, count);
}
void	how_many(char *line, stack *pile)
{
	char *tmp;
	int i;
	int count;

	tmp = NULL;
	while (line[i] != '\0')
	{
		i++;
		if (line[i] == '\n')
			count++;
	}
	ft_check(line, count, pile);
}

int main(int argc, char **argv)
{
    stack	*pileA;
	stack	*pileB;
	stack	*pile_checker;
	int		arg;
	char	*line;
	int ret;

	arg = 0;
	pile_checker = NULL;
	pileA = NULL;
	pileB = NULL;
	if (argc <= 2)
		pileA = ft_argc_min(argv, pileA);
	else
		pileA = ft_argc_max(argv, argc, pileA);
	if (argc <= 2)
		pile_checker = ft_argc_min(argv, pile_checker);
	else
		pile_checker = ft_argc_max(argv, argc, pile_checker);
	arg = ft_lstsize(pileA);
	if ((ft_is_order(pileA)) == 0 )
	{
		clear_stack(pileA);
		exit(EXIT_FAILURE);
	}
	pileA = tri_pile(pileA, pileB, arg);
	line = ft_putstr("oui", 1);
	how_many(line, pile_checker);
	return 0;
}