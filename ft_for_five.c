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

t_stack	*ft_parcing_five(t_stack *pile_a, t_stack *pile_b, int tmp)
{
	if (tmp == 3)
	{
		pile_a = ft_reverse_last(pile_a);
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_reverse(pile_a);
		pile_a = ft_reverse(pile_a);
	}
	else if (tmp == 2)
	{
		pile_a = ft_reverse(pile_a);
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_swap(pile_a);
		pile_a = ft_reverse_last(pile_a);
	}
	else if (tmp == 1)
	{
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_swap(pile_a);
	}
	else if (tmp == 0)
		pile_a = ft_swap_between(pile_a, pile_b->value);
	return (pile_a);
}

t_stack	*for_five(t_stack *pile_a, t_stack *pile_b)
{
	t_stack	*element;
	int		tmp;

	element = pile_a;
	tmp = 0;
	while (pile_b->value > element->value && tmp < 3)
	{
		element = element->next;
		tmp++;
	}
	if (element->value < pile_b->value)
	{
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_reverse(pile_a);
	}
	else
		pile_a = ft_parcing_five(pile_a, pile_b, tmp);
	return (pile_a);
}

t_stack	*only_five(t_stack *pile_a, t_stack *pile_b, int arg)
{
	t_stack	*element;

	if (arg == 4)
	{
		pile_a = for_four(pile_a, pile_b);
		return (pile_a);
	}
	pile_b = ft_swap_between_b(pile_b, pile_a->value);
	pile_a = ft_free_t_stack(pile_a);
	pile_b = ft_swap_between_b(pile_b, pile_a->value);
	pile_a = ft_free_t_stack(pile_a);
	pile_a = only_three(pile_a, arg);
	element = pile_a;
	pile_a = ft_for_four(pile_a, pile_b, element);
	pile_b = ft_free_t_stack(pile_b);
	if (arg == 5)
		pile_a = for_five(pile_a, pile_b);
	pile_b = ft_free_t_stack(pile_b);
	return (pile_a);
}
