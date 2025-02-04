/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:19:24 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/20 16:53:00 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
		size++;
	}
	return (size);
}
