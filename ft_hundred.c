/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:19:05 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:19:13 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_tri_hundred(stack *pileA, int pos, int i)
{
	if ((pos / 2) <= i)
	{
		while (i < pos)
		{
			pileA = ft_reverse_last(pileA);
			i++;
		}
	}
	else
	{
		while (i > 1)
		{
			pileA = ft_reverse(pileA);
			i--;
		}
	}
	return (pileA);
}

int	ft_what_position(int i, int pos, stack *element)
{
	int	tmp;

	tmp = element->value;
	while (element)
	{
		if (tmp > element->value)
		{
			tmp = element->value;
			i = pos;
		}
		pos++;
		element = element->next;
	}
	return (i);
}

stack	*ft_hundred(stack *pileA)
{
	int		i;
	stack	*element;
	stack	*pile_b;

	pile_b = NULL;
	element = pileA;
	while (pileA)
	{
		i = ft_what_position(1, 1, element);
		pileA = ft_tri_hundred(pileA, ft_lstsize(pileA) + 1, i);
		pile_b = ft_swap_between_b(pile_b, pileA->value);
		pileA = ft_free_stack(pileA);
		element = pileA;
	}
	while (pile_b)
	{
		pileA = ft_swap_between(pileA, pile_b->value);
		pile_b = ft_free_stack(pile_b);
	}
	return (pileA);
}
