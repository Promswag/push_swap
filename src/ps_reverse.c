/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:55 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 12:42:22 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		tmp = *list;
		if (tmp->next)
			while (tmp->next->next)
				tmp = tmp->next;
		tmp->next->next = *list;
		*list = tmp->next;
		tmp->next = NULL;
	}
}

void	ps_rra(t_list **a)
{
	ps_reverse(a);
}

void	ps_rrb(t_list **a)
{
	ps_reverse(a);
}

void	ps_rrr(t_list **a, t_list **b)
{
	ps_reverse(a);
	ps_reverse(b);
}
