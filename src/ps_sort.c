/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:01 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 20:18:57 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_get_leftmostbit(t_list *list)
{
	int	value;
	int	bit;

	value = 0;
	bit = 32;
	while (list)
	{
		if (value < (int)list->content)
			value = (int)list->content;
		list = list->next;
	}
	while (bit--)
		if (value >> bit & 1)
			return (bit);
	return (-1);
}

void	ps_sort(t_list **a, t_list **b)
{
	int		size;
	int		bit;
	int		leftmostbit;

	leftmostbit = ps_get_leftmostbit(*a);
	bit = 0;
	while (bit < leftmostbit + 1)
	{
		size = ft_lstsize(*a);
		while (size--)
		{
			if (!((int)((*a)->content) >> bit & 1))
				ps_pb(a, b);
			else
				ps_ra(a);
		}
		if (ps_list_is_sorted_int(*a))
			break ;
		bit++;
		size = ft_lstsize(*b);
		while (size--)
		{
			if (!((int)((*b)->content) >> bit & 1))
				ps_rb(b);
			else
				ps_pa(a, b);
		}
	}
	while (*b)
		ps_pa(a, b);
}

void	ps_sort_small(t_list **a)
{
	if (a)
	{
		while (*a)
		{
			if (ps_list_is_sorted_int(*a))
				break ;
			if ((*a)->content > (*a)->next->content)
				ps_sa(a);
			else
				ps_rra(a);
		}
	}
}

void	ps_sort_med(t_list **a, t_list **b)
{
	if (a)
	{
		while (ft_lstsize(*a) > 3)
			ps_pb(a, b);
		ps_sort_small(a);
		while (*b)
		{
			if ((*b)->content < (*a)->content)
				ps_pa(a, b);
			else if ((*b)->content == (*a)->content + 1)
			{
				ps_ra(a);
				ps_pa(a, b);
				ps_ra(a);
			}
			else
				ps_rra(a);
		}
	}
}
