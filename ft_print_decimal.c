/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybichri <ybichri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 22:58:24 by ybichri           #+#    #+#             */
/*   Updated: 2020/03/03 01:45:53 by ybichri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_decimal(int val, t_arg *curr_arg)
{
	char	*str;
	size_t	val_len;

	if (!val && !curr_arg->precision && curr_arg->point)
		str = ft_strdup("");
	else
	{
		str = ft_itoa(val);
		val_len = ft_strlen(str) - (val < 0);
		if (val_len < (size_t)curr_arg->precision)
			str = ft_strinsert(str, (val < 0),
				ft_strgen('0', curr_arg->precision - val_len));
	}
	if ((val_len = ft_strlen(str)) < (size_t)curr_arg->min_width)
	{
		if (curr_arg->point)
			curr_arg->fill_char = ' ';
		if (curr_arg->just)
			str = ft_strjoin_free(str,
				ft_strgen(' ', curr_arg->min_width - val_len));
		else
			str = ft_strinsert(str, (val < 0) && (curr_arg->fill_char == '0'),
			ft_strgen(curr_arg->fill_char, curr_arg->min_width - val_len));
	}
	return (str);
}

int			ft_print_decimal(t_arg *curr_arg)
{
	char	*out;
	int		val;
	int		len;

	val = va_arg(g_params, int);
	out = parse_decimal(val, curr_arg);
	ft_putstr_fd(out, 1);
	len = (int)ft_strlen(out);
	free(out);
	return (len);
}
