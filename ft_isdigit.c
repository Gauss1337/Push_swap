/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakam <ahakam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:09:48 by ahakam            #+#    #+#             */
/*   Updated: 2022/04/18 02:32:07 by ahakam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *c)
{
	int	i;

	i = 0;
	if ((c[0] < 48 || c[0] > 57) && c[0] == '-')
		i = 1;
	while (c[i])
	{
		if (c[i] < 48 || c[i] > 57)
			return (1);
		i++;
	}
	return (0);
}
