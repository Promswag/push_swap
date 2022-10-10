/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:13:28 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/10 13:58:31 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_list	*a;
	t_list	*b;
	t_list	*index;

	a = NULL;
	b = NULL;
	index = NULL;
	if (argc == 1)
		return (0);
	args = ps_args_handler(argc, argv, &a);
	if (!args)
		ft_putstr_fd("Error\n", 2);
	if (ps_list_is_sorted(a) || ps_load_index_list(a, &index) || \
		ps_update_index(a, &index))
		return (ps_clear(&a, &b, &index, args));
	if (ft_lstsize(index) > 10)
		ps_sort(&index, &b);
	else if (ft_lstsize(index) > 3)
		ps_sort_med(&index, &b);
	else
		ps_sort_small(&index, &b);
	return (ps_clear(&a, &b, &index, args));
}
