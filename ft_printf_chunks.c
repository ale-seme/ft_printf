/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_chunks.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/02 23:02:48 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/03 14:15:46 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_first_chunk(const char *str, va_list args, int *i)
{
	int		ret;
	char	c;

	ret = 0;
	if (str[*i + 1] == 'c')
	{
		c = (char)va_arg(args, int);
		ret += ft_putchar_r(c);
		(*i)++;
	}
	else if (str[*i + 1] == 's')
	{
		ret += ft_putstring_r(va_arg(args, char *));
		(*i)++;
	}
	else if (str[*i + 1] == 'p')
	{
		ret += ft_putptr_r(va_arg(args, void *));
		(*i)++;
	}
	return (ret);
}

int	ft_second_chunk(const char *str, va_list args, int *i)
{
	int	ret;

	ret = 0;
	if (str[*i + 1] == 'i' || str[*i + 1] == 'd')
	{
		ret += ft_putnbr_r(va_arg(args, int));
		(*i)++;
	}
	return (ret);
}

int	ft_third_chunk(const char *str, va_list args, int *i)
{
	int	ret;

	ret = 0;
	if (str[*i + 1] == 'x')
	{
		ret += ft_puthex_x(va_arg(args, int));
		(*i)++;
	}
	else if (str[*i + 1] == 'X')
	{
		ret += ft_puthex_xup(va_arg(args, int));
		(*i)++;
	}
	return (ret);
}

int	ft_fourth_chunk(const char *str, va_list args, int *i)
{
	int	ret;

	ret = 0;
	if (str[*i + 1] == 'u')
	{
		ret += ft_putnbr_u_r(va_arg(args, unsigned int));
		(*i)++;
	}
	else if (str[*i + 1] == '%')
	{
		ret += ft_putchar_r('%');
		(*i)++;
	}
	return (ret);
}
