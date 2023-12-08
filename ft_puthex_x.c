/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_x.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 20:49:29 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/02 12:49:35 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_x(int num);

static int	ft_puthex_x_help(unsigned int n, int ret)
{
	char	hex_digit;
	int		num_digit;

	hex_digit = 0;
	if (n > 0)
	{
		if (n > 15)
			ret += ft_puthex_x(n / 16);
		num_digit = n % 16;
		if (num_digit < 10)
		{
			hex_digit = (char)(num_digit + '0');
		}
		else
		{
			hex_digit = (char)(num_digit - 10 + 'a');
		}
		ret += ft_putchar_r(hex_digit);
	}
	return (ret);
}

int	ft_puthex_x(int num)
{
	int				ret;
	unsigned int	number;

	ret = 0;
	number = num;
	if (number == 0)
	{
		ret += ft_putchar_r('0');
	}
	else
	{
		ret += ft_puthex_x_help(number, ret);
	}
	return (ret);
}
