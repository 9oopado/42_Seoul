/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:54:10 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 17:36:51 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_decimal(long long n, int flag)
{
	char	*itoa_n;

	if (flag == U_INT)
		n = (unsigned int)n;
	itoa_n = ft_itoa(n);
	return (write(1, itoa_n, ft_strlen(itoa_n)));
}
