/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:29:10 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:37:13 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_morceaux(stack *pile, int tmp)
{
	while (pile)
	{
		if (tmp > pile->value)
		{
			tmp = pile->value;
		}
		pile = pile->next;
	}
	return (tmp);
}

int	ft_norme_opti_for_i(stack *pile, int i)
{
	if (pile->value > i)
		i = pile->value;
	else
	{
		while (pile->value <= i && pile != NULL)
			pile = pile->next;
		i = pile->value;
	}
	return (i);
}

int	ft_morceaux_suite(stack *pile, int tmp)
{
	int	i;
	int	fin;
	int	first_elem_litle;

	first_elem_litle = 0;
	i = tmp;
	i = ft_norme_opti_for_i(pile, i);
	while (pile)
	{
		if (pile->value < i && pile->value > tmp)
		{
			first_elem_litle++;
			fin = pile->value;
			i = fin;
		}
		pile = pile->next;
	}
	if (first_elem_litle == 0)
		return (i);
	return (fin);
}

stack	*ft_norme_for_tritab(int count, int tmp, stack *tmp_tab, stack *tab)
{
	while (count > 0)
	{
		tmp = ft_morceaux_suite(tab, tmp);
		tmp_tab = empiler(tmp_tab, tmp);
		count--;
	}
	return (tmp_tab);
}

stack	*ft_tri_tab(stack *tab)
{
	int		i;
	int		tmp;
	int		count;
	stack	*tmp_tab;
	stack	*final;

	count = 44;
	tmp_tab = NULL;
	final = NULL;
	tmp = tab->value;
	tmp = ft_morceaux(tab, tmp);
	tmp_tab = empiler(tmp_tab, tmp);
	tmp_tab = ft_norme_for_tritab(count, tmp, tmp_tab, tab);
	count = 0;
	while (count < 45)
	{
		final = ft_swap_between_tmp(final, tmp_tab->value);
		tmp_tab = ft_free_stack(tmp_tab);
		count++;
	}
	return (final);
}

stack	*ft_norme_for_find_litle(stack *tmp_elem, stack *element, stack *pileA, stack *tab, int tmp)
{
	int	pos;
	int	count;

	count = 44;
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

stack	*ft_find_little(stack *pileA, int count)
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
	tab = ft_norme_for_find_litle(tmp_elem, element, pileA, tab, tmp);
	return (tab);
}

stack	*ft_norme_for_optihundred(stack *pileA, stack *pileB)
{
	int	i;

	i = 0;
	while (i < 45)
	{
		pileB = ft_reverse_last_b(pileB);
		pileA = ft_swap_between(pileA, pileB->value);
		pileB = ft_free_stack(pileB);
		i++;
	}
	return (pileA);
}

stack	*ft_opti_hundred(stack *pileA)
{
	int		i;
	stack	*tab;
	stack	*pileB;

	pileB = NULL;
	i = 1;
	tab = ft_find_little(pileA, 44);
	tab = ft_tri_tab(tab);
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
	pileA = ft_norme_for_optihundred(pileA, pileB);
	return (pileA);
}
