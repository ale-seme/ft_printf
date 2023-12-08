/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 21:39:06 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/03 16:08:03 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
// # include <stdio.h>
// # include <limits.h>

int	ft_printf(const char *str, ...);
int	ft_putchar_r(char c);
int	ft_putnbr_r(int n);
int	ft_putnbr_u_r(int n);
int	ft_putstring_r(char *str);
int	ft_puthex_x(int num);
int	ft_puthex_xup(int num);
int	ft_putptr_r(void *ptr);
int	ft_first_chunk(const char *str, va_list args, int *i);
int	ft_second_chunk(const char *str, va_list args, int *i);
int	ft_third_chunk(const char *str, va_list args, int *i);
int	ft_fourth_chunk(const char *str, va_list args, int *i);
#endif