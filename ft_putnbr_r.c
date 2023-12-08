/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 21:56:30 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/02 13:19:22 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_r(int n)
{
	long	number;
	int		count;

	count = 0;
	number = n;
	if (number < 0)
	{
		write (1, "-", 1);
		number *= -1;
		count++;
	}
	if (number == 0)
	{
		write (1, "0", 1);
		count++;
	}
	if (number > 0)
	{
		if (number > 9)
		{
			count += ft_putnbr_r(number / 10);
		}
		count += ft_putchar_r(((number % 10) + 48));
	}
	return (count);
}
