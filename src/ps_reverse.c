/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:40:55 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 20:33:43 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_reverse(t_list **list)
{
	t_list	*cur;
	t_list	*prev;

	if (*list)
	{
		cur = *list;
		prev = NULL;
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		if (prev)
		{
			prev->next = NULL;
			cur->next = (*list)->next;
			*list = cur;
		}
		// if (tmp->next)
		// 	tmp->next->next = *list;
		// *list = tmp->next;
		// tmp->next = NULL;
	}
}

void	ps_rra(t_list **a)
{
	ps_reverse(a);
	ft_printf("rra\n");
}

void	ps_rrb(t_list **a)
{
	ps_reverse(a);
	ft_printf("rrb\n");
}

void	ps_rrr(t_list **a, t_list **b)
{
	ps_reverse(a);
	ps_reverse(b);
	ft_printf("rrr\n");
}
