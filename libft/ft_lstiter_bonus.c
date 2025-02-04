/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:07:30 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/30 10:05:08 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (lst == 0)
		return ;
	temp = lst;
	while (temp->next != 0)
	{
		f(temp->value);
		temp = temp->next;
	}
	f(temp->value);
}
