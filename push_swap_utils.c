/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:48:30 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/18 03:02:48 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_clones(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				write(1, "clones are not allowed !\n", 26);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_max_values(char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
		{
			write(1, "you better know your limits!\n", 30);
			exit(1);
		}
		if (ft_isdigit(argv[i]))
		{
			write(1, "pls enter ints only !\n", 23);
			exit(1);
		}
		i++;
	}
}

void	ft_fill_params(t_stack **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	*stack_a = ft_lstnew(ft_atoi(argv[i]), i);
	i++;
	while (i < argc)
	{
		ft_lstadd_back(&(*stack_a), ft_lstnew(atoi(argv[i]), i));
		i++;
	}
}

void	ft_print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	printf("\n");
}

int	get_max_bit(int max_bits)
{
	int	max;

	max_bits >>= 1;
	max = 0;
	while (max_bits)
	{
		max_bits >>= 1;
		max++;
	}
	return (max);
}
