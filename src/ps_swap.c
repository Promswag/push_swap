/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:29:01 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 15:50:49 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_swap(t_list **list)
{
	t_list	*tmp;

	if (*list)
	{
		if ((*list)->next)
		{
			tmp = (*list)->next;
			(*list)->next = tmp->next;
			tmp->next = *list;
			*list = tmp;
		}
	}
}

void	ps_sa(t_list **a)
{
	ps_swap(a);
	ft_printf("sa\n");
}

void	ps_sb(t_list **b)
{
	ps_swap(b);
	ft_printf("sb\n");
}

void	ps_ss(t_list **a, t_list **b)
{
	ps_swap(a);
	ps_swap(b);
	ft_printf("ss\n");
}
