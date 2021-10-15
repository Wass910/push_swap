/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:57:19 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:10:28 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int	is_empty_stack(stack *st)
{
	if (st == NULL)
		return (1);
	return (0);
}

stack	*empiler(stack *pile, int nombre)
{
	stack	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		exit(EXIT_FAILURE);
	element->value = nombre;
	element->next = pile;
	return (element);
}

stack	*clear_stack(stack *pile)
{
	stack	*element;

	if (is_empty_stack(pile))
		return (NULL);
	while (pile)
	{
		element = pile;
		pile = pile->next;
		free(element);
	}
	return (pile);
}

int	depiler(stack *pile)
{
	return (pile->value);
}

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

stack	*ft_next_number(stack *pile)
{
	stack	*tmp;

	tmp = pile;
	pile = pile->next;
	free(tmp);
	return (pile);
}

stack	*ft_free_stack(stack *pile)
{
	stack	*element;

	element = pile->next;
	free(pile);
	return (element);
}

int	ft_lstsize(stack *pileA)
{
	int	size;

	size = 0;
	while (pileA)
	{
		++size;
		pileA = pileA->next;
	}
	return (size);
}
