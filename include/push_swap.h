/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:14:19 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/05 19:27:39 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

//	ps_args.c
int		ps_args_handler(int argc, char **argv, t_list **list);
int		ps_number_check(int argc, char **argv);
int		ps_overflow_check(int argc, char **argv);
int		ps_load_stack(int argc, char **argv, t_list **list);

//	ps_error.c
int		ps_error_handler(int errno);

//	ps_misc.c
int		ps_list_is_sorted(t_list *list);
void	ps_print(t_list *a, t_list *b);

//	ps_sort.c
void	ps_swap(t_list **list);
void	ps_push(t_list **src, t_list **dst);
void	ps_rotate(t_list **list);
void	ps_reverse(t_list **list);

//	ps_utils.c
int		ft_isanumber(char *str);
int		ft_tabsize(char **tab);
int		int32_overflow_check(const char *str);




#endif