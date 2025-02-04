/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:47:26 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/20 16:53:00 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_printptr(unsigned long ptr);
static void	ft_printhex(unsigned long nbr, char type);

static void	ft_printhex(unsigned long nbr, char type)
{
	char	*base;

	if (type == 'x')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	if (nbr < 16)
		ft_putchar(base[nbr]);
	else if (nbr >= 16)
	{
		ft_printhex((nbr / 16), type);
		ft_printhex((nbr % 16), type);
	}
}

int	ft_printptr(unsigned long ptr)
{
	int				size;
	unsigned long	temp;

	if (ptr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	size = 0;
	temp = ptr;
	while (ptr > 0)
	{
		ptr /= 16;
		size++;
	}
	write(1, "0x", 2);
	size += 2;
	ft_printhex(temp, 'x');
	return (size);
}
