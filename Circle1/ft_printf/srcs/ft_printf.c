/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:24:48 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/25 21:35:05 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list *ap, char type)
{
	if (type == 'c')
		return (ft_print_chr(va_arg(*ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(*ap, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (ft_print_dec(va_arg(*ap, int)));
	else if (type == 'u')
		return (ft_print_dec(va_arg(*ap, unsigned int)));
	else if (type == 'x')
		return (ft_print_hex(va_arg(*ap, unsigned int), 0));
	else if (type == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), 1));
	else if (type == '%')
		return (ft_print_chr('%'));
	else
		return (-1);
}

int	ft_run(va_list *ap, const char *format)
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
	va_list ap;
	int		cnt;

	va_start(ap, format);
	cnt = ft_run(&ap, format);
	va_end(ap);
	return (cnt);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("---- printf ----\n");
// 	printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n", 
// 		'a', "Hi i'm jikoo", (void *)0, 42, 42, -42, 42, 42);
// 	ft_printf("---- ft_printf ----\n");
// 	ft_printf("%%c : %c\n%%s : %s\n%%p : %p\n%%d : %d\n%%i : %i\n%%u : %u\n%%x : %x\n%%X : %X\n", 
// 		'a', "Hi i'm jikoo", (void *)0, 42, 42, -42, 42, 42);
// }