/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:14:12 by pmoreira          #+#    #+#             */
/*   Updated: 2024/10/31 14:05:18 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	sz;
	char	*str;

	i = 0;
	j = 0;
	sz = ft_strlen(little);
	str = (char *) big;
	if (sz == 0)
		return (str);
	while (str[i] != 0 && i < len)
	{
		j = 0;
		while (str[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
