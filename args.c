/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:25:46 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/03 20:39:46 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_2_merde.h"

static int	has_alpha(char *str)
{
	int	cpt;

	cpt = -1;
	while (str[++cpt])
	{
		if ((str[cpt] < '0' || str[cpt] > '9') && str[cpt] != ' ')
			return (1);
	}
	return (0);
}

static int	is_in(t_list *lst, char *str)
{
	while (lst)
	{
		if (lst->content == ft_atoi(str))
			return (1);
		lst = lst->next;
	}
	return (0);
}

static t_list	*multiples_args(char *str, t_list **lst)
{
	char	**tab;
	int		cpt;

	cpt = 0;
	tab = ft_split(str, ' ');
	while (tab[cpt])
	{
		if (!lst || !is_in(*lst, tab[cpt]))
			ft_lstadd_back(lst, ft_atoi(tab[cpt]));
		else
			return (ft_lstclear(lst, &free));
		free(tab[cpt++]);
	}
	free(tab);
	return (*lst);
}

t_list	*create_list(int ac, char **av, t_list *lst)
{
	int		cpt;

	cpt = 0;
	while (++cpt < ac)
	{
		if (!has_alpha(av[cpt]))
		{
			if (ft_strrchr(av[cpt], ' '))
			{
				if (!multiples_args(av[cpt], &lst))
					return (NULL);
			}
			else
			{
				if (!is_in(lst, av[cpt]))
					ft_lstadd_back(&lst, ft_atoi(av[cpt]));
				else
					return (ft_lstclear(&lst, &free));
			}
		}
		else
			return (NULL);
	}
	return (lst);
}
