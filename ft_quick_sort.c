/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:28:05 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/16 18:54:37 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_calculate_pivot(stack *pile, stack *tab, int size)
{
	int		i;
	stack	*tmp_pile;
	stack	*tmp_tab;

	i = 0;
	tmp_pile = pile;
	tmp_tab = tab;
	while (tmp_tab && i < size)
	{
		tmp_tab = tmp_tab->next;
		i++;
	}
	i = tmp_tab->value;
	while (tmp_pile && i > 1)
	{
		tmp_pile = tmp_pile->next;
		i--;
	}
	return (tmp_pile->value);
}

stack	*ft_quick_sort_a(stack *pileA, stack *pile_b, int i)
{
	int		count;
	stack	*tab;
	int		val;
	int		size_a;

	count = 0;
	while (count < i)
	{
		val = 0;
		size_a = (ft_lstsize(pileA)) - 1;
		tab = ft_index(pileA, size_a);
		val = ft_calculate_pivot(pileA, tab, (ft_lstsize(pileA)) / 2);
		while (pileA->value > val)
			pileA = ft_reverse(pileA);
		pile_b = ft_swap_between_b(pile_b, pileA->value);
		pileA = ft_free_stack(pileA);
		while (tab)
			tab = ft_free_stack(tab);
		count++;
	}
	return (pile_b);
}

stack	*ft_quick_sort_b(stack *pileA, stack *pile_b, int i, int pivot)
{
	int		count;
	stack	*tab;
	int		val;
	int		size_a;

	count = 0;
	while (count < i)
	{
		val = 0;
		size_a = (ft_lstsize(pile_b)) - 1;
		tab = ft_index(pile_b, size_a);
		val = ft_calculate_pivot(pile_b, tab, (ft_lstsize(pile_b)) / pivot);
		while (pile_b->value < val)
			pile_b = ft_reverse_b(pile_b);
		pileA = ft_swap_between(pileA, pile_b->value);
		pile_b = ft_free_stack(pile_b);
		while (tab)
			tab = ft_free_stack(tab);
		count++;
	}
	return (pileA);
}

stack	*ft_parcing_all(stack *pileA, stack *pile_b, int what_pivot)
{
	int		i;
	stack	*tmp_pilea;

	tmp_pilea = NULL;
	i = ft_lstsize(pileA);
	pile_b = ft_quick_sort_a(pileA, pile_b, i);
	tmp_pilea = ft_quick_sort_b(tmp_pilea, pile_b, i, what_pivot);
	tmp_pilea = ft_hundred(tmp_pilea);
	return (tmp_pilea);
}
