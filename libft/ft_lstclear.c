/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:23:39 by dgoubin           #+#    #+#             */
/*   Updated: 2022/12/03 21:16:22 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
t_list	*ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst || del)
	{
		if (*lst)
		{
			while ((*lst)->next)
			{
				tmp = (*lst)->next;
				ft_lstdelone(*lst, del);
				*lst = tmp;
			}
		}
	}
	return (NULL);
}
