/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:26:29 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:26:33 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_swap_check(t_stack *pile)
{
	t_stack	*element;
	t_stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, pile->value);
	tmp = empiler(tmp, pile->next->value);
	pile->value = tmp->value;
	pile->next->value = element->value;
	free(element);
	free(tmp);
	return (pile);
}

t_stack	*ft_reverse_tmp(t_stack *pile)
{
	t_stack	*element;
	t_stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	return (tmp);
}

t_stack	*ft_reverse_last_check(t_stack *pile)
{
	t_stack	*element;
	t_stack	*tmp;
	t_stack	*final;

	final = NULL;
	tmp = NULL;
	element = NULL;
	tmp = pile;
	while (tmp->next)
		tmp = tmp->next;
	while (pile->next)
	{
		element = empiler(element, pile->value);
		pile = ft_next_number(pile);
	}
	while (element)
	{
		final = empiler(final, element->value);
		element = ft_next_number(element);
	}
	final = ft_add_front(&final, tmp);
	return (final);
}

t_stack	*ft_swap_between_tmp(t_stack *pile_more, int add)
{
	t_stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	return (pile_more);
}

t_stack	*tri_pile(t_stack *pileA, t_stack *pile_b, int arg)
{
	if (arg == 2 || arg == 3)
		pileA = only_three(pileA, arg);
	else if (arg > 3 && arg < 6)
		pileA = only_five(pileA, pile_b, arg);
	else if (arg >= 6 && arg <= 10)
		pileA = ft_hundred(pileA);
	else if (arg > 10 && arg <= 300)
		pileA = ft_parcing_all(pileA, pile_b, 5);
	else if (arg > 300)
		pileA = ft_parcing_all(pileA, pile_b, 11);
	while (pileA)
		pileA = ft_free_t_stack(pileA);
	return (pileA);
}
