/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:27:23 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:27:25 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_pile(int i, t_stack *pile_a, char **dest)
{
	while (i >= 0)
	{
		if (ft_is_digit(dest[i]) == 1)
		{
			clear_t_stack(pile_a);
			printf("ERROR\n");
			exit(EXIT_FAILURE);
		}
		pile_a = empiler(pile_a, ft_atoi(dest[i]));
		free(dest[i]);
		i--;
	}
	free(dest);
	return (pile_a);
}

t_stack	*ft_argc_max(char **argv, int argc, t_stack *pile_a)
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
		pile_a = ft_fill_pile(i, pile_a, dest);
		i = 0;
		argc--;
	}
	return (pile_a);
}

t_stack	*ft_argc_min(char **argv, t_stack *pile_a)
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
		pile_a = ft_fill_pile(i, pile_a, dest);
	return (pile_a);
}

int	ft_is_order(t_stack *pile_a)
{
	t_stack	*element;
	int		i;

	if (!pile_a)
		return (1);
	i = 0;
	element = pile_a->next;
	while (pile_a->next)
	{
		if (pile_a->value > pile_a->next->value)
		{
			i++;
		}
		pile_a = pile_a->next;
	}
	return (i);
}

int	ft_error(const char *s)
{
	int	i;
	int	good_letter;

	i = 0;
	good_letter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'a' || s[i] == 'b')
			good_letter++;
		i++;
	}
	return (good_letter);
}
