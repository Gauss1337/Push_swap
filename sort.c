/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:00:17 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/21 23:09:36 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	ft_sort_three_numbers(t_stack **stack_a)
{
	if ((((*stack_a)->value > (*stack_a)->next->value)
			&& ((*stack_a)->value > (*stack_a)->next->next->value))
		&& ((*stack_a)->next->next->value < (*stack_a)->value
			&& ((*stack_a)->next->next->value < (*stack_a)->next->value)))
	{
		ft_swap(stack_a, 1);
		*stack_a = ft_r_rotate(stack_a, 1);
	}
	else if ((((*stack_a)->value < (*stack_a)->next->value)
			&& ((*stack_a)->value < ((*stack_a)->next->next->value)))
		&& ((*stack_a)->next->value > (*stack_a)->value
			&& ((*stack_a)->next->value > (*stack_a)->next->next->value)))
	{
		ft_swap(stack_a, 1);
		ft_rotate(stack_a, 1);
	}
	else if (((*stack_a)->value > (*stack_a)->next->value)
		&& ((*stack_a)->value > (*stack_a)->next->next->value))
		ft_rotate(stack_a, 1);
	else if (((*stack_a)->next->value < (*stack_a)->value)
		&& ((*stack_a)->next->value < (*stack_a)->next->next->value))
		ft_swap(stack_a, 1);
	else if (((*stack_a)->next->next->value < (*stack_a)->next->value)
		&& ((*stack_a)->next->next->value < (*stack_a)->value))
		*stack_a = ft_r_rotate(stack_a, 1);
}

int	get_direction(t_stack **stack_a, int index)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack_a;
	while (tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	if (ft_lstsize(*stack_a) / 2 > i)
		return (1);
	else
		return (0);
}

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (ft_lstsize(*stack_a) != 3)
	{
		while ((*stack_a)->index != i)
		{
			if (get_direction(stack_a, i) == 1)
				ft_rotate(stack_a, 1);
			else
				*stack_a = ft_r_rotate(stack_a, 1);
		}
		ft_push(stack_a, stack_b, 0);
		i++;
	}
	ft_sort_three_numbers(stack_a);
}

void	ft_sort_four_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	while (ft_lstsize(*stack_b))
		ft_push(stack_b, stack_a, 1);
}

void	ft_sort_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_min_to_b(stack_a, stack_b);
	while (*stack_b)
		ft_push(stack_b, stack_a, 1);
}
