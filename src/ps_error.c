/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:16:36 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 12:56:23 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_error_handler(int errno)
{
	ft_putstr_fd("Error\n", 2);
	if (errno == 0)
		ft_putstr_fd("Missing arguments\n", 2);
	if (errno == 1)
		ft_putstr_fd("Arguments must be numbers\n", 2);
	if (errno == 2)
		ft_putstr_fd("Int overflow\n", 2);
	if (errno == 3)
		ft_putstr_fd("Duplicates\n", 2);
	if (errno == 4)
		ft_putstr_fd("List failure\n", 2);
	return (-1);
}
