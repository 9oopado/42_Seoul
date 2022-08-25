/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:10:08 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/25 21:35:07 by jikoo            ###   ########.fr       */
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

int	ft_print_dec(long long n)
{
	char	*dec;

	dec = ft_itoa_base(n, "0123456789");
	return (ft_print_str(dec));
}

int	ft_print_hex(long long n, int flag)
{
	char	*hex;

	hex = ft_itoa_base(n, "0123456789abcdef");
	if (flag)
		hex = ft_toupper(hex);
	return (ft_print_str(hex));
}
