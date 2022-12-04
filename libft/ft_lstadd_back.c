/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:56:52 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/04 12:54:44 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, int content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
	}
}
