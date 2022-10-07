/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:36:01 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/07 14:46:48 by gbaumgar         ###   ########.fr       */
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
	int		bit;
	int		leftmostbit;

	leftmostbit = ps_get_leftmostbit(*a);
	bit = 0;
	while (bit < leftmostbit + 1 && !ps_list_is_sorted_int(*a))
		bit = ps_sort2(bit, a, b);
	while (*b)
		ps_pa(a, b);
}

int	ps_sort2(int bit, t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size-- && !ps_list_is_sorted_int(*a))
	{
		if (!((int)((*a)->content) >> bit & 1))
			ps_pb(a, b);
		else
			ps_ra(a);
	}
	bit++;
	size = ft_lstsize(*b);
	while (size-- && !ps_list_is_sorted_int(*a))
	{
		if (!((int)((*b)->content) >> bit & 1))
			ps_rb(b);
		else
			ps_pa(a, b);
	}
	return (bit);
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
			if (((*b)->content < (*a)->content && (*b)->content > \
	ft_lstlast(*a)->content) || (ps_list_is_sorted_int(*a) \
	&& (*b)->content > ft_lstlast(*a)->content) \
	|| (ps_list_is_sorted_int(*a) && (*b)->content < (*a)->content))
				ps_pa(a, b);
			else if ((*b)->next && (((*b)->next->content < (*a)->content && \
	(*b)->next->content > ft_lstlast(*a)->content) || \
	(ps_list_is_sorted_int(*a) && (*b)->next->content > \
	ft_lstlast(*a)->content) || (ps_list_is_sorted_int(*a) && \
	(*b)->next->content < (*a)->content)))
				ps_rb(b);
			else
				ps_ra(a);
		}
		while ((*a)->content > ft_lstlast(*a)->content)
			ps_rra(a);
	}
}
