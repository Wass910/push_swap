/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:43 by idhiba            #+#    #+#             */
/*   Updated: 2021/10/19 18:28:45 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_stack
{
	int					value;
	struct s_stack		*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

void	afficherPile(t_stack *pileA, t_stack *pile_b);
t_stack	*tri_pile(t_stack *pileA, t_stack *pile_b, int arg);
int		depiler(t_stack *pile);
t_stack	*empiler(t_stack *pile, int nombre);
t_stack	*initalisation(t_stack *pile);
t_stack	*clear_t_stack(t_stack *pile);
t_stack	*ft_next_number(t_stack *pile);
int		ft_atoi(char *str);
t_stack	*ft_free_t_stack(t_stack *pile);
t_stack	*ft_swap(t_stack *pile);
t_stack	*ft_add_back(t_stack **alst, t_stack *new);
t_stack	*ft_reverse(t_stack *pile);
t_stack	*ft_add_front(t_stack **alst, t_stack *new);
t_stack	*ft_reverse_last(t_stack *pile);
t_stack	*ft_swap_between(t_stack *pile_more, int add);
t_stack	*only_three(t_stack *pileA, int arg);
t_stack	*only_five(t_stack *pileA, t_stack *pile_b, int arg);
t_stack	*ft_for_four(t_stack *pileA, t_stack *pile_b, t_stack *element);
t_stack	*for_four(t_stack *pileA, t_stack *pile_b);
t_stack	*for_five(t_stack *pileA, t_stack *pile_b);
t_stack	*ft_for_two(t_stack *pileA);
t_stack	*ft_parcing_five(t_stack *pileA, t_stack *pile_b, int tmp);
t_stack	*ft_hundred(t_stack *pileA);
t_stack	*ft_opti_hundred(t_stack *pileA, t_stack *pile_b);
t_stack	*ft_swap_between_b(t_stack *pile_more, int add);
char	**ft_split(char const *s, char c);
void	ft_verif_double(t_stack *pile);
int		ft_is_digit(char *str);
int		ft_lstsize(t_stack *pileA);
int		ft_is_order(t_stack *pileA);
t_stack	*ft_tri_hundred(t_stack *pileA, int pos, int i);
t_stack	*ft_swap_between_tmp(t_stack *pile_more, int add);
t_stack	*ft_hundred_b(t_stack *pileA);
t_stack	*ft_reverse_b(t_stack *pile);
t_stack	*ft_reverse_last_b(t_stack *pile);
t_stack	*ft_less_hundred(t_stack *pileA);
int		ft_morceaux(t_stack *pile, int tmp);
int		ft_morceaux_suite(t_stack *pile, int tmp);
int		ft_norme_opti_for_i(t_stack *pile, int i);
t_stack	*ft_opti_five_hundred(t_stack *pileA);
t_stack	*ft_opti_hundred_five(t_stack *pileA);
t_stack	*ft_parcing_all(t_stack *pileA, t_stack *pile_b, int what_position);
t_stack	*ft_swap_b(t_stack *pile);
t_stack	*ft_find_little_less(t_stack *pileA, int count);
t_stack	*ft_tri_tab_less(t_stack *tab, int count);
t_stack	*ft_norme_for_lesshundred(t_stack *pileA, t_stack *pile_b);
t_stack	*ft_tri_tab_five(t_stack *tab, int count);
t_stack	*ft_norme_for_index(t_stack *pileA, t_stack *tab, int tmp, int count);
t_stack	*ft_index(t_stack *pileA, int count);
char	*ft_strjoin_free(char *s1, char *s2, int f);
int		ft_count(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
void	*ft_calloc(int count, int size);
char	*ft_strchr(char *s, int c);
int		ft_strlen(char *s);
int		read_line(int fd, char **dest);
char	*ft_no_leaks(char *dest, int i);
int		get_next_line(int fd, char **line);
t_stack	*ft_second_algo(t_stack *pileA);
t_stack	*ft_reverse_tmp(t_stack *pile);
t_stack	*ft_reverse2(t_stack *pile);
t_stack	*ft_argc_max(char **argv, int argc, t_stack *pileA);
t_stack	*ft_argc_min(char **argv, t_stack *pileA);
int		is_empty_t_stack(t_stack *st);
void	ft_putchar(char c);
void	ft_putstr(char *s);
t_stack	*ft_swap_check(t_stack *pile);
t_stack	*ft_reverse_last_check(t_stack *pile);
int		ft_strlen_const(const char *s);
int		ft_cmp(const char *s1, const char *s2);
t_stack	*ft_swap_checker(t_stack *pile);
t_stack	*ft_reverse_check(t_stack *pile);
t_stack	*ft_reverse_last_checker(t_stack *pile);
void	ft_print_error(char *line);
void	ft_result_checker(t_stack *pile_a, t_stack *pile_b);
int		ft_error(const char *s);

#endif
