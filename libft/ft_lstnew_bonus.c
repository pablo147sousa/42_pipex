/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:06:28 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/30 10:05:08 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *value);

t_list	*ft_lstnew(void *value)
{
	t_list	*lst;

	lst = (t_list *) malloc(sizeof(t_list));
	if (lst == 0)
		return (0);
	lst->value = value;
	lst->next = 0;
	return (lst);
}
