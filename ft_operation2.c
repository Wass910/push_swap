/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:45:38 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 10:45:39 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_front(t_stack **alst, t_stack *new)
{
	t_stack	*tmp;

	tmp = NULL;
	tmp = *alst;
	new->next = tmp;
	tmp = new;
	return (tmp);
}

t_stack	*ft_reverse_last(t_stack *pile)
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
	ft_putstr("rra\n");
	return (final);
}

t_stack	*ft_reverse_last_b(t_stack *pile)
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
	ft_putstr("rrb\n");
	return (final);
}

t_stack	*ft_swap_between(t_stack *pile_more, int add)
{
	t_stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	ft_putstr("pa\n");
	return (pile_more);
}

t_stack	*ft_swap_between_b(t_stack *pile_more, int add)
{
	t_stack	*element;

	element = NULL;
	element = empiler(element, add);
	pile_more = ft_add_front(&pile_more, element);
	ft_putstr("pb\n");
	return (pile_more);
}
