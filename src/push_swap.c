/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:13:28 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/05 19:32:27 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = argc;
	if (ps_args_handler(argc, argv, &a))
		return (-1);
	if (ps_list_is_sorted(a))
		ft_printf("\n");
	// ps_print(a, b);
	// ps_push(&a, &b);
	// ps_push(&a, &b);
	// ps_push(&a, &b);
	// ps_print(a, b);
	// ps_rotate(&a);
	// ps_rotate(&b);
	// ps_print(a, b);
	// ps_reverse(&a);
	// ps_reverse(&b);
	// ps_print(a, b);
	// ps_push(&a, &b);
	// ps_push(&a, &b);
	// ps_push(&a, &b);
	// ps_print(a, list_b);
	return (0);
}
