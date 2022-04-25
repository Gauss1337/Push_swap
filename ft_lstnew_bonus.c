/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:54:24 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/07 02:58:19 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value, int index)
{
	t_stack	*htr;

	htr = malloc (sizeof(t_stack));
	if (!htr)
		return (NULL);
	htr->next = NULL;
	htr->value = value;
	htr->index = index;
	return (htr);
}
