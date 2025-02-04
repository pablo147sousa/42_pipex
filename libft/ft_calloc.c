/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:22:01 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/23 12:42:27 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb != 0 && (size > (size_t)(-1) / nmemb))
		return (0);
	array = (void *) malloc(nmemb * size);
	if (array == 0)
		return (0);
	ft_bzero (array, size * nmemb);
	return (array);
}
