/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:06:04 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 22:27:50 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

void	print_tlist(t_list *heap)
{
	ft_printf("\n--- START ---\n");
	while (heap)
	{
		ft_printf("%d - %d | ", heap->content, heap->index);
		heap = heap->next;
	}
}

int	main(int ac, char *av[])
{
	t_list	*heap_a;
	t_list	*heap_b;

	if (ac < 2)
		return (EXIT_SUCCESS);
	heap_a = NULL;
	heap_a = create_list(ac, av, NULL);
	if (heap_a == NULL)
	{
		ft_printf("error");
		return (EXIT_FAILURE);
	}
	heap_b = NULL;
	if (ft_lstsize(heap_a) == 2)
	{
		if (heap_a->index > heap_a->next->index)
			ft_printf("sa\n");
	}
	else if (ft_lstsize(heap_a) == 3)
		algo_trois(&heap_a);
	else if (ft_lstsize(heap_a) < 6)
		algo_six(&heap_a, &heap_b);
	else
		pseudo_radix(&heap_a, &heap_b);
}
