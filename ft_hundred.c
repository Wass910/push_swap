/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hundred.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 10:49:31 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 10:49:35 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_tri_hundred(t_stack *pile_a, int pos, int i)
{
	if ((pos / 2) <= i)
	{
		while (i < pos)
		{
			pile_a = ft_reverse_last(pile_a);
			i++;
		}
	}
	else
	{
		while (i > 1)
		{
			pile_a = ft_reverse(pile_a);
			i--;
		}
	}
	return (pile_a);
}

int	ft_what_position(int i, int pos, t_stack *element)
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

t_stack	*ft_hundred(t_stack *pile_a)
{
	int		i;
	t_stack	*element;
	t_stack	*pile_b;

	pile_b = NULL;
	element = pile_a;
	while (pile_a)
	{
		i = ft_what_position(1, 1, element);
		pile_a = ft_tri_hundred(pile_a, ft_lstsize(pile_a) + 1, i);
		pile_b = ft_swap_between_b(pile_b, pile_a->value);
		pile_a = ft_free_t_stack(pile_a);
		element = pile_a;
	}
	while (pile_b)
	{
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_b = ft_free_t_stack(pile_b);
	}
	return (pile_a);
}
