/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_dispatcher.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 21:14:43 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/02 18:34:07 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion_dispatcher(const char char_conv, t_arg *curr_arg)
{
	if (char_conv == 'c')
		return (ft_print_char('c', 0, curr_arg));
	else if (char_conv == 's')
		return (ft_print_str(curr_arg));
	else if (char_conv == 'p')
		return (ft_print_pointer(curr_arg));
	else if (char_conv == 'd')
		return (ft_print_decimal(curr_arg));
	else if (char_conv == 'i')
		return (ft_print_decimal(curr_arg));
	else if (char_conv == 'u')
		return (ft_print_unsigned(10, 0, curr_arg));
	else if (char_conv == 'x')
		return (ft_print_unsigned(16, 0, curr_arg));
	else if (char_conv == 'X')
		return (ft_print_unsigned(16, 1, curr_arg));
	else
		return (ft_print_char('%', 1, curr_arg));
}
