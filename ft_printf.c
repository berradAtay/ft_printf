/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 08:42:19 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 17:24:04 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int printed;

	printed = 0;
	g_pos = 0;
	va_start(g_params, format);
	while (format[g_pos])
	{
		if (format[g_pos] == '%')
			printed += ft_arg_handler(format);
		else
		{
			ft_putchar_fd(format[g_pos], 1);
			printed++;
			g_pos++;
		}
	}
	va_end(g_params);
	return (printed);
}
