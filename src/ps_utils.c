/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 19:19:04 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 11:57:23 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isanumber(char *str)
{
	int	i;
	int	l;

	if (!str)
		return (0);
	i = 0;
	l = ft_strlen(str);
	if ((str[i] == '-' || str[i] == '+') && l == 1)
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (i < l)
		if (!ft_isdigit(str[i++]))
			return (0);
	return (1);
}

int	ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	if (!tab || !*tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}

int	int32_overflow_check(const char *str)
{
	int			i;
	long long	r;
	int			sign;

	r = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'
		|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' ')
		i++;
	if (*(str + i) == '+' || *(str + i) == '-')
		if (*(str + i++) == '-')
			sign = -1;
	while (*(str + i) >= 48 && *(str + i) <= 57)
	{
		if (sign == 1 && (r > (INT_MAX - (*(str + i) - 48)) / 10))
			return (-1);
		if (sign == -1 && (r * sign < (INT_MIN + (*(str + i) - 48)) / 10))
			return (-1);
		r = r * 10 + *(str + i) - 48;
		i++;
	}
	return (0);
}
