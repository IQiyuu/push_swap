/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:02:08 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 15:06:58 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

int	is_sorted(t_list *heap)
{
	if (!heap)
		return (1);
	while (heap->next)
	{
		if (heap->content > heap->next->content)
			return (0);
		heap = heap->next;
	}
	return (1);
}

int	rev_is_sorted(t_list *heap)
{
	if (!heap)
		return (1);
	while (heap->next)
	{
		if (heap->content < heap->next->content)
			return (0);
		heap = heap->next;
	}
	return (1);
}

int	is_zero(t_list *heap, int cpt)
{
	while (heap)
	{
		if (!((heap->index >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

int	is_one(t_list *heap, int cpt)
{
	while (heap)
	{
		if (((heap->index >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

int	bit_max(t_list *heap)
{
	int	max;
	int	cpt;
	int	rd;

	max = 0;
	while (heap)
	{
		if (heap->index > max)
			max = heap->index;
		heap = heap->next;
	}
	cpt = 0;
	rd = 1;
	while (max > 0)
	{
		max -= rd;
		cpt++;
		rd = (rd * 2);
	}
	return (cpt);
}
