/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstring_r.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/31 21:54:57 by asemerar      #+#    #+#                 */
/*   Updated: 2023/11/02 16:53:14 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstring_r(char *str)
{
	int	i;
	int	len;

	if (str == NULL)
	{
		str = "(null)";
	}
	len = 0;
	i = 0;
	while (str[i])
	{
		i++;
		len++;
	}
	write (1, str, len);
	return (len);
}
