/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:33:09 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 15:50:53 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (*src)
	{
		tmp = (*src)->next;
		(*src)->next = *dst;
		*dst = *src;
		*src = tmp;
	}
}

void	ps_pa(t_list **a, t_list **b)
{
	ps_push(b, a);
	ft_printf("pa\n");
}

void	ps_pb(t_list **a, t_list **b)
{
	ps_push(a, b);
	ft_printf("pb\n");
}
