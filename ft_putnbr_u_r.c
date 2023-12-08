/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_u_r.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lightw <lightw@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 17:31:44 by lightw        #+#    #+#                 */
/*   Updated: 2023/11/02 13:14:54 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u_r(int n)
{
	unsigned int	number;
	int				count;

	count = 0;
	number = n;
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
