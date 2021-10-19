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

t_stack	*ft_for_two(t_stack *pile_a)
{
	t_stack	*element;

	element = pile_a->next;
	if (pile_a->value > element->value)
		pile_a = ft_swap(pile_a);
	return (pile_a);
}

t_stack	*ft_norme_for_three(t_stack *pile_a, t_stack *element)
{
	if (pile_a->value > element->next->value)
		pile_a = ft_reverse_last(pile_a);
	else
	{
		pile_a = ft_swap(pile_a);
		pile_a = ft_reverse(pile_a);
	}
	return (pile_a);
}

t_stack	*only_three(t_stack *pile_a, int arg)
{
	t_stack	*elem;

	elem = pile_a->next;
	if (arg == 2)
		return (ft_for_two(pile_a));
	if (elem->value > pile_a->value && elem->value > elem->next->value)
		pile_a = ft_norme_for_three(pile_a, elem);
	else if (elem->value < pile_a->value && elem->value > elem->next->value)
	{
		pile_a = ft_swap(pile_a);
		pile_a = ft_reverse_last(pile_a);
	}
	else if (pile_a->value > elem->next->value)
		pile_a = ft_reverse(pile_a);
	else if (pile_a->value < elem->next->value && pile_a->value > elem->value)
		pile_a = ft_swap(pile_a);
	return (pile_a);
}
