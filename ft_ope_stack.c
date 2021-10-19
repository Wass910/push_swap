/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ope_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:57:19 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:10:28 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

int	is_empty_t_stack(t_stack *st)
{
	if (st == NULL)
		return (1);
	return (0);
}

t_stack	*empiler(t_stack *pile, int nombre)
{
	t_stack	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		exit(EXIT_FAILURE);
	element->value = nombre;
	element->next = pile;
	return (element);
}

t_stack	*clear_t_stack(t_stack *pile)
{
	t_stack	*element;

	if (is_empty_t_stack(pile))
		return (NULL);
	while (pile)
	{
		element = pile;
		pile = pile->next;
		free(element);
	}
	return (pile);
}

t_stack	*ft_next_number(t_stack *pile)
{
	t_stack	*tmp;

	tmp = pile;
	pile = pile->next;
	free(tmp);
	return (pile);
}

t_stack	*ft_free_t_stack(t_stack *pile)
{
	t_stack	*element;

	element = pile->next;
	free(pile);
	return (element);
}
