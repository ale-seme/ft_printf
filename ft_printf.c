/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: asemerar <asemerar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/28 14:00:34 by asemerar      #+#    #+#                 */
/*   Updated: 2023/12/08 10:43:15 by asemerar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>

// You have to implement the following conversions:
// • %c Prints a single character.
// • %s Prints a string (as defined by the common C convention).
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %i Prints an integer in base 10.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/fprintf.html
//http://www.facweb.iitkgp.ac.in/~bibhas/Hex_Memory_Addressing.pdf

static int	ft_split_printf(const char *str, va_list args)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p')
				ret += ft_first_chunk(str, args, &i);
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ret += ft_second_chunk(str, args, &i);
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
				ret += ft_third_chunk(str, args, &i);
			else if (str[i + 1] == 'u' || str [i + 1] == '%')
				ret += ft_fourth_chunk(str, args, &i);
			else 
				return -1;
		}
		else
			ret += ft_putchar_r(str[i]);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		ret;

	if (!str)
	{
		return (0);
	}
	va_start(args, str);
	ret = 0;
	ret += ft_split_printf(str, args);
	va_end(args);
	if (ret < 0)
	{
		return -1;
	}
	return (ret);
}

// int main() 
// {
// 	// char c = 'A';
// 	// char *str = "Hello, World!";
// 	// int num = 54321;
// 	// int negative_num = -6789;
// 	// unsigned int u_num = 12345;
// 	// void *ptr = (void *)0x7FFF12345678;
// 	// printf(" printf test cases:\n");
// 	// printf("1. Character: %c\n", c);
// 	// printf("2. String: %s\n", str);
// 	// printf("3. Pointer: %p\n", ptr);
// 	// printf("3.1. Pointer: %p\n", (void *) 0);
// 	// printf("4. Decimal (d): %d\n", num);
// 	// printf("4.1. Decimal (d) largest min: %d\n", INT_MIN);
// 	// printf("5. Decimal (i): %i\n", num);
// 	// printf("5.1. Largest positive Decimal (i): %i\n", INT_MAX);
// 	// printf("6. Decimal (d, negative): %d\n", negative_num);
// 	// printf("7. Unsigned Decimal (u): %u\n", u_num);
// 	// printf("8. Hexadecimal (lowercase neg, x): %x\n", -122323);
// 	// printf("9. Hexadecimal (uppercase neg, X): %X\n", -122323);
// 	// printf("10. Hexadecimal (lowercase pos, x): %x\n",  283932);
// 	// printf("11. Hexadecimal (uppercase pos, X): %X\n",  283932);
// 	// printf("12. Percent Sign: %%\n");
// 	// printf("\nmy ft_printf test cases:\n");
// 	// ft_printf("1. Character: %c\n", c);
// 	// ft_printf("2. String: %s\n", str);
// 	// ft_printf("3. Pointer: %p\n", ptr);
// 	// ft_printf("3.1. Pointer: %p\n", (void *) 0);
// 	// ft_printf("4. Decimal (d): %d\n", num);
// 	// ft_printf("4.1. Decimal (d) largest min: %d\n", INT_MIN);
// 	// ft_printf("5. Decimal (i): %i\n", num);
// 	// ft_printf("5.1. Largest positive Decimal (i): %i\n", INT_MAX);
// 	// ft_printf("6. Decimal (d, negative): %d\n", negative_num);
// 	// ft_printf("7. Unsigned Decimal (u): %u\n", u_num);
// 	// ft_printf("8. Hexadecimal (lowercase neg, x): %x\n", -122323);
// 	// ft_printf("9. Hexadecimal (uppercase ned, X): %X\n", -122323);
// 	// ft_printf("10. Hexadecimal (lowercase pos, x): %x\n",  283932);
// 	// ft_printf("11. Hexadecimal (uppercase pos, X): %X\n",  283932);
// 	//ft_printf("12. Percent Sign: %%\n");
// 	//ft_printf(NULL);
// 	//printf(NULL);
// 	//return 0;
// }