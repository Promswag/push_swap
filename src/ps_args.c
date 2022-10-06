/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:39:52 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 12:55:06 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_args_handler(int argc, char **argv, t_list **list)
{
	int	offset;

	offset = 1;
	if (argc == 1)
		return (ps_error_handler(0));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_tabsize(argv);
		offset--;
	}
	if (ps_number_check(argc, argv, offset))
		return (ps_error_handler(1));
	if (ps_overflow_check(argc, argv, offset))
		return (ps_error_handler(2));
	if (ps_duplicate_check(argc, argv, offset))
		return (ps_error_handler(3));
	ps_load_stack(argc, argv, offset, list);
	return (0);
}

int	ps_number_check(int argc, char **argv, int offset)
{
	while (argc-- - offset)
	{
		if (!ft_isanumber(argv[argc]))
			return (1);
	}
	return (0);
}

int	ps_overflow_check(int argc, char **argv, int offset)
{
	while (argc-- - offset)
	{
		if (int32_overflow_check(argv[argc]))
			return (1);
	}
	return (0);
}

int	ps_duplicate_check(int argc, char **argv, int offset)
{
	int	i;

	while (argc-- - offset)
	{
		i = argc;
		while (i-- - offset)
			if (ft_atoi(argv[argc]) == ft_atoi(argv[i]))
				return (1);
	}
	return (0);
}

int	ps_load_stack(int argc, char **argv, int offset, t_list **list)
{
	t_list	*elem;

	while (argc-- - offset)
	{
		elem = ft_lstnew((argv[argc]));
		if (elem)
		{
			if (!*list)
				*list = elem;
			else
				ft_lstadd_front(list, elem);
		}
		else
		{
			ft_lstclear(list, NULL);
			return (ps_error_handler(4));
		}
	}
	return (0);
}
