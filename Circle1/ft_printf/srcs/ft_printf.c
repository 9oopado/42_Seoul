/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:42:28 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 16:39:55 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list ap, char type)
{
	if (type == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (type == 's')
		return (ft_print_string(va_arg(ap, char *)));
	// else if (type == 'p')
	// 	return ();
	else if (type == 'd' || type == 'i')
		return (ft_print_decimal(va_arg(ap, int), INT));
	else if (type == 'u')
		return (ft_print_decimal(va_arg(ap, unsigned int), U_INT));
	else if (type == 'x')
		return (ft_print_hexadecimal(va_arg(ap, int)));
	// else if (type == 'X')
	// 	return ();
	else if (type == '%')
		return (ft_print_char('%'));
	else
		return (-1);
}

int	ft_do_printf(va_list ap, const char *format)
{
	int	count;
	int	check;

	count = 0;
	while (*format)
	{
		if (*format != '%')
			check = write(1, format, 1);
		else if (*(++format) != '\0')
			check = ft_parse(ap, *format);
		if (check < 0)
			return (-1);
		count += check;
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = ft_do_printf(ap, format);
	va_end(ap);
	return (cnt);
}

#include <stdio.h>
int	main(void)
{
	printf("s:%s  d:%d  i:%i  %%  c:%c  u:%u  x:%x  X:%X\n", "Hello", 4, 2, '!', -2147483647, 10, 10);
	ft_printf("s:%s  d:%d  i:%i  %%  c:%c  u:%u\n", "Hello", 4, 2, '!', -2147483647);
}
