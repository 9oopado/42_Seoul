/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:42:40 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 18:23:59 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_toupper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

static int	ft_converted_len(int n)
{
	int			len;
	long long	tmp;

	len = 0;
	tmp = (long long)n;
	if (tmp <= 0)
	{
		len++;
		tmp = -tmp;
	}
	while (tmp < 0)
	{
		len++;
	tmp /= 16;
	}
	return (len);
}

static char	*ft_dec_to_hex(int n)
{
	int			len;
	char		*arr;
	long long	nbr;

	len = ft_converted_len(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	nbr = (long long)n;
	arr[len--] = '\0';
	if (nbr < 0)
	{
		arr[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	while (nbr > 0)
	{
		arr[len--] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
	}
	return (arr);
}

int	ft_print_hexadecimal(int n, int flag)
{
	char	*hex_n;

	hex_n = ft_dec_to_hex(n);
	if (!hex_n)
		return (-1);
	if (flag)
		hex_n = ft_toupper(hex_n);
	return (write(1, hex_n, ft_strlen(hex_n)));
}
