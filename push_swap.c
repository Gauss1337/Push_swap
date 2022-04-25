/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:54:51 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/25 04:51:20 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_stack **stack_a, t_stack **stack_b)
{
	t_par	rad;

	rad.i = 0;
	rad.size = ft_lstsize(*stack_a);
	rad.max_num = get_max_index(stack_a);
	rad.max_bits = get_max_bit(rad.size);
	*stack_b = NULL;
	while (rad.i < rad.max_bits + 1)
	{
		rad.j = 0;
		while (rad.j < rad.size)
		{
			rad.num = ((*stack_a)->index >> rad.i);
			if (rad.num & 1)
				ft_rotate(stack_a, 1);
			else
				ft_push(stack_a, stack_b, 0);
			rad.j++;
		}
		rad.i++;
		while (*stack_b)
			ft_push(stack_b, stack_a, 1);
	}
}

void	ft_sort(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_lstsize(stack_a) == 3)
	{
		ft_sort_three_numbers(&stack_a);
		exit (0);
	}
	else if (ft_lstsize(stack_a) == 4)
	{
		ft_sort_four_numbers(&stack_a, &stack_b);
		exit (0);
	}
	else if (ft_lstsize(stack_a) == 5)
	{
		ft_sort_five_numbers(&stack_a, &stack_b);
		exit (0);
	}
}

int	is_sorted(t_stack **stack_a)
{
	int		is_sorted;
	t_stack	*tmp;

	is_sorted = 1;
	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			is_sorted = 0;
		tmp = tmp->next;
	}
	return (is_sorted);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*k;

	stack_b = NULL;
	if (argc != 1)
	{
		ft_check_max_values(argv, argc);
		ft_check_clones(argv, argc);
		ft_fill_params(&stack_a, argc, argv);
		k = (int *)malloc(sizeof(int) * (argc - 1));
		store_numbers(&stack_a, k, argc);
		sort_array(k, argc);
		indexing(&stack_a, k, argc);
		if (is_sorted(&stack_a))
		{
			write(1, "already sorted !\n", 18);
			exit(0);
		}
		if (argc <= 6)
			ft_sort(stack_a);
		radix(&stack_a, &stack_b);
	}
	return (0);
}
