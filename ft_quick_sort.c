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

int	ft_calculate_pivot(t_stack *pile, t_stack *tab, int size)
{
	int		i;
	t_stack	*tmp_pile;
	t_stack	*tmp_tab;

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

t_stack	*ft_quick_sort_a(t_stack *pile_a, t_stack *pile_b, int i)
{
	int		count;
	t_stack	*tab;
	int		val;
	int		size_a;

	count = 0;
	while (count < i)
	{
		val = 0;
		size_a = (ft_lstsize(pile_a)) - 1;
		tab = ft_index(pile_a, size_a);
		val = ft_calculate_pivot(pile_a, tab, (ft_lstsize(pile_a)) / 2);
		while (pile_a->value > val)
			pile_a = ft_reverse(pile_a);
		pile_b = ft_swap_between_b(pile_b, pile_a->value);
		pile_a = ft_free_t_stack(pile_a);
		while (tab)
			tab = ft_free_t_stack(tab);
		count++;
	}
	return (pile_b);
}

t_stack	*ft_quick_sort_b(t_stack *pile_a, t_stack *pile_b, int i, int pivot)
{
	int		count;
	t_stack	*tab;
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
		pile_a = ft_swap_between(pile_a, pile_b->value);
		pile_b = ft_free_t_stack(pile_b);
		while (tab)
			tab = ft_free_t_stack(tab);
		count++;
	}
	return (pile_a);
}

t_stack	*ft_parcing_all(t_stack *pile_a, t_stack *pile_b, int what_pivot)
{
	int		i;
	t_stack	*tmp_pile_a;

	tmp_pile_a = NULL;
	i = ft_lstsize(pile_a);
	pile_b = ft_quick_sort_a(pile_a, pile_b, i);
	tmp_pile_a = ft_quick_sort_b(tmp_pile_a, pile_b, i, what_pivot);
	tmp_pile_a = ft_hundred(tmp_pile_a);
	return (tmp_pile_a);
}
