/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:22:45 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 15:24:55 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

t_list	*lst_dup(t_list *lst)
{
	t_list	*d;

	d = NULL;
	while (lst)
	{
		ft_lstadd_back(&d, lst->content);
		lst = lst->next;
	}
	return (d);
}

int	has_alpha(char *str)
{
	int	cpt;

	cpt = -1;
	while (str[++cpt])
	{
		if ((str[cpt] < '0' || str[cpt] > '9')
			&& str[cpt] != ' ' && str[cpt] != '-')
			return (1);
	}
	return (0);
}

int	is_in(t_list *lst, char *str)
{
	while (lst)
	{
		if (lst->content == ft_atoi(str))
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*min(t_list **lst)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *lst;
	min = tmp;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*update(t_list *s, t_list *t)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = t;
	while (tmp2)
	{
		tmp = s;
		while (tmp)
		{
			if (tmp->content == tmp2->content)
			{
				tmp2->index = tmp->index;
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (t);
}
