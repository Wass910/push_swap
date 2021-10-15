/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:37:33 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/05 15:40:07 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"
#include <stdio.h>

stack	*ft_fill_pile(int i, stack *pileA, char **dest)
{
	while (i >= 0)
	{
		if (ft_is_digit(dest[i]) == 1)
		{
			clear_stack(pileA);
			printf("ERROR\n");
			exit(EXIT_FAILURE);
		}
		pileA = empiler(pileA, ft_atoi(dest[i]));
		free(dest[i]);
		i--;
	}
	free(dest);
	return (pileA);
}

stack	*ft_argc_max(char **argv, int argc, stack *pileA)
{
	int		i;
	char	**dest;

	i = 0;
	while (argc > 1)
	{
		dest = ft_split(argv[argc - 1], ' ');
		while (dest[i] != NULL)
			i++;
		i--;
		pileA = ft_fill_pile(i, pileA, dest);
		i = 0;
		argc--;
	}
	return (pileA);
}

stack	*ft_argc_min(char **argv, stack *pileA)
{
	int		i;
	char	**dest;

	i = 0;
	dest = ft_split(argv[1], ' ');
	if (dest != NULL)
	{
		while (dest[i] != NULL)
			i++;
	}
	i--;
	if (i == 0)
		return (0);
	else
		pileA = ft_fill_pile(i, pileA, dest);
	return (pileA);
}

int	ft_is_order(stack *pileA)
{
	stack	*element;
	int		i;

	if (!pileA)
		return (1);
	i = 0;
	element = pileA->next;
	while (pileA->next)
	{
		if (pileA->value > pileA->next->value)
		{
			i++;
		}
		pileA = pileA->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	stack	*pileA;
	stack	*pileB;
	int		arg;
	char	**dest;

	arg = 0;
	pileA = NULL;
	pileB = NULL;
	if (argc <= 2)
		pileA = ft_argc_min(argv, pileA);
	else
		pileA = ft_argc_max(argv, argc, pileA);
	ft_verif_double(pileA);
	arg = ft_lstsize(pileA);
	if ((ft_is_order(pileA)) == 0 )
	{
		clear_stack(pileA);
		exit(EXIT_FAILURE);
	}
	pileA = tri_pile(pileA, pileB, arg);
	clear_stack(pileA);
	return (0);
}
