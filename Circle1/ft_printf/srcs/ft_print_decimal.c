/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:54:10 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 16:34:33 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strsize(long long n)
{
	int			size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n = -n;
	}
	while (n > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static char	*ft_setarr(char *arr, long long n, int size)
{
	arr[size--] = '\0';
	if (n < 0)
	{
		arr[0] = '-';
		n = -n;
	}
	if (n == 0)
	{
		arr[0] = '0';
		return (arr);
	}
	while (n > 0)
	{
		arr[size--] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}

static char	*ft_itoa(long long n)
{
	int			size;
	char		*arr;

	size = ft_strsize(n);
	arr = (char *)malloc(sizeof(char) * (size + 1));
	if (!arr)
		return (NULL);
	arr = ft_setarr(arr, n, size);
	return (arr);
}

int	ft_print_decimal(long long n, int flag)
{
	char	*itoa_n;

	if (flag == U_INT)
		n = (unsigned int)n;
	itoa_n = ft_itoa(n);
	return (write(1, itoa_n, ft_strlen(itoa_n)));
}
