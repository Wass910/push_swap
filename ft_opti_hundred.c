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
	if (pile && pile->value > i)
		i = pile->value;
	else
	{
		while (pile && pile->value <= i && pile != NULL)
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
