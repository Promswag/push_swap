/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:37:44 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 12:39:12 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_rotate(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = (*list)->next;
		ft_lstlast(*list)->next = *list;
		(*list)->next = NULL;
		*list = tmp;
	}
}

void	ps_ra(t_list **a)
{
	ps_rotate(a);
}

void	ps_rb(t_list **b)
{
	ps_rotate(b);
}

void	ps_rr(t_list **a, t_list **b)
{
	ps_rotate(a);
	ps_rotate(b);
}
