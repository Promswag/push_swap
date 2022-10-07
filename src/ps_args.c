/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:39:52 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/07 15:09:21 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_args_handler(int argc, char **argv, t_list **list)
{
	char	*str;
	char	**args;

	if (argc == 1)
		return (NULL);
	else if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		str = ft_tab_strjoin(argv + 1, " ");
		args = ft_split(str, ' ');
		if (str)
			free(str);
	}
	argc = ft_tabsize(args);
	if (ps_number_check(argc, args) || ps_overflow_check(argc, args) || \
		ps_duplicate_check(argc, args) || ps_load_stack(argc, args, list))
		return (NULL);
	return (args);
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

int	ps_duplicate_check(int argc, char **argv)
{
	int	i;

	while (argc--)
	{
		i = argc;
		while (i--)
			if (ft_atoi(argv[argc]) == ft_atoi(argv[i]))
				return (1);
	}
	return (0);
}

int	ps_load_stack(int argc, char **argv, t_list **list)
{
	t_list	*elem;

	while (argc--)
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
			return (-1);
		}
	}
	return (0);
}
