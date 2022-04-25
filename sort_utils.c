/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 23:04:30 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/21 23:09:58 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	switch_position(int	*k, int *j)
{
	int	temp;

	temp = *k;
	*k = *j;
	*j = temp;
}

void	indexing(t_stack **stack, int *arr, int argc)
{
	int		i;
	int		j;
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		j = 0;
		while (i < argc - 1)
		{
			if (arr[i] == tmp->value)
			{
				tmp->index = i;
			}
			i++;
			j++;
		}
		tmp = tmp->next;
	}
}

int	get_max_index(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->index != ft_lstsize(*stack_a) - 1)
		tmp = tmp->next;
	return (tmp->index);
}
