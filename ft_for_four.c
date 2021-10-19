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

t_stack	*ft_for_tmp_two(t_stack *pile_a, int i)
{
	pile_a = ft_reverse_last(pile_a);
	pile_a = ft_swap_between(pile_a, i);
	pile_a = ft_reverse_last(pile_a);
	pile_a = ft_reverse_last(pile_a);
	return (pile_a);
}

t_stack	*ft_for_four(t_stack *pile_a, t_stack *pile_b, t_stack *element)
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
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_reverse(pile_a);
	}
	else if (tmp == 2)
		pile_a = ft_for_tmp_two(pile_a, pile_b->value);
	else if (tmp == 1)
	{
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_a = ft_swap(pile_a);
	}
	else if (tmp == 0)
		pile_a = ft_swap_between(pile_a, pile_b->value);
	return (pile_a);
}

t_stack	*for_four(t_stack *pile_a, t_stack *pile_b)
{
	t_stack	*element;

	pile_b = ft_swap_between_b(pile_b, pile_a->value);
	pile_a = ft_free_t_stack(pile_a);
	pile_a = only_three(pile_a, 1);
	element = pile_a;
	pile_a = ft_for_four(pile_a, pile_b, element);
	pile_b = ft_free_t_stack(pile_b);
	return (pile_a);
}
