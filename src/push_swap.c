/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:13:28 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 14:36:26 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*index;

	a = NULL;
	b = NULL;
	index = NULL;
	if (ps_args_handler(argc, argv, &a))
		return (-1);
	if (ps_list_is_sorted(a))
		return (0);
	if (ps_load_index_list(a, &index))
		return (-1);
	ps_update_index(a, &index);
	ps_sort(index, b);
	ps_print(a, index);
	return (0);
}
