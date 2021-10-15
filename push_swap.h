#include <stdlib.h>
#include <stdio.h>

typedef struct StackElement
{
    int                       value;
    struct StackElement       *next;
}          stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

void    afficherPile(stack *pileA, stack *pileB, int pivot);
stack   *tri_pile(stack *pileA, stack *pileB, int arg);
int     depiler(stack *pile);
stack   *empiler(stack *pile, int nombre);
stack   *initalisation(stack *pile);
stack   *clear_stack(stack *pile);
stack   *ft_next_number(stack *pile);
int     ft_atoi(char *str);
stack   *ft_free_stack(stack *pile);
stack   *ft_swap(stack *pile);
stack   *ft_add_back(stack **alst, stack *new);
stack   *ft_reverse(stack *pile);
stack   *ft_add_front(stack **alst, stack *new);
stack   *ft_reverse_last(stack *pile);
stack   *ft_swap_between(stack *pile_more, int add);
stack   *only_three(stack *pileA, int arg);
stack   *only_five(stack *pileA, stack *pileB, int arg);
stack   *ft_for_four(stack *pileA, stack *pileB, stack *element);
stack   *for_four(stack *pileA, stack *pileB);
stack   *for_five(stack *pileA, stack *pileB);
stack   *ft_for_two(stack *pileA);
stack   *ft_parcing_five(stack *pileA, stack *pileB, int tmp);
stack   *ft_hundred(stack *pileA);
stack   *ft_opti_hundred(stack *pileA, stack *pileB);
stack   *ft_swap_between_b(stack *pile_more, int add);
char	**ft_split(char const *s, char c);
void    ft_verif_double(stack *pile);
int     ft_is_digit(char *str);
int	    ft_lstsize(stack *pileA);
int     ft_is_order(stack *pileA);
stack   *ft_tri_hundred(stack *pileA, int pos, int i);
stack    *ft_swap_between_tmp(stack *pile_more, int add);
stack   *ft_hundred_b(stack *pileA);
stack   *ft_reverse_b(stack *pile);
stack   *ft_reverse_last_b(stack *pile);
stack   *ft_less_hundred(stack *pileA);
int     ft_morceaux(stack* pile, int tmp);
int     ft_morceaux_suite(stack* pile, int tmp);
int ft_norme_opti_for_i(stack *pile, int i);
stack   *ft_opti_five_hundred(stack *pileA);
stack   *ft_opti_hundred_five(stack *pileA);
stack   *ft_new_algo(stack *pileA, stack *pileB);
stack   *ft_swap_b(stack *pile);
stack   *ft_find_little_less(stack *pileA, int count);
stack   *ft_norme_for_find_litle_less(stack *tmp_elem, stack *element, stack *pileA, stack *tab, int tmp);
stack     *ft_tri_tab_less(stack *tab, int count);
stack   *ft_norme_for_tritab_less(int c, int tmp, stack *tmp_tab, stack *tab);
stack   *ft_norme_for_lesshundred(stack *pileA, stack *pileB);
stack     *ft_tri_tab_five(stack *tab, int count);
stack   *ft_norme_for_tritab_five(int count, int tmp, stack *tmp_tab, stack *tab);
stack   *ft_norme_for_find_litle_five(stack *tmp_elem, stack *pileA, stack *tab, int tmp, int count);
stack   *ft_find_little_five(stack *pileA, int count);
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
stack *ft_second_algo(stack *pileA);
stack	*ft_reverse_tmp(stack *pile);