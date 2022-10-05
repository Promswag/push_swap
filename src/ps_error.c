/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:16:36 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/05 19:31:13 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error_handler(int errno)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putstr_fd("Too few arguments.\n", 2);
	if (errno == 1)
		ft_putstr_fd("Arguments must be numbers.\n", 2);
	if (errno == 2)
		ft_putstr_fd("Arguments must fit in an INT.\n", 2);
	return (-1);
}
