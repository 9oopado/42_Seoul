/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:43:30 by jikoo             #+#    #+#             */
/*   Updated: 2022/08/24 17:36:54 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define INT 0
# define U_INT 1

int		ft_printf(const char *format, ...);
int		ft_do_printf(va_list ap, const char *format);
int		ft_parse(va_list ap, char type);
int		ft_strlen(char *str);
char	*ft_itoa(long long n);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_decimal(long long n, int flag);
int		ft_print_hexadecimal(int n);

#endif