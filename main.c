/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:06:04 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/03 22:18:52 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

void	print_tlist(t_list *lst)
{
	printf("\n---ICI---\n");
	while (lst)
	{
		printf("%d | ", lst->content);
		lst = lst->next;
	}
	printf("\n---END---\n");
}

int	is_zero(t_list *heap, int cpt)
{
	while (heap)
	{
		if (!((heap->content >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

int	is_one(t_list *heap, int cpt)
{
	while (heap)
	{
		if (((heap->content >> cpt) & 1))
			return (1);
		heap = heap->next;
	}
	return (0);
}

void	swap(t_list **heap_a)
{
	t_list	*tmp;

	tmp = (*heap_a);
	(*heap_a) = (*heap_a)->next;
	tmp->next = tmp->next->next;
	(*heap_a)->next = tmp;
}

void	push(t_list **heap_from, t_list **heap_to)
{
	t_list	*tmp;

	tmp = (*heap_from)->next;
	(*heap_from)->next = (*heap_to);
	(*heap_to) = (*heap_from);
	*heap_from = tmp;
}

void	rotate(t_list **heap)
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
}

void	rev_rotate(t_list **heap)
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
}

int	is_sorted(t_list *heap_a)
{
	while (heap_a->next)
	{
		if (heap_a->content > heap_a->next->content)
			return (0);
		else
			heap_a = heap_a->next;
	}
	return (1);
}

void	swap_zero_tob(t_list **heap_a, t_list **heap_b, int cpt)
{
	t_list	*tmp;

	tmp = NULL;
	while ((*heap_a)->next && tmp != (*heap_a)->next)
	{
		if (!(((*heap_a)->content >> cpt) & 1))
		{
			push(heap_a, heap_b);
			printf("pb\n");
		}
		else
		{
			if (!tmp)
				tmp = (*heap_a);
			rotate(heap_a);
			printf("ra\n");
		}
	}
	if (!(((*heap_a)->content >> cpt) & 1))
	{
		push(heap_a, heap_b);
		printf("pb\n");
	}
	else
	{
		rotate(heap_a);
		printf("ra\n");
	}
}

void	swap_one_toa(t_list **heap_a, t_list **heap_b, int cpt)
{	
	t_list	*tmp;

	if (!*heap_b)
		return ;
	tmp = NULL;
	while ((*heap_b)->next && tmp != (*heap_b)->next)
	{
		if ((((*heap_b)->content >> cpt) & 1))
		{
			push(heap_b, heap_a);
			printf("pa\n");
		}
		else
		{
			if (!tmp)
				tmp = (*heap_b);
			rotate(heap_b);
			printf("rb\n");
		}
	}
	if ((((*heap_b)->content >> cpt) & 1))
	{
		push(heap_b, heap_a);
		printf("pa\n");
	}
	else
	{
		rotate(heap_b);
		printf("rb\n");
	}
}

int	bit_max(t_list *heap)
{
	int	max;
	int	cpt;
	int	rd;

	max = 0;
	while (heap)
	{
		if (heap->content > max)
			max = heap->content;
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

void	pseudo_radix(t_list **heap_a, t_list **heap_b)
{
	int		cpt;
	t_list	*tmp;
	int		size;

	size = bit_max(*heap_a);
	//printf("%d\n", size);
	cpt = 0;
	while (cpt < size)
	{
		if (is_zero(*heap_a, cpt))
			swap_zero_tob(heap_a, heap_b, cpt);
		cpt++;
		if (is_one(*heap_b, cpt))
			swap_one_toa(heap_a, heap_b, cpt);
	}
	while (*heap_b)
	{
		printf("pa\n");
		push(heap_b, heap_a);
	}
}

int	main(int ac, char *av[])
{
	t_list	*heap_a;
	t_list	*tmp;
	t_list	*heap_b;

	if (ac < 2)
		return (EXIT_SUCCESS);
	heap_a = NULL;
	heap_a = create_list(ac, av, NULL);
	if (heap_a == NULL)
	{
		printf("error");
		return (EXIT_FAILURE);
	}
	heap_b = NULL;
	pseudo_radix(&heap_a, &heap_b);
	//print_tlist(heap_a);
	/*ft_lstadd_back(&heap_a, 5);
	ft_lstadd_back(&heap_a, 2);
	ft_lstadd_back(&heap_a, 4);
	ft_lstadd_back(&heap_a, 3);
	ft_lstadd_back(&heap_a, 6);
	ft_lstadd_back(&heap_a, 7);
	ft_lstadd_back(&heap_a, 210);
	ft_lstadd_back(&heap_a, 25);
	ft_lstadd_back(&heap_a, 35);
	ft_lstadd_back(&heap_a, 36);
	ft_lstadd_back(&heap_a, 83);
	ft_lstadd_back(&heap_a, 13);
	ft_lstadd_back(&heap_a, 342);
	ft_lstadd_back(&heap_a, 388);
	ft_lstadd_back(&heap_a, 103);
	ft_lstadd_back(&heap_a, 523);
	ft_lstadd_back(&heap_a, 338);
	ft_lstadd_back(&heap_a, 31);
	ft_lstadd_back(&heap_a, 23);
	ft_lstadd_back(&heap_a, 353);
	ft_lstadd_back(&heap_a, 348);
	ft_lstadd_back(&heap_a, 321);
	ft_lstadd_back(&heap_a, 302);
	ft_lstadd_back(&heap_a, 363);
	ft_lstadd_back(&heap_a, 183);
	ft_lstadd_back(&heap_a, 983);
	ft_lstadd_back(&heap_a, 743);
	ft_lstadd_back(&heap_a, 203);
	ft_lstadd_back(&heap_a, 583);
	ft_lstadd_back(&heap_a, 35);
	ft_lstadd_back(&heap_a, 83);
	tmp = heap_a;
	heap_b = NULL;
	while (heap_a)
	{
		printf("heap %d\n", heap_a->content);
		heap_a = heap_a->next;
	}
	heap_a = tmp;
	pseudo_radix(&heap_a, &heap_b);
	//swap(&heap_a);
	//push(&heap_a, &heap_b);
	//push(&heap_a, &heap_b);
	//rotate(&heap_a);
	//push(&heap_a, &heap_b);
	//rev_rotate(&heap_a);
	printf("\n-------------\n\n");
	while (heap_a)
	{
		printf("heap a %d\n", heap_a->content);
		heap_a = heap_a->next;
	}
	ft_lstclear(&heap_a, &free);
	
	//printf("%d\n", (heap_a->content));
	printf("%d\n", ((heap_a->next->content >> 0) & 1));
	printf("%d\n", ((heap_a->next->content >> 1) & 1));
	printf("%d\n", ((heap_a->next->content >> 2) & 1));
	printf("%d\n", ((heap_a->next->content >> 3) & 1));*/
}
