/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:48 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/07 15:09:22 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_update_index(t_list *list, t_list **index)
{
	t_list	*read;
	t_list	*chk;
	t_list	*set;

	if (!list || !index || !*index)
		return (-1);
	read = list;
	while (read)
	{	
		chk = list;
		set = *index;
		while (chk && set)
		{
			if (ft_atoi(read->content) < ft_atoi(chk->content))
				set->content++;
			chk = chk->next;
			set = set->next;
		}
		read = read->next;
	}
	return (0);
}

int	ps_load_index_list(t_list *list, t_list **index)
{
	int		size;
	t_list	*elem;

	if (!list)
		return (-1);
	size = ft_lstsize(list);
	while (size--)
	{
		elem = ft_lstnew(0);
		if (elem)
		{
			if (!*index)
				*index = elem;
			else
				ft_lstadd_front(index, elem);
		}
		else
		{
			ft_lstclear(index, NULL);
			return (ps_error_handler(4));
		}
	}
	return (0);
}

int	ps_clear(t_list **a, t_list **b, t_list **c, char **argv)
{
	int	i;

	i = -1;
	if (a && *a)
		ft_lstclear(a, NULL);
	if (b && *b)
		ft_lstclear(b, NULL);
	if (c && *c)
		ft_lstclear(c, NULL);
	while (argv[++i])
		free(argv[i]);
	free(argv);
	return (0);
}
