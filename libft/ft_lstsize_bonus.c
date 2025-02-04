/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:08:25 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/23 12:44:01 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst);

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (lst == 0)
		return (0);
	size = 1;
	while (lst->next != 0)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
