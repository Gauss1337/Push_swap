/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:54:26 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/21 23:07:51 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
	int				moves;
}	t_stack;

typedef struct s_par
{
	int	size;
	int	num;
	int	max_num;
	int	max_bits;
	int	i;
	int	j;
}	t_par;

typedef enum s_bool {false, true}	t_bool;

long long	ft_atoi(const char *string);
int			ft_isdigit(char *c);
int			ft_lstsize(t_stack *lst);
int			get_max_bit(int max_bits);
int			get_max_index(t_stack **stack_a);
int			get_direction(t_stack **stack_a, int index);
int			is_sorted(t_stack **stack_a);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
void		ft_lstadd_front(t_stack **alst, t_stack *new);
void		ft_sort_five_numbers(t_stack **stack_a, t_stack **stack_b);
void		ft_fill_params(t_stack **stack_a, int argc, char **argv);
void		push_min_to_b(t_stack	**stack_a, t_stack	**stack_b);
void		ft_lstiter(t_stack *lst, void (*f)(void *));
void		ft_rotate_all(t_stack **stack_a, t_stack **stack_b);
void		ft_fill_params(t_stack **stack_a, int argc, char **argv);
void		ft_print_stack(t_stack *stack);
void		ft_swap(t_stack **stack, int is_a);
void		ft_r_rotate_all(t_stack **stack_a, t_stack **stack_b);
void		ft_sort_four_numbers(t_stack **stack_a, t_stack **stack_b);
void		ft_free(int *value);
void		indexing(t_stack **stack, int *arr, int argc);
void		sort_array(int *arr, int argc);
void		switch_position(int	*k, int *j);
void		ft_rotate(t_stack **stack, int is_a);
void		ft_swap_all(t_stack **stack_a, t_stack **stack_b);
void		ft_push(t_stack **stack_a, t_stack **stack_b, int is_a);
void		store_numbers(t_stack **stack, int *array, int argc);
void		ft_sort(t_stack *stack_a);
void		ft_sort_three_numbers(t_stack **stack_a);
void		ft_check_clones(char **argv, int argc);
void		ft_check_max_values(char **argv, int argc);
void		ft_check_clones(char **argv, int argc);
t_stack		*ft_get_before_last(t_stack *stack);
t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstdelone(t_stack **lst);
t_stack		*ft_lstnew(int value, int index);
t_stack		*ft_get_before_last(t_stack *stack);
t_stack		*ft_r_rotate(t_stack **stack, int is_a);
#endif 
