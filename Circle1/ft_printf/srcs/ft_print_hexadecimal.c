/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:42:40 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 17:36:52 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_toupper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        i++;
    }
    return (str);
}

static char *ft_dec_to_hex(int n)
{
    // 10 -> 16 진수 변환
    return ("");
}

int ft_print_hexadecimal(int n)
{
    char    *hex_n;

    hex_n = ft_dec_to_hex(n);
    // 플래그 줘서 toupper 처리
    return (write(1, hex_n, ft_strlen(hex_n)));
}