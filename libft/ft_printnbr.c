/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:55:13 by pmoreira          #+#    #+#             */
/*   Updated: 2024/12/20 16:53:00 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int			ft_printnbr(int n);
static void	ft_putnbr(int n);

static void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar((n + '0'));
	}
	else if (n > 9)
	{
		ft_putnbr((n / 10));
		ft_putchar(((n % 10) + '0'));
	}
	else
	{
		write(1, "-", 1);
		ft_putnbr((n * (-1)));
	}
}

int	ft_printnbr(int num)
{
	int	size;
	int	temp;

	size = 0;
	temp = num;
	if (num < 0)
		size++;
	while (num != 0)
	{
		size++;
		num /= 10;
	}
	ft_putnbr(temp);
	if (temp == 0 || temp < INT_MIN || temp > INT_MAX)
		size = 1;
	return (size);
}
