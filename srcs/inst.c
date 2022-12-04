/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:59:44 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 22:40:09 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

void	swap(t_list **heap_a, char *inst)
{
	t_list	*tmp;

	tmp = (*heap_a);
	(*heap_a) = (*heap_a)->next;
	tmp->next = tmp->next->next;
	(*heap_a)->next = tmp;
	ft_putstr_fd(inst, 1);
}

void	push(t_list **heap_from, t_list **heap_to, char *inst)
{
	t_list	*tmp;

	tmp = (*heap_from)->next;
	(*heap_from)->next = (*heap_to);
	(*heap_to) = (*heap_from);
	*heap_from = tmp;
	ft_putstr_fd(inst, 1);
}

void	rotate(t_list **heap, char *inst)
{
	t_list	*first;
	t_list	*tmp;

	tmp = (*heap)->next;
	first = (*heap);
	while ((*heap)->next)
		(*heap) = (*heap)->next;
	(*heap)->next = first;
	first->next = NULL;
	(*heap) = tmp;
	ft_putstr_fd(inst, 1);
}

void	rev_rotate(t_list **heap, char *inst)
{
	t_list	*first;
	t_list	*tmp;

	first = (*heap);
	while ((*heap)->next)
	{
		tmp = (*heap);
		(*heap) = (*heap)->next;
	}
	(*heap)->next = first;
	tmp->next = NULL;
	ft_putstr_fd(inst, 1);
}
