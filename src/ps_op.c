/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:48 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/04 17:34:56 by gbaumgar         ###   ########.fr       */
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
