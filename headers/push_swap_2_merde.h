/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2_merde.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:43:12 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 22:27:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_2_MERDE_H
# define PUSH_SWAP_2_MERDE_H

# include "libft.h"
# include <stdlib.h>

t_list	*create_list(int ac, char **av, t_list *lst);
void	print_tlist(t_list *lst);
int		is_sorted(t_list *heap);
int		bit_max(t_list *heap);
int		is_one(t_list *heap, int cpt);
int		is_zero(t_list *heap, int cpt);
int		rev_is_sorted(t_list *heap);
int		is_sorted(t_list *heap);
void	pseudo_radix(t_list **heap_a, t_list **heap_b);
void	algo_trois(t_list **heap);
void	algo_six(t_list **heap_a, t_list **heap_b);
int		has_alpha(char *str);
int		is_in(t_list *lst, char *str);
t_list	*min(t_list **lst);
t_list	*create_list(int ac, char **av, t_list *lst);
t_list	*lst_dup(t_list *lst);
t_list	*update(t_list *s, t_list *t);
void	rev_rotate(t_list **heap, char *inst);
void	rotate(t_list **heap, char *inst);
void	push(t_list **heap_from, t_list **heap_to, char *inst);
void	swap(t_list **heap_a, char *inst);

#endif