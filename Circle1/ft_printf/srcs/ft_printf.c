/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:42:28 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 10:40:47 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_print_char(int c)
{
    return (write(1, &c, 1));
}

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}

int ft_print_string(char *str)
{
    if (!str)
        str = "(null)";
    return (write(1, str, ft_strlen(str)));
}

int ft_parse(va_list ap, char type)
{
    if (type == 'c')
        return (ft_print_char(va_arg(ap, int)));
    else if (type == 's')
        return (ft_print_string(va_arg(ap, char *)));
    // else if (type == 'p')
    //     return ();
    // else if (type == 'd')
    //     return ();
    // else if (type == 'i')
    //     return ();
    // else if (type == 'u')
    //     return ();
    // else if (type == 'x')
    //     return ();
    // else if (type == 'X')
    //     return ();
    // else if (type == '%')
    //     return ();
    else
        return (-1);
}

int ft_do_printf(va_list ap, const char *format)
{
    int count;
    int check;

    count = 0;
    while (*format)
    {
        if (*format != '%')
            check = write(1, format, 1);
        else if (*(++format) != '\0')
            check = ft_parse(ap, *format);
        // if (*format == '%')
        //     check = ft_parse(ap, *(++format));
        // else
        //     check = write(1, format, 1);
        if (check < 0)
            return (-1);
        count += check;
        format++;
    }
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     cnt;

    va_start(ap, format);
    cnt = ft_do_printf(ap, format);
    va_end(ap);
    return (cnt);
}

int main()
{
    ft_printf("hello %s", "world");
}