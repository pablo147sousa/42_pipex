/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:19:47 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/23 12:42:15 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
}
