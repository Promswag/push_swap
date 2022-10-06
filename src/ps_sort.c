/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:01 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 14:49:31 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_list **a, t_list **b)
{
	t_list	*a_a;
	t_list	*b_b;
	int		bit;

	bit = -1;
	a_a = *a;
	while (++bit < 9)
	{
		b_b = *b;
		while (a_a)
		{
			if (a->content >> bit & 1)
			{
				a_a = a_a->next;
				ps_pb(a, b);
			}
			else
				a_a = a_a->next:
		}
		while (*b)


	}

}


