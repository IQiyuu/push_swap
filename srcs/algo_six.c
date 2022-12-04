/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:15:51 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 22:40:14 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

static int	get_nbr_rotate(t_list **l, int nbr)
{
	t_list	*tmp;
	int		cpt;

	tmp = *l;
	cpt = 0;
	while (tmp)
	{
		if (tmp->index == nbr)
			break ;
		cpt++;
		tmp = tmp->next;
	}
	*l = NULL;
	return (cpt);
}

static int	pushin(t_list *heap_a, t_list *heap_b)
{
	static t_list	*l = NULL;
	int				closest;

	if (!l)
		l = heap_a;
	closest = 10;
	while (heap_a && (heap_a->next != l || \
		closest != heap_b->index + 1))
	{
		if (heap_a->index == heap_b->index + 1)
			return (get_nbr_rotate(&l, heap_a->index));
		if (heap_a->index == heap_b->index - 1)
			return (get_nbr_rotate(&l, heap_a->index) + 1);
		if ((heap_a->index - heap_b->index > 0 \
			&& heap_a->index - heap_b->index < closest))
			closest = heap_a->index - heap_b->index;
		heap_a = heap_a->next;
	}
	if (heap_a && heap_a->next == l)
		return (get_nbr_rotate(&l, closest - heap_b->index));
	return (get_nbr_rotate(&l, closest - heap_b->index));
}

static void	algo_deux(t_list **heap_a, int cpt)
{
	while (!is_sorted(*heap_a))
	{
		rotate(heap_a, "");
		cpt++;
	}
	if (cpt > ft_lstsize(*heap_a) / 2)
		while (cpt++ < ft_lstsize(*heap_a))
			ft_printf("rra\n");
	else
		while (cpt-- > 0)
			ft_printf("ra\n");
}

void	algo_six(t_list **heap_a, t_list **heap_b)
{
	int	cpt;
	int	rev;

	cpt = 0;
	while (ft_lstsize(*heap_a) > 3)
		push(heap_a, heap_b, "pb\n");
	algo_trois(heap_a);
	while (ft_lstsize(*heap_b) > 0)
	{
		cpt = pushin(*heap_a, *heap_b);
		rev = (cpt > (ft_lstsize(*heap_a) / 2));
		if (rev)
			cpt = ft_lstsize(*heap_a) - cpt;
		while (cpt > 0)
		{
			if (rev)
				rev_rotate(heap_a, "rra\n");
			else
				rotate(heap_a, "ra\n");
			cpt--;
		}
		push(heap_b, heap_a, "pa\n");
	}
	algo_deux(heap_a, 0);
}
