/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:40:46 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 17:36:53 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

char	*ft_itoa(long long n)
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
