/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:10:18 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/30 10:05:08 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (*lst == 0)
		return ;
	else
	{
		temp = *lst;
		while ((*lst)->next != 0)
		{
			del((*lst)->value);
			temp = (*lst)->next;
			free((*lst));
			(*lst) = temp;
		}
		del((*lst)->value);
		free(*lst);
	}
	*lst = 0;
}
