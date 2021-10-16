/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_four.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:13:04 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:14:18 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_for_tmp_two(stack *pileA, int i)
{
	pileA = ft_reverse_last(pileA);
	pileA = ft_swap_between(pileA, i);
	pileA = ft_reverse_last(pileA);
	pileA = ft_reverse_last(pileA);
	return (pileA);
}

stack	*ft_for_four(stack *pileA, stack *pile_b, stack *element)
{
	int	tmp;

	tmp = 0;
	while (pile_b->value > element->value && tmp < 2)
	{
		element = element->next;
		tmp++;
	}
	if (element->value < pile_b->value)
	{
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_reverse(pileA);
	}
	else if (tmp == 2)
		pileA = ft_for_tmp_two(pileA, pile_b->value);
	else if (tmp == 1)
	{
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_swap(pileA);
	}
	else if (tmp == 0)
		pileA = ft_swap_between(pileA, pile_b->value);
	return (pileA);
}

stack	*for_four(stack *pileA, stack *pile_b)
{
	stack	*element;

	pile_b = ft_swap_between_b(pile_b, pileA->value);
	pileA = ft_free_stack(pileA);
	pileA = only_three(pileA, 1);
	element = pileA;
	pileA = ft_for_four(pileA, pile_b, element);
	pile_b = ft_free_stack(pile_b);
	return (pileA);
}
