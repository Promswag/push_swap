/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaumgar <gbaumgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:14:19 by gbaumgar          #+#    #+#             */
/*   Updated: 2022/10/06 19:53:26 by gbaumgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>

# include "../libft/libft.h"
# include "../ft_printf/include/ft_printf.h"

//	ps_args.c
int		ps_args_handler(int argc, char **argv, t_list **list);
int		ps_number_check(int argc, char **argv, int offset);
int		ps_overflow_check(int argc, char **argv, int offset);
int		ps_duplicate_check(int argc, char **argv, int offset);
int		ps_load_stack(int argc, char **argv, int offset, t_list **list);

//	ps_error.c
int		ps_error_handler(int errno);

//	ps_misc.c
int		ps_list_is_sorted(t_list *list);
int		ps_list_is_sorted_int(t_list *list);
void	ps_print(t_list *a, t_list *b);

//	ps_op.c
int		ps_load_index_list(t_list *list, t_list **index);
int		ps_update_index(t_list *list, t_list **index);

//	ps_sort.c
int		ps_get_leftmostbit(t_list *list);
void	ps_sort(t_list **a, t_list **b);
void	ps_sort_small(t_list **a);
void	ps_sort_med(t_list **a, t_list **b);

//	ps_swap.c
void	ps_swap(t_list **list);
void	ps_sa(t_list **a);
void	ps_sb(t_list **b);
void	ps_ss(t_list **a, t_list **b);

//	ps_push.c
void	ps_push(t_list **src, t_list **dst);
void	ps_pa(t_list **a, t_list **b);
void	ps_pb(t_list **a, t_list **b);

//	ps_rotate.c
void	ps_rotate(t_list **list);
void	ps_ra(t_list **a);
void	ps_rb(t_list **b);
void	ps_rr(t_list **a, t_list **b);

//	ps_reverse.c
void	ps_reverse(t_list **list);
void	ps_rra(t_list **a);
void	ps_rrb(t_list **a);
void	ps_rrr(t_list **a, t_list **b);

//	ps_utils.c
int		ft_isanumber(char *str);
int		ft_tabsize(char **tab);
int		int32_overflow_check(const char *str);

#endif