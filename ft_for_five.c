/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_five.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:51:39 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:12:42 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_parcing_five(stack *pileA, stack *pile_b, int tmp)
{
	if (tmp == 3)
	{
		pileA = ft_reverse_last(pileA);
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_reverse(pileA);
		pileA = ft_reverse(pileA);
	}
	else if (tmp == 2)
	{
		pileA = ft_reverse(pileA);
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_swap(pileA);
		pileA = ft_reverse_last(pileA);
	}
	else if (tmp == 1)
	{
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_swap(pileA);
	}
	else if (tmp == 0)
		pileA = ft_swap_between(pileA, pile_b->value);
	return (pileA);
}

stack	*for_five(stack *pileA, stack *pile_b)
{
	stack	*element;
	int		tmp;

	element = pileA;
	tmp = 0;
	while (pile_b->value > element->value && tmp < 3)
	{
		element = element->next;
		tmp++;
	}
	if (element->value < pile_b->value)
	{
		pileA = ft_swap_between(pileA, pile_b->value);
		pileA = ft_reverse(pileA);
	}
	else
		pileA = ft_parcing_five(pileA, pile_b, tmp);
	return (pileA);
}

stack	*only_five(stack *pileA, stack *pile_b, int arg)
{
	stack	*element;
	int		tmp;

	tmp = 0;
	if (arg == 4)
	{
		pileA = for_four(pileA, pile_b);
		return (pileA);
	}
	pile_b = ft_swap_between_b(pile_b, pileA->value);
	pileA = ft_free_stack(pileA);
	pile_b = ft_swap_between_b(pile_b, pileA->value);
	pileA = ft_free_stack(pileA);
	pileA = only_three(pileA, arg);
	element = pileA;
	pileA = ft_for_four(pileA, pile_b, element);
	pile_b = ft_free_stack(pile_b);
	if (arg == 5)
		pileA = for_five(pileA, pile_b);
	pile_b = ft_free_stack(pile_b);
	return (pileA);
}
