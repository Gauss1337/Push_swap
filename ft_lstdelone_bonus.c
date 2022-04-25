/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:47:27 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/10 22:33:26 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstdelone(t_stack **lst)
{
	t_stack	*temp;

	if (ft_lstsize(*lst))
	{
		temp = *lst;
		temp = temp->next;
		return (temp);
	}
	return (NULL);
}
