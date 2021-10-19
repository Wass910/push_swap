/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:45:29 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 10:45:31 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_back(t_stack **alst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *alst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	new->next = NULL;
	return (tmp);
}

t_stack	*ft_swap(t_stack *pile)
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
	ft_putstr("sa\n");
	return (pile);
}

t_stack	*ft_swap_b(t_stack *pile)
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
	ft_putstr("sb\n");
	return (pile);
}

t_stack	*ft_reverse(t_stack *pile)
{
	t_stack	*element;
	t_stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	ft_putstr("ra\n");
	return (tmp);
}

t_stack	*ft_reverse_b(t_stack *pile)
{
	t_stack	*element;
	t_stack	*tmp;

	tmp = NULL;
	element = NULL;
	element = empiler(element, depiler(pile));
	pile = ft_next_number(pile);
	tmp = pile;
	pile = ft_add_back(&tmp, element);
	ft_putstr("rb\n");
	return (tmp);
}
