/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:54:54 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/20 08:47:18 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, int is_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if (ft_lstsize(*stack) > 1)
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
	}
	if (!is_a)
		write(1, "sb\n", 3);
	else if (is_a == 1)
		write(1, "sa\n", 3);
	else
		return ;
}

void	ft_rotate(t_stack **stack, int is_a)
{
	t_stack	*tmp;

	tmp = *stack;
	if (ft_lstsize(*stack) > 1)
	{
		ft_lstadd_back(stack, ft_lstnew((*stack)->value, (*stack)->index));
		(*stack) = (*stack)->next;
		free(tmp);
	}
	if (!is_a)
		write(1, "rb\n", 3);
	else if (is_a == 1)
		write(1, "ra\n", 3);
	else
		return ;
}

t_stack	*ft_r_rotate(t_stack **stack, int is_a)
{
	t_stack	*tmp;
	t_stack	*to_return;

	tmp = ft_get_before_last(*stack);
	to_return = NULL;
	if (ft_lstsize(*stack))
	{
		to_return = ft_lstlast(*stack);
		to_return->next = (*stack);
		tmp->next = NULL;
	}
	if (!is_a)
		write(1, "rrb\n", 4);
	else if (is_a == 1)
		write(1, "rra\n", 4);
	return (to_return);
}

t_stack	*ft_get_before_last(t_stack *stack)
{
	while (stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	store_numbers(t_stack **stack, int *array, int argc)
{
	int		i;
	int		j;
	t_stack	*temp;

	i = 1;
	j = 0;
	temp = *stack;
	while (i < argc)
	{
		array[j] = temp->value;
		i++;
		j++;
		temp = temp->next;
	}
}
