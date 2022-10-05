/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:56:13 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/05 19:20:03 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_list_is_sorted(t_list *list)
{
	if (!list)
		return (0);
	while (list->next)
	{
		if (ft_atoi(list->content) < ft_atoi(list->next->content))
			list = list->next;
		else
			return (0);
	}
	return (1);
}

void	ps_print(t_list *a, t_list *b)
{
	if (a || b)
	{
		ft_printf("------\n");
		while (a || b)
		{
			if (a)
			{
				ft_printf("%s ", a->content);
				a = a->next;
			}
			else
				ft_printf("  ");
			if (b)
			{
				ft_printf("%s\n", b->content);
				b = b->next;
			}
			else
				ft_printf(" \n");
		}
		ft_printf("- -\na b\n");
	}
}
