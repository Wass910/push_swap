/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:40:33 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:43:53 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_swap(stack *pile)
{
	stack	*element;
	stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, pile->value);
	tmp = empiler(tmp, pile->next->value);
	pile->value = tmp->value;
	pile->next->value = element->value;
	free(element);
	free(tmp);
	printf("sa\n");
	return (pile);
}

stack	*ft_swap_b(stack *pile)
{
	stack	*element;
	stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, pile->value);
	tmp = empiler(tmp, pile->next->value);
	pile->value = tmp->value;
	pile->next->value = element->value;
	free(element);
	free(tmp);
	printf("sb\n");
	return (pile);
}

stack	*ft_add_back(stack **alst, stack *new)
{
	stack	*tmp;

	tmp = *alst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = NULL;
	return (tmp);
}

stack	*ft_reverse_tmp(stack *pile)
{
	stack	*element;
	stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	return (tmp);
}

stack	*ft_reverse(stack *pile)
{
	stack	*element;
	stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	printf("ra\n");
	return (tmp);
}

stack	*ft_reverse_b(stack *pile)
{
	stack	*element;
	stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	printf("rb\n");
	return (tmp);
}

stack	*ft_add_front(stack **alst, stack *new)
{
	stack	*tmp;

	tmp = NULL;
	tmp = *alst;
	new->next = tmp;
	tmp = new;
	return (tmp);
}

stack	*ft_reverse_last(stack *pile)
{
	stack	*element;
	stack	*tmp;
	stack	*final;

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
	printf("rra\n");
	return (final);
}

stack	*ft_reverse_last_b(stack *pile)
{
	stack	*element;
	stack	*tmp;
	stack	*final;

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
	printf("rrb\n");
	return (final);
}

stack	*ft_swap_between(stack *pile_more, int add)
{
	stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	printf("pa\n");
	return (pile_more);
}

stack	*ft_swap_between_tmp(stack *pile_more, int add)
{
	stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	return (pile_more);
}

stack	*ft_swap_between_b(stack *pile_more, int add)
{
	stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	printf("pb\n");
	return (pile_more);
}

stack	*tri_pile(stack *pileA, stack *pileB, int arg)
{
	if (arg == 2 || arg == 3)
		pileA = only_three(pileA, arg);
	else if (arg > 3 && arg < 6)
		pileA = only_five(pileA, pileB, arg);
	else if (arg >= 6 && arg <= 10)
		pileA = ft_hundred(pileA);
	else if (arg > 10 && arg <= 300)
		pileA = ft_new_algo(pileA, pileB, 5);
	else if (arg > 300)
		pileA = ft_new_algo(pileA, pileB, 11);
	free(pileB);
	return (pileA);
}
