/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:19:26 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:24:29 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_norme_for_tritab_less(int c, int tmp, stack *tmp_tab, stack *tab)
{
	while (c > 0)
	{
		tmp = ft_morceaux_suite(tab, tmp);
		tmp_tab = empiler(tmp_tab, tmp);
		c--;
	}
	return (tmp_tab);
}

stack	*ft_tri_tab_less(stack *tab, int count)
{
	int		i;
	int		sec_count;
	int		tmp;
	stack	*tmp_tab;
	stack	*final;

	sec_count = count + 1;
	tmp_tab = NULL;
	final = NULL;
	tmp = tab->value;
	tmp = ft_morceaux(tab, tmp);
	tmp_tab = empiler(tmp_tab, tmp);
	tmp_tab = ft_norme_for_tritab_less(count, tmp, tmp_tab, tab);
	count = 0;
	while (count < sec_count)
	{
		final = ft_swap_between_tmp(final, tmp_tab->value);
		tmp_tab = ft_free_stack(tmp_tab);
		count++;
	}
	return (final);
}

stack	*ft_norme_for_find_litle_less(stack *tmp_elem, stack *element, stack *pileA, stack *tab, int tmp)
{
	int	pos;
	int	count;

	count = (ft_lstsize(pileA) / 2) - 1;
	while (count > 0)
	{
		pos = 1;
		tmp = ft_morceaux_suite(tmp_elem, tmp);
		while (element->value != tmp)
		{
			pos++;
			element = element->next;
		}
		element = pileA;
		tab = empiler(tab, pos);
		count--;
	}
	return (tab);
}

stack	*ft_find_little_less(stack *pileA, int count)
{
	stack	*tmp_elem;
	stack	*tab;
	stack	*element;
	int		tmp;
	int		pos;

	tab = NULL;
	tmp_elem = pileA;
	element = pileA;
	tmp = tmp_elem->value;
	tmp = ft_morceaux(tmp_elem, tmp);
	pos = 1;
	while (element->value != tmp)
	{
		pos++;
		element = element->next;
	}
	tab = empiler(tab, pos);
	element = pileA;
	tab = ft_norme_for_find_litle_less(tmp_elem, element, pileA, tab, tmp);
	return (tab);
}

stack	*ft_norme_for_lesshundred(stack *pileA, stack *pileB)
{
	while (pileB)
	{
		pileB = ft_reverse_last_b(pileB);
		pileA = ft_swap_between(pileA, pileB->value);
		pileB = ft_free_stack(pileB);
	}
	return (pileA);
}

stack	*ft_less_hundred(stack *pileA)
{
	int		i;
	stack	*tab;
	stack	*pileB;

	i = 1;
	pileB = NULL;
	tab = ft_find_little_less(pileA, ((ft_lstsize(pileA) / 2) - 1));
	tab = ft_tri_tab_less(tab, ((ft_lstsize(pileA) / 2) - 1));
	while (tab)
	{
		if (tab->value == i)
		{
			pileB = ft_swap_between_b(pileB, pileA->value);
			pileA = ft_free_stack(pileA);
			tab = tab->next;
		}
		else
			pileA = ft_reverse(pileA);
		i++;
	}
	pileB = ft_hundred_b(pileB);
	pileA = ft_hundred(pileA);
	pileA = ft_norme_for_lesshundred(pileA, pileB);
	return (pileA);
}
