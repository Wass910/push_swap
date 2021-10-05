/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_three.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:14:35 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:17:09 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_for_two(stack *pileA)
{
	stack	*element;

	element = pileA->next;
	if (pileA->value > element->value)
		pileA = ft_swap(pileA);
	return (pileA);
}

stack	*ft_norme_for_three(stack *pileA, stack *element)
{
	if (pileA->value > element->next->value)
		pileA = ft_reverse_last(pileA);
	else
	{
		pileA = ft_swap(pileA);
		pileA = ft_reverse(pileA);
	}
	return (pileA);
}

stack	*only_three(stack *pileA, int arg)
{
	stack	*elem;

	elem = pileA->next;
	if (arg == 2)
		return (ft_for_two(pileA));
	if (elem->value > pileA->value && elem->value > elem->next->value)
		pileA = ft_norme_for_three(pileA, elem);
	else if (elem->value < pileA->value && elem->value > elem->next->value)
	{
		pileA = ft_swap(pileA);
		pileA = ft_reverse_last(pileA);
	}
	else if (pileA->value > elem->next->value)
		pileA = ft_reverse(pileA);
	else if (pileA->value < elem->next->value && pileA->value > elem->value)
		pileA = ft_swap(pileA);
	return (pileA);
}
