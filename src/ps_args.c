/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:39:52 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/05 19:35:07 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_args_handler(int argc, char **argv, t_list **list)
{
	if (argc == 1)
		return (ps_error_handler(0));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_tabsize(argv);
	}
	ft_printf("%d\n", argc);
	if (ps_number_check(argc, argv))
		return (ps_error_handler(1));
	if (ps_overflow_check(argc, argv))
		return (ps_error_handler(2));
	ps_load_stack(argc, argv, list);
	return (0);
}

int	ps_number_check(int argc, char **argv)
{
	while (argc--)
	{
		if (!ft_isanumber(argv[argc]))
			return (1);
	}
	return (0);
}

int	ps_overflow_check(int argc, char **argv)
{
	while (argc--)
	{
		if (int32_overflow_check(argv[argc]))
			return (1);
	}
	return (0);
}

int	ps_load_stack(int argc, char **argv, t_list **list)
{
	t_list	*elem;

	while (--argc)
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
			return (1);
		}
	}
	return (0);
}
