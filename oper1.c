/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:54:57 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/18 03:12:13 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *arr, int argc)
{
	int		i;
	int		j;
	t_bool	swapped;

	i = 0;
	while (i < argc - 1)
	{
		swapped = false;
		j = 0;
		while (j < argc - i - 1)
		{
			if ((j + 1 < argc - i - 1) && (arr[j] > arr[j + 1]))
			{
				switch_position(&arr[j], &arr[j + 1]);
				swapped = true;
			}
			j++;
		}
		i++;
		if (swapped == false)
			break ;
	}
}

void	ft_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate (stack_a, 1);
	ft_rotate (stack_b, 0);
	write(1, "rr\n", 3);
}

void	ft_swap_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 1);
	ft_swap(stack_b, 0);
	write(1, "ss\n", 3);
}

void	ft_r_rotate_all(t_stack **stack_a, t_stack **stack_b)
{
	ft_r_rotate(stack_a, 1);
	ft_r_rotate(stack_b, 0);
	write(1, "rrr\n", 4);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int is_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	ft_lstadd_front(stack_b, ft_lstnew((*stack_a)->value, (*stack_a)->index));
	*stack_a = (*stack_a)->next;
	free(tmp);
	tmp = NULL;
	if (is_a == 1)
		write(1, "pa\n", 3);
	else if (is_a == 0)
		write(1, "pb\n", 3);
	else
		return ;
}
