/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr_r.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 13:27:19 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/02 17:49:14 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_r1(unsigned long ptr_address)
{
	unsigned long	ptr_digit;
	char			hex_digit;
	int				ret;

	ret = 0;
	hex_digit = 0;
	if (ptr_address > 0)
	{
		if (ptr_address > 15)
			ret += ft_putptr_r1(ptr_address / 16);
		ptr_digit = ptr_address % 16;
		if (ptr_digit < 10)
		{
			hex_digit = (char)(ptr_digit + '0');
		}
		else
		{
			hex_digit = (char)(ptr_digit - 10 + 'a');
		}
	}
	ret += ft_putchar_r(hex_digit);
	return (ret);
}

int	ft_putptr_r(void *ptr)
{
	int				ret;
	unsigned long	ptr_address;

	ret = 0;
	ptr_address = (unsigned long)ptr;
	if (ptr_address == 0)
	{
		ret += ft_putstring_r("(nil)");
		return (ret);
	}
	else
	{
		ret += ft_putchar_r('0');
		ret += ft_putchar_r('x');
	}
	ret += ft_putptr_r1(ptr_address);
	return (ret);
}
