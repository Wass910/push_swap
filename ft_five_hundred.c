/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_five_hundred.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:01:56 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/16 18:12:49 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_norme_for_index(t_stack *pile_a, t_stack *tab, int tmp, int count)
{
	int		pos;
	t_stack	*element;
	t_stack	*tmp_elem;

	element = pile_a;
	tmp_elem = pile_a;
	while (count > 0)
	{
		pos = 1;
		tmp = ft_morceaux_suite(tmp_elem, tmp);
		while (element->value != tmp)
		{
			pos++;
			element = element->next;
		}
		element = pile_a;
		tab = empiler(tab, pos);
		count--;
	}
	return (tab);
}

t_stack	*ft_index(t_stack *pile_a, int count)
{
	t_stack	*tmp_elem;
	t_stack	*tab;
	int		tmp;
	int		pos;

	tab = NULL;
	tmp_elem = pile_a;
	tmp = tmp_elem->value;
	tmp = ft_morceaux(tmp_elem, tmp);
	pos = 1;
	tmp_elem = pile_a;
	while (tmp_elem->value != tmp)
	{
		pos++;
		tmp_elem = tmp_elem->next;
	}
	tab = empiler(tab, pos);
	tab = ft_norme_for_index(pile_a, tab, tmp, count);
	return (tab);
}
