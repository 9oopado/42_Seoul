/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:48:15 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/25 21:20:36 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strcat(char *dst, char *src)
{
	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

static char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*join_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!join_str)
		return (NULL);
	join_str[0] = '\0';
	ft_strcat(join_str, s1);
	ft_strcat(join_str, s2);
	return (join_str);
}

int	ft_print_ptr(unsigned long long n)
{
	char	*ptr_n;

	ptr_n = ft_itoa_base(n, "0123456789abcdef");
	ptr_n = ft_strjoin("0x", ptr_n);
	return (ft_print_str(ptr_n));
}
